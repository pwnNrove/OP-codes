echo "Enter 2 numbers [Either 0 or 1]:"
read a b

if [ $a -eq 0 -o $a -eq 1 ]
then
	if [ $b -eq 0 -o $b -eq 1 ]
	then
		c=$(($a | $b))
		echo "$a or $b is $c"
	fi
fi
