# Assignment 3, due Apri 1st, 2020

The goal of this assignment is to get to know basic functionality of OpenMP.


## Exercise 1 (1 Point)

### Description

This exercise should get you familiar with basic OpenMP variables. 

### Tasks

Find the following environment variables in OpenMP and explain them.
 - Get own Thread number
 - Number of processors
 - Number of threads 
 - Max number of threads 
 - Threads In parallel
 - Dynamic threads enabled
 - Nested parallelism enabled

Print all these variables only in one thread, but run your program using 8 threads.
Additionally add a Hello world with the own thread number in a parallel region.

## Exercise 2 (2 Points)

### Description

This exercise consist of extending the Hadamard product implementation of the previous assignment.

### Tasks

- Implement a parallel version of both snippets of the hadamarad product.
- Use these 3 scheduling methods: static, dynamic and guided. Explain those 3 methods and compare their performance
- Benchmark your serial and parallel versions with 1, 2, 4 and 8 threads on LCC2 using n=10,000, 20,000 and 50,000


## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.

## Exercise 3 (1 Point)