/*
*       plusmin.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	1.6.2018
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_EXCER 30
#define ADD_SUB_MAX 100

int do_add();
int do_sub();
int get_rand(int min, int max, int old);


int main(void) {
        int errors, i;
        
        srand(time(NULL));
        errors = 0;
        
        for (i = 0; i < NUM_OF_EXCER; i++) {
                if ((rand() % 2) == 0) {
                        errors += do_add();
                } else {
                        errors += do_sub();
                }
        }
        
        printf("\nPocet chyb: %d\n", errors);
        getchar();
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
        printf("%d + %d = ", a, b);
        scanf("%d", &c);
        if (c != (a + b)) {
                printf("Spatne!\n");
                result++;
        }
        
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
        printf("%d - %d = ", c, b);
        scanf("%d", &a);
        if (a != (c - b)) {
                printf("Spatne!\n");
                result++;
        }
        
        return result;
}


int get_rand(int min, int max, int old) {
        int result;
        
        do {
                result = (rand() % (max - min + 1)) + min;
        } while (result == old);
        
        return result; 
}
