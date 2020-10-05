# Exercises for 30/09-2020

Based on exercises by: Michael Kirkedal Thomsen <kirkedal@acm.org>

## Finish leftover exercises from Monday

I you have unfinished business from Monday, finish it first.


## Simple performance measurements

You can use `time(1)` to get a quick measurement of the execution time. Be aware that this is not very accurate and can be
susceptible to cache effects and what other tasks are running. So run it several times to get a good estimate. To run use

```
> time ./[program]
```

If you want a better profiling you can look at the Linux tool `gprof(1)` or Google Performance Tools.

## Summing an array

Consider the two programs from the lecture included in the `exercise_code` directory.

### Locality

First, recap the two types of locality that we would like to achieve to in order to get good performance. Why does `sum_array_rows` have better locality than `sum_array_cols`? Which types of locality does the programs have?

### Performance

Try to run the programs on increasing sizes until you can see a difference. See below

Map the execution time for increasing sizes of input. Compare the two programs. What is the asymptotic behaviour? Calculate the execution time per element.

How does it compare to the operations per element that we discussed at the lecture? You need to examine the assembler code to know the exact number for this.

Hint, I can suggest that you setup a simple test-bench (e.g. using a script) that makes the above calculations, but don't spend too much time on it.

## Summing a 3D array

Consider the following program taken from the slides (note, the indices on the slides are messed up, so this is more correct).

```
/* You might want to use different values for L,M,N when performing benchmarks. */
#define L 10
#define M 10
#define N 10

long sum_array_3d(long a[L][M][N])
{
  long sum = 0;
  int i, j, k;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < L; k++) {
        sum += a[k][i][j];
      }
    }
  }
  return sum;
}
```

There is a good reference for how to use 3d arrays here on [stackoverflow](https://stackoverflow.com/questions/40845302/passing-three-dimensional-arrays-to-a-function-in-c).


### Locality
Sketch what the structure of a 3D array will be like in the 1D memory of the computer. What should be the order of the indices be to achieve spacial locality?

### Performance

Write the above into a C program that you can run. You can base it on the previous examples.

Test with different ordering of the indices to very verify your previous result.

Take care to prevent the compiler from completely optimizing away your computation.

