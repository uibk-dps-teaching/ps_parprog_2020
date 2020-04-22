#include <errno.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERROR fprintf(stderr, "%s:%d: error: %s\n", __FILE__, __LINE__, strerror(errno))
#define PERROR_GOTO(label) \
    do { \
        PERROR; \
        goto label; \
    } while (0)

#define INIT_ARRAY(arr, label) \
    do { \
        if (!(arr)) PERROR_GOTO(label); \
        for (long i = 0; i < n; ++i) { \
            (arr)[i] = malloc(sizeof(**(arr)) * n); \
            if (!(arr)[i]) PERROR_GOTO(label); \
        } \
    } while (0)

#define AT(m, x, y, size) m[size*x + y]

#define SEED 151515


int main(int argc, char **argv) {
    // handle input
    if (argc != 2) {
        fprintf(stderr, "Error: usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }
    errno = 0;
    char *str = argv[1];
    char *endptr;
    long n = strtol(str, &endptr, 0);
    if (errno != 0) {
        perror("strtol");
        return EXIT_FAILURE;
    }
    if (endptr == str) {
        fprintf(stderr, "Error: no digits were found!\n");
        return EXIT_FAILURE;
    }
    if (n < 0) {
        fprintf(stderr, "Error: matrix size must not be negative!\n");
        return EXIT_FAILURE;
    }

    // allocate memory
    int status = EXIT_FAILURE;
    int *a = malloc(sizeof(a) * n * n);
    if (!a) PERROR_GOTO(error_a);
    int *b = malloc(sizeof(b) * n * n);
    if (!b) PERROR_GOTO(error_b);
    int *c = malloc(sizeof(c) * n * n);
    if (!c) PERROR_GOTO(error_c);
    status = EXIT_SUCCESS;

#pragma omp parallel default(none) firstprivate(n) shared(a, b, c)
    {
        unsigned int seed = SEED + omp_get_thread_num();
#pragma omp for
        for (long i = 0; i < n; ++i) {
            for (long j = 0; j < n; ++j) {
                AT(a, i, j, n) = rand_r(&seed);
                AT(b, i, j, n) = rand_r(&seed);
                AT(c, i, j, n) = 0;
            }
        }
    }

    double start_time = omp_get_wtime();

    int *b_transposed = malloc(sizeof(b_transposed) * n * n);
    //transposing matrix b
#pragma omp parallel for
    for (long i = 0; i < n; ++i) {
        for (long j = 0; j < n; ++j) {
            AT(b_transposed, i, j, n) = AT(b, j, i, n);
        }
    }

    // matrix multiplication
#pragma omp parallel for default(none) firstprivate(n, a, b_transposed) shared(c)
    for (long i = 0; i < n; ++i) {
        for (long j = 0; j < n; ++j) {
            for (long k = 0; k < n; ++k) {
                AT(c, i, j, n) += AT(a, i, k, n) * AT(b_transposed, j, k, n);
            }
        }
    }

    // sum of matrix c
    unsigned long res = 0;
#pragma omp parallel for default(none) firstprivate(c, n) reduction(+ : res)
    for (long i = 0; i < n; ++i) {
        for (long j = 0; j < n; ++j) {
            res += AT(c, i, j, n);
        }
    }
    double end_time = omp_get_wtime();
    printf("res: %lu, time: %2.2f seconds\n", res, end_time - start_time);

    // cleanup
    error_c:
    free(c);
    error_b:
    free(b);
    error_a:
    free(a);
    return status;
}
