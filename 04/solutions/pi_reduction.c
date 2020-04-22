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
        //seed dependant on thread_num, that each thread has own seed
        unsigned int seed = SEED + omp_get_thread_num();

        // reduction gets translated to a private variable which is incremented in the loop
        // and atomic operation of reduction gets done at the end of the loop in an atomic clause
#pragma omp for reduction(+:nr_of_points_inside)
        for (long i = 0; i < N; i++) {
            x = (double) rand_r(&seed) / RAND_MAX;
            y = (double) rand_r(&seed) / RAND_MAX;


            if (x * x + y * y <= 1)
                nr_of_points_inside++;
        }

    }
    double pi;
    pi = 4 * ((double) nr_of_points_inside / N);

    printf("Pi: %lf\n", pi);
    return EXIT_SUCCESS;
}


