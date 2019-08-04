/*
*       do_math.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	30.9.2016
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_EXCER 30
#define ADD_SUB_MAX 10
#define MUL_DIV_MAX 4

int do_add();
int do_sub();
int do_mul();
int do_div();

int get_rand(int min, int max, int old);


int main(void) {
        int c, add, sub, mul, div;
        
        add = 0;
        sub = 0;
        mul = 0;
        div = 0;
        srand(time(NULL));
        
        do {
                printf("\nMatematika\n");
                printf("==========\n\n");
                printf("1) Scitani\n");
                printf("2) Odcitani\n");
                printf("3) Nasobeni\n");
                printf("4) Deleni\n\n");
                printf("5) Konec\n\n");
                
                c = getchar();
                
                switch (c) {
                        case '1':
                                add = do_add();
                                break;
                        case '2':
                                sub = do_sub();
                                break;
                        case '3':
                                mul = do_mul();
                                break;
                        case '4':
                                div = do_div();
                                break;
                }
        } while (c != '5');
        
        printf("\nVysvedceni\n");
        printf("==========\n\n");
        if (add != 0)
                printf("Scitani   %d chyb\n", add);
        if (sub != 0)
                printf("Odcitani  %d chyb\n", sub);
        if (mul != 0)
                printf("Nasobeni  %d chyb\n", mul);
        if (div != 0)
                printf("Deleni    %d chyb\n", div);
        
        getchar();
        printf("\nStiskni klavesu...\n");
        getchar();
        
        return 0;
}


int do_add() {
        int i, a, b, c, result, max;
        
        max = ADD_SUB_MAX;
        result = 0;
        for (i = 0; i < NUM_OF_EXCER; i++) {
                a = rand() % max + 1;
                b = rand() % max + 1;
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
        }
        
        return result;
}


int do_sub() {
        int i, a, b, c, result, max;
        
        max = ADD_SUB_MAX;
        result = 0;
        for (i = 0; i < NUM_OF_EXCER; i++) {
                a = rand() % max + 1;
                b = rand() % max + 1;
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
        }
        
        return result;
}


int do_mul() {
        int i, a, b, c, d, result;

        a = 0;
        b = 0;
        result = 0;
        for (i = 0; i < NUM_OF_EXCER; i++) {
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
        }
        
        return result;
}


int do_div() {
        int i, a, b, c, result;

        a = 0;
        b = 0;
        result = 0;
        for (i = 0; i < NUM_OF_EXCER; i++) {
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
