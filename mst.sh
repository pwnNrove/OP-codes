echo "1. Less than"
echo "2. Greater than"
echo "3. Not equal to"
echo "4. Equal to"
echo "Enter choice:"
read a
#echo "$a"
echo "Enter 2 numbers:"
read b c

if [[ $a -eq 1 ]];
then if [ $b -lt $c ]
then echo "$b is less than $c"
else
echo "$c is less than $b"
fi
fi

if [[ $a -eq 2 ]];
then if [ $b -gt $c ]
then echo "$b is greater than $c"
else
echo "$c is greater than $b"
fi
fi

if [[ $a -eq 3 ]];
then 
echo "Checking for unequality..."
if [ $b -ne $c ]
then echo "Result: True"
echo "$b is not equal to $c"
else
echo "Result: False"
fi
fi

if [[ $a -eq 4 ]];
then echo "Checking for equality..."
if [ $b -eq $c ]
then echo "Result: True"
echo "$b is equal to c"
else
echo "Result: False"
fi
fi
