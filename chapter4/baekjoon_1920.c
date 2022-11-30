#include <stdio.h>
#include <stdlib.h>

int	compare_int(const void *a, const void *b)
{
	const int	*n1 = a;
	const int	*n2 = b;

	if (*n1 > *n2)
		return (1);
	else if (*n1 == *n2)
		return (0);
	else
		return (-1);
}

int	 binary_search(int *x, int q, int l, int u)
{
	int	m;

	if (l > u)
		return (-1);
	if (q == x[l])
		return (l);
	if (q == x[u])
		return (u);
	m = (l + u) / 2;
	if (q < x[m])
		return (binary_search(x, q, l, m - 1));
	if (q > x[m])
		return (binary_search(x, q, m + 1, u));
	return (m);
}

int	main(void)
{
	int	n, m;
	int	*x;
	int	t, q;

	scanf("%d", &n);
	if (!(x = malloc(sizeof(int) * n)))
		return (1);
	for (int i = 0 ; i < n ; i++)
		scanf("%d", &x[i]);
	qsort(x, n, sizeof(int), compare_int);
	scanf("%d", &m);
	for (int i = 0 ; i < m ; i++)
	{
		scanf("%d", &q);
		t = binary_search(x, q, 0, n - 1);
		if (t >= 0)
			printf("1\n");
		else
			printf("0\n");
	}
	return (0);
}