#!/bin/bash
export OMP_NUM_THREADS=1
echo 1 Thread
time ./multipi 400 1> /dev/null
echo 2 Threads
export OMP_NUM_THREADS=2
time ./multipi 400 1> /dev/null
export OMP_NUM_THREADS=4
echo 4 Threads
time ./multipi 400 1> /dev/null
export OMP_NUM_THREADS=8
echo 8 Threads
time ./multipi 400 1> /dev/null
