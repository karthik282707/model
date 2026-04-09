#!/bin/bash
print_loop() {
    n=1
    while [ $n -le 5 ]
    do
        echo "$n"
        n=$((n + 1))
    done
}

print_loop
