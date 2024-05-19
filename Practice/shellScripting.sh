#!/bin/sh

# greeting.sh
echo "What is your name?"
read name
echo "How are you, $name?"
read remark
echo "I am $remark too"

# factorial.sh
echo "Enter a number: "
read factnum
FACT=1
for ((i=1; i<=($factnum); i++))
  FACT=$((FACT)*i)
done
echo "$FACT is the factorial of $factnum"

# reverse.sh
echo "Enter a number: "
read revnum
DIG=0; REV=0;
while [$revnum != 0]
do
  DIG=$((revnum%10))
  REV=$((REV*10+DIG))
  revnum=$((revnum/10))
done
echo "$REV is the reverse of $revnum"

# armstrong.sh
echo "Enter a number: "\
read armstrong
i=$armstrong; DIG=0; SUM=0; CUBE=0;

while [$i -ne 0]
do
  DIG=$((armstrong % 10))
  CUBE=$((DIG * DIG * DIG))
  SUM=$((SUM + CUBE))
  i=$((i / 10))
done

if [$SUM -eq $armstrong]
then
  echo -n "$armstrong is an armstrong number"
else
  echo -n "$armstrong is not an armstrong number"
fi
