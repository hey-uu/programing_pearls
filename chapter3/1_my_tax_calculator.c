#include <stdio.h>

long double	tax_calculator_in_book(int income);

long double	my_tax_calculator(int income)
{
	long double	weight, diff, tax;

	weight = 0.14;
	diff = income - 2200;
	tax = 0;
	while (diff > 500 && weight < 0.70)
	{
		tax += weight * 500;
		weight += 0.01;
		diff -= 500;
	}
	if (diff > 0)
		tax += weight * diff;
	return (tax);
}
 

int main(void)
{
	int income;

	printf("Enter an income: ");
	while (scanf("%d", &income) != EOF)
	{
		printf("mine: %Lf\n", my_tax_calculator(income));
		printf("book : %Lf\n", tax_calculator_in_book(income));
		printf("Enter an income: ");
	}
}