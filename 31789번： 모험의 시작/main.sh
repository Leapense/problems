#!/bin/bash

read N

read X S

can_defeat="NO"

for (( i=0; i<N; i++ ))
do
    read c_i p_i
    if (( c_i <= X && p_i > S )); then
        can_defeat="YES"
        break
    fi
done

echo $can_defeat
