/*
*       muldiv.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	1.6.2018
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_EXCER 30
#define MUL_DIV_MAX 4

int do_mul();
int do_div();
int get_rand(int min, int max, int old);


int main(void) {
        int errors, i;
        
        srand(time(NULL));
        errors = 0;
        
        for (i = 0; i < NUM_OF_EXCER; i++) {
                if ((rand() % 2) == 0) {
                        errors += do_mul();
                } else {
                        errors += do_div();
                }
        }
        
        printf("\nPocet chyb: %d\n", errors);
        getchar();
        printf("\nStiskni klavesu...\n");
        getchar();
        return 0;
}


/* return num of errors */
int do_mul() {
        static int a, b; 
        int c, d, result;
        
        result = 0;

        a = get_rand(0, 10, a); 
        b = get_rand(2, MUL_DIV_MAX, b);
        
        d = rand() % 2;
        do {
                if (d == 0) { 
                        printf("%d x %d = ", a, b);
                } else {
                        printf("%d x %d = ", b, a);
                }
                scanf("%d", &c);
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
        b = get_rand(2, MUL_DIV_MAX, b);
        c = a * b;
        do {
                printf("%d / %d = ", c, b);
                scanf("%d", &a);
                if (a != (c / b)) {
                        printf("Spatne!\n");
                        result++;
                }
        } while (a != (c / b)); 
        
        return result;
}


int get_rand(int min, int max, int old) {
        int result;
        
        do {
                result = (rand() % (max - min + 1)) + min;
        } while (result == old);
        
        return result; 
}
