#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void	calculate_terms(int *arr, int *coef, int k, int cnt)
{
	for (int i = 0 ; i < cnt ; i++)
	{
		arr[k + i] = coef[k];
		for (int j = 1 ; j <= k ; j++)
			arr[k + i] += coef[j] * arr[k + i - j];
	}
}

void	print_arr(int *arr, int m)
{
	for (int i = 0 ; i < m ; i++)
		printf("arr_%d : %d\n", i + 1, arr[i]);
}

int main(void)
{
	int k, m;
	int	*arr, *coef, *tem;

	scanf("%d", &k);
	if (!(arr = malloc(sizeof(int) * k)))
		return (1);
	for (int i = 0 ; i < k ; i++)
		scanf("%d", arr + i);
	if (!(coef = malloc(sizeof(int) * (k + 1))))
		return (1);
	for (int i = 0 ; i < k + 1 ; i++)
		scanf("%d", coef + i);
	scanf("%d", &m);
	if (m > k)
	{
		if (!(tem = malloc(sizeof(int) * m)))
			return (1);
		memcpy(tem, arr, sizeof(int) * k);
		free(arr);
		arr = tem;
		calculate_terms(arr, coef, k, m - k);
	}
	print_arr(arr, m);
	free(arr);
}