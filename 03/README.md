# Assignment 3, due April 1st, 2020

The goal of this assignment is to get to know the basic functionality of OpenMP.

## Exercise 1 (1 Point)

### Description

This exercise should get you familiar with basic OpenMP variables. 

### Tasks

- Write a parallel "Hello World" in OpenMP where each thread prints its own thread number and the total number of threads.
- Run it several times. What can you observe regarding the order of output lines? How can this be fixed?
- Change your program such that all threads print their own thread number but only a single thread prints the total number of threads.
- What happens when you nest two or more parallel regions?

## Exercise 2 (1 Point)

### Description

This exercise consists of extending the Hadamard product implementation of the previous assignment.

### Tasks

- Implement parallel versions of both snippets of the Hadamard product of the previous Assignment using OpenMP.
- Find out which function OpenMP offers for measuring time and use it for the following experiments on LCC2 (compute nodes only via job submission, not on the login node!).
- Benchmark your serial implementations and your parallel implementations with 1, 2, 4 and 8 threads on LCC2 using n=10.000, 20.000 and 30.000.
- Use the 3 loop scheduling methods discussed in the lecture, static, dynamic and guided. Explain their differences and compare their performance for the two code snippets. What can you observe?

## Exercise 3 (1 Point)

### Description

This exercise deals with time measurements.

### Tasks

- The tool `/usr/bin/time` can be used to get useful information on the properties of a program's execution, e.g. its execution time or the maximum amount of main memory used.
- Measure the execution time of your OpenMP implementation of the Hadamard product using `/usr/bin/time -v <program_name>`. Take a look at the output, specifically "user time" and "elapsed (wall clock) time". How do they differ? Does either of them match the time measurement function of OpenMP?

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
