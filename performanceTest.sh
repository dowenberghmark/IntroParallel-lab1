#!/bin/bash



for T in 1 2 4 8 16 32
do
    for N in 1 2 4 8 16 32
    do
        echo "T:$T N:$N "
        ./performance $T $N
        echo ""
    done
done
