#!/bin/bash
echo "Enter a number "
read a

#if [ $a % 5 != 0]
#then
#	echo "$a is not divisible by 5"
#else
#	echo "$a is divisible by 5"
#fi

c=$(( !a ))
echo "Not $a is $c"


