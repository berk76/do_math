/*
*       maratgon2.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	9.1.2017
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINLEN 10

int do_add(int max);
int do_sub(int max);


int main(void) {
        int i, wrong, max;
        
        wrong = 0;
        max = 10;
        srand(time(NULL));
        
        for (i = 0; i < 100; i++) {
                wrong += do_add(max);
                printf("Celkem = %d, Chyb = %d\n", i + 1, wrong);
        }
        
        return 0;
}


int do_add(int max) {
        int a, b, c, d, result, result2;
	char s[LINLEN];
        
        result = 0;
        a = rand() % (max + 1);
        b = rand() % (max + 1);

        if (a > b) {
                a -= b;
        } else {
                b -= a;
        }

        d = rand() % (a + b + 1);

        do {
                printf("%d + %d = %d + ", a, b, d);
                fgets(s, LINLEN, stdin);
		c = atoi(s);
                if ((c + d) == (a + b)) {
                        printf("Vyborne! :-)\n");
                        result2 = 0;
                } else {
                        printf("Spatne! :-(\n");
			result = 1;
                        result2 = 1;
                }
        } while (result2 != 0);
        
        return result;
}
