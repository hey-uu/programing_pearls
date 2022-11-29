#include <stdio.h>

#define BINARY_NUM 0xff
#define IS_ON(n, i) (n & (1 << i)) > 0

enum e_segment
{
	ZERO = ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 0)),
	ONE = ((1 << 3) | (1 << 5)),
	TWO = ((1 << 2) | (1 << 4) | (1 << 1) | (1 << 5) | (1 << 0)),
	THREE = ((1 << 2) | (1 << 4) | (1 << 1) | (1 << 5) | (1 << 0)),
	FOUR = ((1 << 3) | (1 << 1) | (1 << 4) | (1 << 6)),
	FIVE = ((1 << 2) | (1 << 3) | (1 << 1) | (1 << 6) | (1 << 0)),
	SIX = ((1 << 2) | (1 << 3) | (1 << 1) | (1 << 5) | (1 << 0) | (1 << 6)),
	SEVEN = ((1 << 3) | (1 << 2) | (1 << 4) | (1 << 6)),
	EIGHT = ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6)),
	NINE = (EIGHT & ~(1 << 5))
};

void	seven_segment_device(int n, int arr[5])
{
	int digit[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

	if (n < 0)
	{
		printf("this is negative number\n");
		return ;
	}
	for (int i = 0 ; i < 5 ; i++)
	{
		arr[i] = digit[n % 10];
		n /= 10;
	}
}

void	display_number(int num)
{
	if (IS_ON(num, 2))
		printf(" ---\n");
	else
		printf("\n");
	if (IS_ON(num, 3) && IS_ON(num, 4))
		printf("|   |\n");
	else if (IS_ON(num, 3))
		printf("|\n");
	else if (IS_ON(num, 4))
		printf("    |\n");
	if (IS_ON(num, 1))
		printf(" ---\n");
	if (IS_ON(num, 5) && IS_ON(num, 6))
		printf("|   |\n");
	else if (IS_ON(num, 5))
		printf("|\n");
	else if (IS_ON(num, 6))
		printf("    |\n");
	if (IS_ON(num, 0))
		printf(" ---\n");
	else
		printf("\n");
	printf("\n");
}

int main(void)
{
	int	arr[5];

	seven_segment_device(BINARY_NUM, arr);
	for (int i = 0 ; i < 5 ; i++)
		display_number(arr[4 - i]);
}