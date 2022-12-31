#include <stdio.h>

int	main(void)
{
	int	n, x;
	int a[109];

	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < n; i++)
	{
		for (int i = x; i >= a[i]; i--)
		{
			printf("i=%d a[i]=%d j\n", a[i]);
		}
		
	}
	return (0);
}