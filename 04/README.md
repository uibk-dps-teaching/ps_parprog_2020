# Assignment 4, due April 22nd, 2020

The goal of this task is to gain more practice in parallelizing programs with OpenMP.


## Exercise 1 (1 Point)

### Description

This exercise consists of implementing the Monte Carlo Pi approximation of assignment 02 in OpenMP.    

### Tasks

- Implement parallel versions of the Monte Carlo Pi approximation of assignment 02 using OpenMP. In total, three different versions using the following OpenMP constructs should be implemented:
    - `critical` section
    - `atomic` statement
    - `reduction` clause
- Benchmark your parallel implementations with 1, 2, 4, and 8 threads on LCC2 using n=500,000,000. What can you observe? How do those results compare to your measurements in Assignment 02?


## Exercise 2 (1 Point)

### Description

This exercise deals with performance analysis and improvement of a given [code](ex2.c). The program reads a matrix size n from the command-line. Then two square matrices a and b of size n\*n are filled with random numbers. Finally, the program should print the sum of all elements of matrix c and the wall clock time after the matrix multiplication c=a\*b was conducted. 

### Tasks

- Are there any (performance) issues in the given code? Document your findings.
- Improve the performance of the given source code. 
- Benchmark your modification of the code and the original implementation with 1, 2, 4, and 8 threads on LCC2 using n=1,500. Has your effort paid off?


## Exercise 3 (1 Point)

### Description

In this exercise, you are asked to implement merge sort for arrays of type `int32_t *`. The input for your program should be the size of the array to sort. The generated array should be filled randomly using a pseudo-random number generator provided in `stdlib.h`. Note that, for now, the implementation and parallelization do not have to be particularly optimal. We will continue to optimize this program in the next assignment.

### Tasks

- Implement a sequential, iterative version of merge sort.
- Create a set of tests to ensure that the algorithm sorts properly. You need not to use a unit testing framework.
- Implement a parallel, iterative version of merge sort using OpenMP.


## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
