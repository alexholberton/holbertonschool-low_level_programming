#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{
    unsigned long checksum;
	clock_t start, end total, start step, end step;
    double d_total, d_build, d_process, d_reduce;

    /* Start global timer */
    start_total = clock();

    /* Phase 1: BUILD_DATA instrumentation */
    start_step = clock();
    build_dataset();
    end_step = clock();
    d_build = (double)(end_step - start_step) / CLOCKS_PER_SEC;

    /* Phase 2: PROCESS instrumentation */
    start_step = clock();
    process_dataset();
    end_step = clock();
    d_process = (double)(end_step - start_step) / CLOCKS_PER_SEC;

    /* Phase 3: REDUCE (Checksum) instrumentation */
    start_step = clock();
    checksum = reduce_checksum();
    end_step = clock();
    d_reduce = (double)(end_step - start_step) / CLOCKS_PER_SEC;

    /* Stop global timer */
    end_total = clock();
    d_total = (double)(end_total - start_total) / CLOCKS_PER_SEC;

    /* Security check to prevent compiler optimization on unused variables */
    if (checksum == 0ul)
        printf("impossible\n");

    /* Final Output (Required format) */
    printf("TOTAL seconds: %.6f\n", d_total);
    printf("BUILD_DATA seconds: %.6f\n", d_build);
    printf("PROCESS seconds: %.6f\n", d_process);
    printf("REDUCE seconds: %.6f\n", d_reduce);

    return (0);
}
