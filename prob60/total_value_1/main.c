#include <stdio.h>

int	main(void) {
    char str[5];
    fgets(str, 5, stdin);
    // printf("%s", str);
    
    int N;
    sscanf(str, "%d", &N);
    
    for (int i = 0; i < N; i++) {
        char str1[31];
        fgets(str1, 31, stdin);
        printf("%s", str1);
    }
    return 0;
}