/*
*       maratgon3.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	16.1.2017
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINLEN 80
#define MAX_SUM 30
#define MAX_OP 29
#define LEN 6


int do_add();


int main(void) {
        int i, wrong;
        
        wrong = 0;
        srand(time(NULL));
        
        for (i = 0; i < 100; i++) {
                wrong += do_add();
                printf("Celkem = %d, Chyb = %d\n\n", i + 1, wrong);
        }
        
        return 0;
}


int do_add() {
        int a, b, c, result, result2;
        int i, delta;
        char p[LINLEN];
        char t[LINLEN];
	char s[LINLEN];
        
        result = 0;
        a = rand() % (MAX_SUM + 1);
        snprintf(p, LINLEN, "%d ", a);
        c = a;
        
        
        for (i = 1; i < LEN; i++) {
                delta = (c > (MAX_SUM - c)) ? c : (MAX_SUM - c);  
                b = rand() % (delta + 1);

                if ((c + b) > MAX_SUM) {
                        if (b > MAX_OP)
                                b = b - MAX_OP;
                        snprintf(t, LINLEN, "- %d ", b);
                        c -= b;
                } else {
                        if (b > MAX_OP)
                                b = b - MAX_OP;
                        snprintf(t, LINLEN, "+ %d ", b);
                        c += b;
                }                  
                strncat(p, t, LINLEN - strlen(p) - 1);
        }
        
        strncat(p, "= ", LINLEN - strlen(p) - 1);

        do {
                printf("%s", p);
                fgets(s, LINLEN, stdin);
                if (c == atoi(s)) {
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
