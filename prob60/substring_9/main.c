#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	cmp_asc(const void *n1, const void *n2) {
	if (*(int *)n1 > *(int *)n2)
		return 1;
	else if (*(int *)n1 < *(int *)n2)
		return -1;
	else
		return 0;
}
int	get_line(char *buf) {
	int i = 0;
	while (1) {
		int size = read(0, &buf[i], 1);
		if (buf[i] == '\n' || buf[i] == '\0') 
			break;
		if (size == 0) 
			break;
		i++;
	}
	buf[i] = '\0';
	int last = i;
	return last;
}

int	main(void) {
	char str1[101];
	get_line(str1);
	int a = 0, b = 0;
	sscanf(str1, "%d %d", &a, &b);
	
	char str2[101];
	get_line(str2);
	// printf("%s\n", str2);
	for (int i = a-1; i <= b-1; i++) {
		printf("%c", str2[i]);
	}
	printf("\n");

	return (0);
}