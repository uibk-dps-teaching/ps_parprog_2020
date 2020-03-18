# Assignment 2, due March 25th, 2020

The goal of this assignment is to get a first grasp of performance-oriented programming. Furthermore, you will be using the LCC2 cluster, `cachegrind`, and `perf` for the first time in this lab.


## Exercise 1 (1 Point)

### Description

You are given a sequential and a parallel implementation of an algorithm. The sequential algorithm runs in O(n^(2.8)) time complexity, while the parallel algorithm runs in O(n^3/p + n) time complexity with p processors.

### Tasks
- What is the theoretical speedup comparing the parallel algorithm using one processor vs. the parallel algorithm using p processors?
- What is the theoretical speedup comparing the sequential algorithm vs. the parallel algorithm?
- Given a fixed input size n. How many processors are required such that the parallel algorithm is faster than the sequential?


## Exercise 2 (1 Point)

### Description

The Hadamard product is defined as the element-wise product of two matrices with the same dimensions. The following two snippets give an implementation of the Hadamard product for n x n square matrices.

```C
for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
        c[i][j] = a[i][j] * b[i][j];
    }
}
```

```C
for (size_t j = 0; j < n; ++j) {
    for (size_t i = 0; i < n; ++i) {
        c[i][j] = a[i][j] * b[i][j];
    }
}
```

### Tasks

- For both implementations, give a function f to calculate the number of data cache read misses for the matrix size n and the cache line size s in an 8-way set-associative cache. Assume that all variables are initialized appropriately (the matrix elements are of type `int32_t`) and that the matrices are stored in contiguous memory in row-major order. Additionally, the matrices are too large to store them entirely in the cache (n >> s).
- Use the two snippets to implement two versions of the Hadamard product. 
- Log into the LCC2 cluster and analyze the cache behavior of the implementations using `cachegrind` and `perf`. Can you validate your theoretical findings? Compare the results of both tools.


## Exercise 3 (1 Point)

### Description

There are several methods to approximate Pi numerically. In this exercise, you are asked to approximate Pi using the Monte Carlo method. Therefore, n (n >> 1) random 2D points equally distributed in the interval [0, 1] x [0, 1] are generated, and it is checked whether they are inside the first quadrant of a unit circle. Let i be the number of points that lie inside the quarter of the unit circle. Then Pi can be approximated by 4 * i / n.

### Tasks

- Implement a serial version of Monte Carlo Pi approximation.
- Implement a parallel version of Monte Carlo Pi approximation using POSIX Threads Library (`pthread`).
- Benchmark the sequential version and the parallel version with 1, 2, 4, and 8 threads on LCC2 using n = 500,000,000. Document your results. How could you improve program performance?


## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.

