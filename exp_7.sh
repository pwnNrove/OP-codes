echo "Akshit Gupta - 21BCS3509"
echo "Enter number: "
read a
echo "------ While loop -------"
while [ $a -le 5 ]
do
echo "$a"
a=$(( $a+1 ))
done
echo "-----------------------------"
echo "-------- Until loop ---------"
until [ $a -lt 0 ]
do
echo "$a"
let a-=1
done
echo "-----------------------------"
