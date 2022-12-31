#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void) {
    char N[3];
    while(*N != '\n') {
        read(0, &N, 1);
        // write(1, &N, 1);
    }
	
    char buf[1600];
    while (1) {
        int read_size = read(0, &buf, 1);
        if (read_size <= 0) {
            break;
        }
		write(1, &buf, 1);
    }
	return (0);
}