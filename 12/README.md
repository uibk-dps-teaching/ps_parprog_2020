# Assignment 12, due June 17th, 2020

The goal of this assignment is to study several means of vectorizing a simple program.


## Exercise 1 (1 Point)

### Description

Vectorization (also called SIMD - Single Instruction, Multiple Data) is an instruction level parallelism (ILP) technique for increasing the performance of programs without the need for multiple cores/threads. You can refer to e.g. slides 22-28 of [this slide set](https://github.com/philippgs/uibk_parsys_19/blob/master/lecture/09_openmp_advanced.pdf) for a short description or do some quick study of the topic on the Internet for more information. In this exercise, we will employ auto-vectorization of the compiler to increase the performance of a small program that computes a multiply-add operation on three vectors.

### Tasks

- Write a sequential program that computes `a[i] += b[i] * c[i]` for three `float` vectors `a`, `b`, and `c`. Enclose this computation in a loop such that it is repeated often enough to yield an overall execution time of a few seconds. I.e. your code should look like this:
```
for(int run = 0; run < repetitions; ++run) {
    for(int i = 0; i < size; ++i) {
        a[i] += b[i] * c[i];
    }
}
```
- Initialize the vectors with constant values and add some output that allows you to verify correct computation of the program for subsequent optimization steps. Compile this program on LCC2 with `gcc 8.2.0` using `-O1` and measure the execution time **of the computation only** for several problem sizes (=vector lenghts). This sequential program is our baseline reference.
- Try to use auto-vectorization in the compiler to vectorize the computation. Investigate which flag(s) to use for that, and try to limit your compiler change to only enable vectorization but not any other optimizations. Measure the execution time for the same problem sizes as before and compute the respective speedups. What can you observe in terms of performance? Is the result still correct?
- Use `perf` to further investigate the origin of any performance difference you might observe. `perf stat -e rYYXX` allows you to measure custom events supported by the CPU, where - on Intel systems - XX is the so-called *event code* and YY is the so-called *unit mask* (also called *umask*). A few event codes and unit masks for measuring vectorized instructions are given below. Check which ones are suitable for your investigation:

| Name                            | Event Code | Unit Mask |
|---------------------------------|:----------:|:---------:|
| SIMD_INST_RETIRED.PACKED_SINGLE |     C7     |    01     |
| SIMD_INST_RETIRED.SCALAR_SINGLE |     C7     |    02     |
| SIMD_INST_RETIRED.PACKED_DOUBLE |     C7     |    04     |
| SIMD_INST_RETIRED.SCALAR_DOUBLE |     C7     |    08     |
| SIMD_INST_RETIRED.VECTOR        |     C7     |    10     |
| SIMD_INST_RETIRED.ANY           |     C7     |    1F     |

In case you are interested: For further events relevant to the CPU type on LCC2 and short event descriptions, see Table 19-23 on pages 415-438 of the [Intel® 64 and IA-32 Architectures Software Developer’s Manual Volume 3B: System Programming Guide, Part 2](https://www.intel.com/content/www/us/en/architecture-and-technology/64-ia-32-architectures-software-developer-vol-3b-part-2-manual.html). It lists all events that can be counted with `perf` on our hardware.


## Exercise 2 (1 Point)

### Description

Instead of relying on the compiler to vectorize the code for us, we will do so manually in this exericse, using OpenMP.

### Tasks

- Vectorize your sequential program using OpenMP (see the description of Exercise 1 for material on this topic). Ensure proper alignment of the data to at least 16 bytes. Do not use OpenMP's thread-based parallelism that we employed so far in this course.
- Compile your OpenMP-vectorized code with `-O1` but without any compiler flags for auto-vectorization and compare its performance for your set of problem sizes to both the sequential version and the compiler-vectorized version. What can you observe? Is the result still correct?
- Verify any findings using `perf` as described in Exercise 1.
- Repeat the sequential and OpenMP executions when changing the data type from `float` to `double`. What can you observe?
- How does the solution for this Exercise compare to Exercise 1? Are there any advantages or disadvantages?

## Exercise 3 (1 Point)

### Description

Instead of relying on OpenMP for vectorization, we will do so using compiler-specific intrinsics in this exercise.

### Tasks

- Vectorize your code for `float` types using the gcc-specific intrinsic functions `_mm_load_ps`, `_mm_add_ps`, `_mm_mul_ps`, and `_mm_store_ps`. Do not forget to include the respective header `xmmintrin.h`.
- Compile your manually vectorized code with `-O1` but without any compiler flags for auto-vectorization  and compare its performance for your set of problem sizes to your previous code versions. What can you observe? Is the result still correct?
- Verify any findings using `perf` as described in Exercise 1.
- How does the solution for this Exercise compare to Exercise 2 and Exercise 1? Are there any advantages or disadvantages?

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.