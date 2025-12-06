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

                for (int p = 1; p <= lenstr / 2; p++) {

                    if (lenstr % p != 0)
                        continue;

                    int pieces = lenstr / p;
                    int equal = 1;

                    for (int i = 1; i < pieces; i++) {
                        if (strncmp(numstring, numstring + i * p, p) != 0) {
                            equal = 0;
                            break;
                        }
                    }

                    if (equal) {
                        c += a;
                        break; 
                    }
                }
            }

        }

        pair = strtok(NULL, ","); 
    }

    printf("%ld",c);

    return 0;
}
