# Valgrind Analysis

## Programs Analyzed
- `programs/recursive_sum.c`
- `programs/heap_pointers.c`

## Commands Used
```
valgrind --leak-check=full --track-origins=yes ./recursive_sum
valgrind --leak-check=full --track-origins=yes ./heap_pointers
```

---

## Program 1: recursive_sum

### Valgrind Output Summary
```
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
  total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

### Analysis
No errors detected. All memory is stack-allocated (local variable `n` in each
recursive frame, `result` in main). Stack frames are automatically destroyed
on return. The 1 alloc / 1 free reported by Valgrind corresponds to internal
C runtime initialization (stdio buffer), not to any allocation in our code.

---

## Program 2: heap_pointers

### Valgrind Output Summary
```
==85572== Invalid read of size 4
==85572==    at 0x1091F9: main (heap_pointers.c:18)
==85572==  Address 0x4a76040 is 0 bytes inside a block of size 4 free'd
==85572==    at 0x484988F: free (...)
==85572==    by 0x1091EC: main (heap_pointers.c:14)
==85572==  Block was alloc'd at
==85572==    at 0x4846828: malloc (...)
==85572==    by 0x10919E: main (heap_pointers.c:6)

HEAP SUMMARY:
    in use at exit: 40 bytes in 1 blocks
  total heap usage: 3 allocs, 2 frees, 1,068 bytes allocated

40 bytes in 1 blocks are definitely lost in loss record 1 of 1
   at 0x4846828: malloc (...)
   by 0x10921A: main (heap_pointers.c:21)

ERROR SUMMARY: 2 errors from 2 contexts
```

---

### Error 1 — Invalid read of size 4 (use-after-free)

**Type:** use-after-free

**Location:** `heap_pointers.c` line 18: `printf("b after free = %d\n", *b);`

**Memory object involved:**
The heap block of 4 bytes allocated at line 6 via `malloc(sizeof(int))`.
Its address is `0x4a76040`.

**What happened step by step:**
1. Line 6: `malloc(sizeof(int))` allocates 4 bytes on the heap at `0x4a76040`.
   Both `a` and `b` are assigned this address.
2. Line 14: `free(a)` returns the block at `0x4a76040` to the allocator.
   The block's lifetime ends here.
3. Line 15: `a = NULL` — only `a` is cleared. `b` still holds `0x4a76040`.
4. Line 18: `*b` dereferences `0x4a76040` — a block whose lifetime has ended.
   This is a use-after-free.

**Why Valgrind catches it:**
Valgrind tracks the lifetime of every heap block. After `free(a)`, the block
at `0x4a76040` is marked as freed. Any read or write to that address triggers
an "Invalid read/write" report. The message "Address 0x4a76040 is 0 bytes
inside a block of size 4 free'd" confirms the exact block involved.

**Lifetime violation:**
`b` outlives the heap block it points to. The block was freed at line 14 but
`b` was never set to NULL. Dereferencing `b` after `free(a)` accesses memory
outside its valid lifetime.

**Memory map at time of error:**
```
STACK                        HEAP
+------------------+         +---------------------------+
| main() frame     |         | addr 0x4a76040            |
|  a = NULL        |         |  STATUS: FREED (invalid)  |
|  b = 0x4a76040 --+-------> |  content: undefined       |
|  c = ...         |         +---------------------------+
+------------------+
```

---

### Error 2 — Definitely lost: 40 bytes (memory leak)

**Type:** memory leak — definitely lost

**Location:** `heap_pointers.c` line 21: `int *c = malloc(sizeof(int) * 10);`

**Memory object involved:**
A heap block of 40 bytes (`sizeof(int) * 10 = 4 * 10`) allocated at line 21.

**What happened:**
`c` is allocated but `free(c)` is never called before `main` returns.
At program exit, Valgrind scans all heap blocks still in use. The block
pointed to by `c` has no live pointer to it after `main` returns — it is
"definitely lost" because the allocator cannot reclaim it automatically.

**Why 40 bytes:**
`sizeof(int)` on a 64-bit Linux system is 4 bytes. Allocating 10 integers
gives 4 * 10 = 40 bytes. Valgrind reports exactly this.

**Lifetime violation:**
The heap block allocated at line 21 has no corresponding `free()`. Its
ownership is lost when `main` returns and `c` goes out of scope. This is
a classic ownership leak: the programmer allocated memory but never
transferred or released ownership before the pointer's scope ended.

**Memory map at time of leak:**
```
STACK                        HEAP
+------------------+         +---------------------------+
| main() frame     |         | addr 0x4a76040 (freed)    |
|  c = 0x4a77080 --+-------> +---------------------------+
|  [being destroyed]|        | addr 0x4a77080            |
+------------------+         |  40 bytes — NEVER FREED   |
                              +---------------------------+
```

---

## AI Error Documentation

### Error Found in Initial AI Explanation

**Context:** Error 1 — use-after-free, heap_pointers.c

**What the AI initially stated:**
The AI described the use-after-free as: "Valgrind reports an invalid read
because `b` points to freed memory and the value is now undefined."

**Why this is partially incorrect:**

1. The AI said the value is "now undefined" — this is misleading.
   In this specific execution, `*b` printed `100`, the original value.
   The allocator did not zero or reuse the block between `free(a)` and
   `*b`. The value appeared valid. This is precisely what makes
   use-after-free bugs dangerous: they often appear to work correctly
   and are invisible without a tool like Valgrind.

2. The AI did not explain WHY Valgrind detects it. Valgrind uses shadow
   memory to track the state of every heap byte. When `free(a)` is
   called, Valgrind marks all bytes of that block as "freed/invalid".
   The next read of any byte in that block triggers the error regardless
   of whether the value has changed.

3. The AI omitted the aliasing root cause entirely. The bug exists
   because `b = a` created an alias, and only `a` was nullified after
   `free`. A correct fix requires either setting `b = NULL` after
   `free(a)`, or not using `b` after the free. The AI's explanation
   would not lead a programmer to understand or fix the real problem.

**Correction:**
A use-after-free must be described in terms of the block's lifetime and
all aliases to it. The fact that the read "succeeds" at runtime does not
mean it is safe — it means the allocator has not yet reused the block.
This is undefined behavior: it may crash, return stale data, or corrupt
future allocations depending on allocator state.
