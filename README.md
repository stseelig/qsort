# qsort

a qsort(3) implementation


## About

It is implemented as the POSIX qsort_r(3),
with qsort(3) being a wrapper/jump for qsort_r(3).


Three different sorting algorithms are used:

* small arrays  - shellsort

* medium arrays - heapsort

* large arrays  - iterative quicksort with heapsort as a fallback


Swapping is optimized for arrays with member sizes <=16, 20, 24, 28, or 32.
Other sizes will take a little performance hit.


It will perform below par if your CPU:

* has a bad branch predictor

* cannot do >2 integer operations at a time

* makes relatively slow (indirect) function calls


## Building

```
$ cc -std=c11 -O3 ./src/build.c
```

I highly recommend using clang(1) instead of gcc(1).


### Defines

QSORT_OPT_NO_ASM

* disables some inline assembly
