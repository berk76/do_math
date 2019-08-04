/*
*       muldiv.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	1.6.2018
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MUL_DIV_MAX 1000
#define LINLEN 80

char s[LINLEN];

int do_mul();
int do_div();
int get_rand(int min, int max, int old);


int main(void) {
        int errors, i, n;
        
        srand(time(NULL));
        errors = 0;
        
        do {
                printf("%s", "Kolik prikladu budeme pocitat? ");
                fgets(s, LINLEN, stdin);
                n = atoi(s);
        } while (n <= 0);
        
        for (i = 0; i < n; i++) {
                if ((rand() % 2) == 0) {
                        errors += do_mul();
                } else {
                        //errors += do_div();
                        errors += do_mul();
                }
        }
        
        printf("%s","\n");
        printf("Pocet prikladu: %d\n", n);
        printf("Pocet chyb:     %d\n", errors);
        printf("\nStiskni klavesu...\n");
        getchar();
        return 0;
}


/* return num of errors */
int do_mul() {
        static int a, b, c; 
        int result;
        
        result = 0;

        a = get_rand(1, 10, a); 
        c = get_rand(10, MUL_DIV_MAX, c);
        b = c / a;
        
        //d = rand() % 2;
        do {
                printf("\n");
                if (a > b) { 
                        //printf("%d x %d = ", a, b);
                        printf("  %5d\n", a);
                        printf("x %5d\n", b);
                } else {
                        //printf("%d x %d = ", b, a);
                        printf("  %5d\n", b);
                        printf("x %5d\n", a);
                }
                printf("-------\n");
                fgets(s, LINLEN, stdin);
                c = atoi(s);
                if (c != (a * b)) {
                        printf("Spatne!\n");
                        result++;
                }
        } while ((c != (a * b)));

        
        return result;
}


/* return num of errors */
int do_div() {
        static int a, b; 
        int c, result;
        
        result = 0;
        
        a = get_rand(1, 10, a);
        c = get_rand(2, MUL_DIV_MAX, b);
        b = c / a;
        c =  b * a;
        
        do {
                printf("%d / %d = ", c, a);
                fgets(s, LINLEN, stdin);
                b = atoi(s);
                if (b != (c / a)) {
                        printf("Spatne!\n");
                        result++;
                }
        } while (b != (c / a)); 
        
        return result;
}


int get_rand(int min, int max, int old) {
        int result;
        
        do {
                result = (rand() % (max - min + 1)) + min;
        } while (result == old);
        
        return result; 
}
