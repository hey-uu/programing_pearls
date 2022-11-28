#include <stdio.h>

long double	get_tax(int income)
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

long double	get_tax_older_one(int income)
{
	if (income <= 2200)
		return (0);
	if (income <= 2700)
		return (0.14 * (income - 2200));
	if (income <= 3200)
		return (70 + 0.15 * (income - 2700));
	if (income <= 3700)
		return (145 + 0.16 * (income - 3200));
	if (income <= 4200)
		return (225 + 0.17 * (income - 3700));
	return (53090 + 0.70 * (income - 102200));
}

int main(void)
{
	int income;

	while (scanf("%d", &income) != EOF)
	{
		printf("mine: %Lf\n", get_tax(income));
		printf("book : %Lf\n", get_tax_older_one(income));
	}
}