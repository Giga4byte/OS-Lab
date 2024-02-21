#!/bin/bash

echo "GIRIBALA ARUN"
echo " "

echo "PRINTING EVEN NUMBERS"
for ((i=2; i<=100; i=i+2))
do
echo -n "$i "
done

echo " "
echo " "

echo "PRINTING THE FACTORIAL"
echo -n "Enter a number: "
read n1
FACT=1;
for ((i=1; i<=($n1); i++))
do
FACT=$((FACT*i))
done
echo "$FACT is the factorial of the given number"

echo " "
echo " "

echo "PRINTING THE REVERSE OF NUMBER"
echo -n "Enter a number: "
read n2
i=$n2;
SUM=0;
while [ $i != 0 ]
do
DIG=$((i%10))
SUM=$((SUM*10+DIG))
i=$((i/10))
done
echo "$SUM is the reverse of the given number"

echo " "
echo " "

echo "CHECKING FOR AN ARMSTRONG NUMBER"
echo -n "Enter a number: "
read n3
i=$n3;
SUM=0;
while [ $i != 0 ]
do
DIG=$((i%10))
DIGIT=$((DIG*DIG*DIG))
SUM=$((SUM+DIGIT))
i=$((i/10))
done
if [ $n3 -eq $SUM ]
then
echo "$n3 is an Armstrong Number"
else
echo "$n3 is not an Armstrong Number"
fi


echo " "
echo " "

echo "CHECKING WHETHER IT IS PRIME"
echo -n "Enter a number: "
read n4
flag=0
for ((i=2; i<n4; i++))
do
if [ $((n4%i)) -eq 0 ]
then
flag=1
break
fi
done
if [ $flag -eq 0 ]
then
echo "$n4 is a Prime number"
else
echo "$n4 is not a Prime number"
fi
