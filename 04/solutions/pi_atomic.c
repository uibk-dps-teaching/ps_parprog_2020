#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

//more readable, gets optimized by compiler anyway
#define N 5 * 100 * 1000 * 1000

//some random seed, always same for reproducibility
#define SEED 15151532

int main() {
    long nr_of_points_inside = 0;

#pragma omp parallel
    {
        double x, y;
        unsigned int seed = SEED + omp_get_thread_num();

#pragma omp for
        for (long i = 0; i < N; i++) {
            x = (double) rand_r(&seed) / RAND_MAX;
            y = (double) rand_r(&seed) / RAND_MAX;


            // atomic only supports a restricted set of expressions, all those expressions happen inseparable, either it happens completely
            // or it does not happen at all(a thread cannot intervene during an event).
            // atomic operation has way less overhead than critical, where available might also take advantage of
            // hardware atomic operations( that means that synchronization is guaranteed by hardware)
            // atomic operation does not block any other atomic operations
            if (x * x + y * y <= 1) {
#pragma omp atomic
                nr_of_points_inside++;
            }
        }

    }
    double pi;
    pi = 4 * ((double) nr_of_points_inside / N);

    printf("Pi: %lf\n", pi);
    return EXIT_SUCCESS;
}


