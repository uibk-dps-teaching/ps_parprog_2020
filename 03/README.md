# Assignment 3, due Apri 1st, 2020

The goal of this assignment is to get to know basic functionality of OpenMP.


## Exercise 1 (1 Point)

### Description

This exercise consist of extending the Hadamard product implementation of the previous assignment.

### Tasks

- Implement a parallel version of both snippets of the hadamarad product.
- Are there performance differences? Explain why.
- Try to further optimize the implementation. 


## Exercise 2 (2 Points)

### Description

This exercise consist of extending the Monte Carlo Pi implementation of the previous assignment.

### Tasks

- Implement a parallel version of Monte Carlo Pi approximation using OpenMP using the `critical` construct.
- Implement a parallel version of Monte Carlo Pi approximation using OpenMP using the `reduction` construct.
- Benchmark the sequential version and the parallel version with 1, 2, 4, and 8 threads on LCC2 using n = 500,000,000. 
- Document your results and state problems that you might have had. 
- Are there performance differences between critical and reduction? Explain why.




## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.

