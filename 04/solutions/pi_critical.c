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

            // a critical block means that in this specific block, only one thread can be at a time
            // that means if thread 1 is in the critical block, all the other threads need to wait until it has finished
            // this synchronization means a lot of overhead.
            // Note that if you have multiple (unnamed) critical blocks in your code, and one thread is in one (unnamed) critical
            // block, no thread can enter any (unnamed) critical block.
            if (x * x + y * y <= 1) {
#pragma omp critical
                nr_of_points_inside++;
            }
        }

    }
    double pi;
    pi = 4 * ((double) nr_of_points_inside / N);

    printf("Pi: %lf\n", pi);
    return EXIT_SUCCESS;
}


