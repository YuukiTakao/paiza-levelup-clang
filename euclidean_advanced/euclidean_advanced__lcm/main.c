#include <stdio.h>
#include <stdlib.h>


int greatest_common_divisor(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int least_common_multiple(int a, int b) {
	return a * b / greatest_common_divisor(a, b);
}
int	main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", least_common_multiple(a, b));
	return (0);
}