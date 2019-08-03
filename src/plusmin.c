/*
*       plusmin.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	1.6.2018
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ADD_SUB_MAX 1000
#define LINLEN 80

char s[LINLEN];

int do_add();
int do_sub();
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
                        errors += do_add();
                } else {
                        errors += do_sub();
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
int do_add() {
        static int a, b;
        int c, result, max;
        
        max = ADD_SUB_MAX;
        result = 0;

        a = get_rand(10, ADD_SUB_MAX, a);
        b = get_rand(10, ADD_SUB_MAX, b);
        if (a > b) {
                a -= b;
        } else {
                b -= a;
        }
        
        do {
                printf("%d + %d = ", a, b);
                fgets(s, LINLEN, stdin);
                c = atoi(s);
                if (c != (a + b)) {
                        printf("Spatne!\n");
                        result++;
                }
        } while (c != (a + b));
               
        return result;
}


/* return num of errors */
int do_sub() {
        static int a, b;
        int c, result, max;
        
        max = ADD_SUB_MAX;
        result = 0;
        
        a = get_rand(10, ADD_SUB_MAX, a);
        b = get_rand(10, ADD_SUB_MAX, b);
        if (a > b) {
                c = a;
        } else {
                c = b;
                b = a;
        }
        
        do {
                printf("%d - %d = ", c, b);
                fgets(s, LINLEN, stdin);
                a = atoi(s);
                if (a != (c - b)) {
                        printf("Spatne!\n");
                        result++;
                }
        } while (a != (c - b));
        
        return result;
}


int get_rand(int min, int max, int old) {
        int result;
        
        do {
                result = (rand() % (max - min + 1)) + min;
        } while (result == old);
        
        return result; 
}
