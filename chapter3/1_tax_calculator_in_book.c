
#include <stdio.h> 

long double	tax_calculator_in_book(int income)
{
	long double	tax;

	if (income <= 2200) 
		tax = 0;
	else if (income <= 2700)
		tax = 0 + 0.14 * (long double)(income - 2200);
	else if (income <= 3200)
		tax = 70.00 + .15 * (long double)(income - 2700);
	else if (income <= 3700)
		tax = 145.00 + .16 * (long double)(income - 3200);
	else if (income <= 4200)
		tax = 225.00 + .17 * (long double)(income - 3700);
	else if (income <= 4700)
		tax = 310.00 + .18 * (long double)(income - 4200);
	else if (income <= 5200)
		tax = 400.00 + .19 * (long double)(income - 4700);
	else if (income <= 5700)
		tax = 495.00 + .20 * (long double)(income - 5200);
	else if (income <= 6200)
		tax = 595.00 + .21 * (long double)(income - 5700);
	else if (income <= 6700)
		tax = 700.00 + .22 * (long double)(income - 6200);
	else if (income <= 7200)
		tax = 810.00 + .23 * (long double)(income - 6700);
	else if (income <= 7700)
		tax = 925.00 + .24 * (long double)(income - 7200);
	else if (income <= 8200)
		tax = 1045.00 + .25 * (long double)(income - 7700);
	else if (income <= 8700)
		tax = 1170.00 + .26 * (long double)(income - 8200);
	else if (income <= 9200)
		tax = 1300.00 + .27 * (long double)(income - 8700);
	else if (income <= 9700)
		tax = 1435.00 + .28 * (long double)(income - 9200);
	else if (income <= 10200)
		tax = 1575.00 + .29 * (long double)(income - 9700);
	else if (income <= 10700)
		tax = 1720.00 + .30 * (long double)(income - 10200);
	else if (income <= 11200)
		tax = 1870.00 + .31 * (long double)(income - 10700);
	else if (income <= 11700)
		tax = 2025.00 + .32 * (long double)(income - 11200);
	else if (income <= 12200)
		tax = 2185.00 + .33 * (long double)(income - 11700);
	else if (income <= 12700)
		tax = 2350.00 + .34 * (long double)(income - 12200);
	else if (income <= 13200)
		tax = 2520.00 + .35 * (long double)(income - 12700);
	else if (income <= 13700)
		tax = 2695.00 + .36 * (long double)(income - 13200);
	else if (income <= 14200)
		tax = 2875.00 + .37 * (long double)(income - 13700);
	else if (income <= 14700)
		tax = 3060.00 + .38 * (long double)(income - 14200);
	else if (income <= 15200)
		tax = 3250.00 + .39 * (long double)(income - 14700);
	else if (income <= 15700)
		tax = 3445.00 + .40 * (long double)(income - 15200);
	else if (income <= 16200)
		tax = 3645.00 + .41 * (long double)(income - 15700);
	else if (income <= 16700)
		tax = 3850.00 + .42 * (long double)(income - 16200);
	else if (income <= 17200)
		tax = 4060.00 + .43 * (long double)(income - 16700);
	else if (income <= 17700)
		tax = 4275.00 + .44 * (long double)(income - 17200);
	else if (income <= 18200)
		tax = 4495.00 + .45 * (long double)(income - 17700);
	else if (income <= 18700)
		tax = 4720.00 + .46 * (long double)(income - 18200);
	else if (income <= 19200)
		tax = 4950.00 + .47 * (long double)(income - 18700);
	else if (income <= 19700)
		tax = 5185.00 + .48 * (long double)(income - 19200);
	else if (income <= 20200)
		tax = 5425.00 + .49 * (long double)(income - 19700);
	else if (income <= 20700)
		tax = 5670.00 + .50 * (long double)(income - 20200);
	else if (income <= 21200)
		tax = 5920.00 + .51 * (long double)(income - 20700);
	else if (income <= 21700)
		tax = 6175.00 + .52 * (long double)(income - 21200);
	else if (income <= 22200)
		tax = 6435.00 + .53 * (long double)(income - 21700);
	else if (income <= 22700)
		tax = 6700.00 + .54 * (long double)(income - 22200);
	else if (income <= 23200)
		tax = 6970.00 + .55 * (long double)(income - 22700);
	else if (income <= 23700)
		tax = 7245.00 + .56 * (long double)(income - 23200);
	else if (income <= 24200)
		tax = 7525.00 + .57 * (long double)(income - 23700);
	else if (income <= 24700)
		tax = 7810.00 + .58 * (long double)(income - 24200);
	else if (income <= 25200)
		tax = 8100.00 + .59 * (long double)(income - 24700);
	else if (income <= 25700)
		tax = 8395.00 + .60 * (long double)(income - 25200);
	else if (income <= 26200)
		tax = 8695.00 + .61 * (long double)(income - 25700);
	else if (income <= 26700)
		tax = 9000.00 + .62 * (long double)(income - 26200);
	else if (income <= 27200)
		tax = 9310.00 + .63 * (long double)(income - 26700);
	else if (income <= 27700)
		tax = 9625.00 + .64 * (long double)(income - 27200);
	else if (income <= 28200)
		tax = 9945.00 + .65 * (long double)(income - 27700);
	else if (income <= 28700)
		tax = 10270.00 + .66 * (long double)(income - 28200);
	else if (income <= 29200)
		tax = 10600.00 + .67 * (long double)(income - 28700);
	else if (income <= 29700)
		tax = 10935.00 + .68 * (long double)(income - 29200);
	else if (income <= 30200)
		tax = 11275.00 + .69 * (long double)(income - 29700);
	else
		tax = 11620.00 + .70 * (income - 30200);
	return (tax);
}
