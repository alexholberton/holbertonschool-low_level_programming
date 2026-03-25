# Memory Maps Analysis

## Programs Analyzed
- `programs/recursive_sum.c`
- `programs/heap_pointers.c`

---

## Program 1: recursive_sum.c

### Source Code
```c
#include <stdio.h>

int recursive_sum(int n)
{
    if (n <= 0)
        return 0;
    return n + recursive_sum(n - 1);
}

int main(void)
{
    int result = recursive_sum(3);
    printf("Sum: %d\n", result);
    return 0;
}
```

### Execution Output
```
Sum: 6
```

### Key Execution Points

**Point 1 — main() calls recursive_sum(3)**
```
STACK (grows downward)
+---------------------------+
| main() frame              |
|  result = [uninitialized] |
|  return address           |
+---------------------------+
| recursive_sum(n=3) frame  |
|  n = 3                    |
|  return address           |
+---------------------------+
```

**Point 2 — Full recursion depth reached**
```
STACK
+---------------------------+
| main() frame              |
|  result = [uninitialized] |
+---------------------------+
| recursive_sum(n=3) frame  |
|  n = 3                    |
+---------------------------+
| recursive_sum(n=2) frame  |
|  n = 2                    |
+---------------------------+
| recursive_sum(n=1) frame  |
|  n = 1                    |
+---------------------------+
| recursive_sum(n=0) frame  |
|  n = 0                    |
|  → returns 0              |
+---------------------------+

HEAP: empty
```

**Point 3 — Unwinding (return phase)**
```
recursive_sum(0) returns 0  → frame destroyed
recursive_sum(1) returns 1+0=1 → frame destroyed
recursive_sum(2) returns 2+1=3 → frame destroyed
recursive_sum(3) returns 3+3=6 → frame destroyed
main(): result = 6
```

### Variable Lifetimes
- `n` in each frame: alive from function entry until return
- `result` in main: alive from declaration until end of main
- All variables are on the **stack**: automatically freed on return

---

## Program 2: heap_pointers.c

### Source Code
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = malloc(sizeof(int));
    *a = 42;

    int *b = a;
    *b = 100;

    printf("a = %d, b = %d\n", *a, *b);

    free(a);
    a = NULL;

    return 0;
}
```

### Execution Output
```
a = 100, b = 100
```

### Key Execution Points

**Point 1 — After malloc and *a = 42**
```
STACK                        HEAP
+------------------+         +------------------+
| main() frame     |         | addr 0x12345678  |
|  a = 0x12345678 -+-------> |  value: 42       |
|  b = [undef]     |         +------------------+
+------------------+
```

**Point 2 — After b = a (aliasing)**
```
STACK                        HEAP
+------------------+         +------------------+
| main() frame     |         | addr 0x12345678  |
|  a = 0x12345678 -+----+--> |  value: 42       |
|  b = 0x12345678 -+----+    +------------------+
+------------------+

Both a and b point to the SAME heap address.
```

**Point 3 — After *b = 100**
```
STACK                        HEAP
+------------------+         +------------------+
| main() frame     |         | addr 0x12345678  |
|  a = 0x12345678 -+----+--> |  value: 100      |
|  b = 0x12345678 -+----+    +------------------+
+------------------+

Writing through b also changes *a because they alias the same address.
This is why the output is: a = 100, b = 100
```

**Point 4 — After free(a) and a = NULL**
```
STACK                        HEAP
+------------------+         +------------------+
| main() frame     |         | addr 0x12345678  |
|  a = NULL        |         |  FREED (invalid) |
|  b = 0x12345678 -+-------> |  ??? (undefined) |
+------------------+         +------------------+

DANGER: b is now a DANGLING POINTER.
b still holds the old address but the memory has been freed.
Dereferencing b here is undefined behavior.
```

### Variable Lifetimes
- `a`: stack variable, alive from declaration to end of main. Set to NULL after free.
- `b`: stack variable, alive from declaration to end of main. Becomes dangling after free(a).
- heap block at `*a`: alive from malloc() call until free(a).

### Pointer Aliasing
- After `b = a`, both pointers hold the same address.
- Modifying `*b` is identical to modifying `*a`.
- Freeing via one pointer invalidates ALL aliases to that block.

---

## AI Error Documentation

### Error Found in Initial AI Explanation

**Context:** Program 2 — heap_pointers.c, Point 4

**What the AI initially stated:**
The AI described `b` after `free(a)` as "a pointer pointing somewhere invalid" without specifying the exact nature of the problem.

**Why this is wrong:**
This description is too vague to be useful. The correct technical description is:
- `b` is a **dangling pointer**: it holds a valid-looking address (0x12345678) but that memory block has been returned to the allocator via `free(a)`.
- The memory at that address may be reused, zeroed, or left unchanged depending on the allocator implementation.
- Dereferencing `b` after `free(a)` is **undefined behavior** per the C standard — it may crash, return garbage, or appear to work correctly.
- Setting `a = NULL` does NOT invalidate `b`. They are independent stack variables that happened to hold the same value.

**Correction:**
A dangling pointer must be described by its address (still the old heap address), its status (memory freed), and the consequence (undefined behavior on dereference). Saying "points somewhere invalid" hides the aliasing problem entirely — the real danger is that `b` was never set to NULL and the programmer may not realize the block was freed.
