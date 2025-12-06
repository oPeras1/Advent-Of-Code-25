#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(long n) {
    if (n == 0)
        return 1;
    if (n < 0) 
        return 0;

    int c = 0;

    while (n > 0) {
        n /= 10;
        c++;
    }

    return c;
}

int main() {
    FILE *f = fopen("input.txt", "r");

    char input[1024];

    if (fgets(input, sizeof(input), f) == NULL) {
        exit(1);
    }

    char *pair = strtok(input, ",");

    long c = 0;

    while (pair != NULL) {
        char *dash = strchr(pair, '-');

        if (dash) {
            *dash = '\0';
            long a = atol(pair);
            long b = atol(dash+1);

            for (; a<=b; a++) {
                char numstring[1024];
                sprintf(numstring, "%ld", a);
                int lenstr = strlen(numstring);

                if (lenstr % 2 != 0) {
                    continue;
                }

                int hlenstr = lenstr/2;

                char f[1024];
                char s[1024];

                strncpy(f, numstring, hlenstr);
                f[hlenstr] = '\0';

                strcpy(s, numstring + hlenstr);

                if (strcmp(f,s) == 0) {
                    c+=a;
                }
            }

        }

        pair = strtok(NULL, ","); 
    }

    printf("%ld",c);

    return 0;
}
