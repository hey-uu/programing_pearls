#! /bin/bash

source_file="1_tax_calculator_in_book.c"

income=2200
tax=0
weight=0.14
c=0

front="
#include <stdio.h> 

long double	tax_calculator_in_book(int income)
{
	long double	tax;

	if (income <= $income) 
		tax = 0;"
echo "$front" > $source_file


while [ $(echo "(0.70 - $weight) > 0" | bc) -eq 1 ]
do
	echo $income
	echo "	else if (income <= $(expr $income + 500))" >> $source_file
	echo "		tax = $c + $weight * (long double)(income - $income);" >> $source_file
	c=$(echo "$c + $weight * 500" | bc)
	income=$(expr $income + 500)
	weight=$(echo $weight + 0.01 | bc)
done

end="	else
		tax = $c + $weight * (income - $income);
	return (tax);
}"

echo "$end" >> $source_file