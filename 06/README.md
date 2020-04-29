# Assignment 6, due May 6th, 2020

The goal of this task is to get a first feeling with using OpenMP tasks.
Additionally we take a first look at a heat stencil application.


## Exercise 1 (1 Point)

### Description

This exercise consists of implementing a program that calculates a folder size (with all subfolders) using OpenMP and Tasks. 

### Tasks

- Implement parallel versions using Tasks to calculate the size of a folder of a given size. Make sure you handle errors and invalid paths correctly.
- The path should be given as program argument, e.g. `./folder_size /path/to/dir`
- Tips:
    * Use `lstat` , `opendir` and `readdir` (read the according man pages)
    * Make sure to correctly handle permission denied
    * It suffices to show the bytes used of the files. 
    * You can check your result with `du -sb /path/to/dir`
- Benchmark your parallel implementations with 1, 2, 4, and 8 threads on your home directory of your own pc. (If that takes too long, choose a other big directory)

## Exercise 2 (2 Points)

### Description

This exercise consists of implementing a 2-Dimensional heat stencil application.

A large class of scientific applications are so-called stencil applications. These simulate time-dependent physical processes 
such as the propagation of heat or pressure in a given medium. The core of the simulation operates on a grid and updates each
 cell with information from its neighbor cells.


<img alt="heat_stencil" src="https://upload.wikimedia.org/wikipedia/commons/e/ec/2D_von_Neumann_Stencil.svg" width="40%">

### Tasks

- Given the code in heat_stencil_2D.c, finish the implementation: 
    * make sure the heat source stays the same through all iterations
    * if you meet a boundary value, use temperature at own position for the next value (e.g if you want to calculate M[0,1], use M[0,1] as the left cell instead of M[-1,1] because that doesn't exists)
    * The simple verification at the end should succeed
- Measure the time, speedup and efficiency of the stencil codes for varying problem and thread sizes. 
- Show your results in figures


## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.

