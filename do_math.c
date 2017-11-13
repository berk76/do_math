/*
*       do_math.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	30.9.2016
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int do_add();
int do_sub();
int do_mul();
int do_div();


int main(void) {
        int c, result, add, sub, mul, div;
        
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
                printf("Scitani   %d\n", add);
        if (sub != 0)
                printf("Odcitani  %d\n", sub);
        if (mul != 0)
                printf("Nasobeni  %d\n", mul);
        if (div != 0)
                printf("Deleni    %d\n", div);
        
        getchar();
        printf("\nStiskni klavesu...\n");
        getchar();
        
        return 0;
}


int do_add() {
        int i, a, b, c, result, max;
        
        max = 10;
        result = 9;
        for (i = 0; i < 10; i++) {
                a = rand() % max + 1;
                b = rand() % max + 1;
                if (a > b) {
                        a -= b;
                } else {
                        b -= a;
                }
                printf("%d + %d = ", a, b);
                scanf("%d", &c);
                if (c == (a + b)) {
                        result--;
                } else {
                        printf("Spatne!\n");
                }
        }
        
        return (result / 2) + 1;
}


int do_sub() {
        int i, a, b, c, result, max;
        
        max = 10;
        result = 9;
        for (i = 0; i < 10; i++) {
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
                if (a == (c - b)) {
                        result--;
                } else {
                        printf("Spatne!\n");
                }
        }
        
        return (result / 2) + 1;
}


int do_mul() {
        int i, a, b, c, result;
        
        result = 9;
        for (i = 0; i < 10; i++) {
                a = rand() % 11;
                b = rand() % 11;
                printf("%d x %d = ", a, b);
                scanf("%d", &c);
                if (c == (a * b)) {
                        result--;
                } else {
                        printf("Spatne!\n");
                }
        }
        
        return (result / 2) + 1;
}


int do_div() {
        int i, a, b, c, result;
        
        result = 9;
        for (i = 0; i < 10; i++) {
                a = (rand() % 10) + 1;
                b = (rand() % 10) + 1;
                c = a * b;
                printf("%d / %d = ", c, b);
                scanf("%d", &a);
                if (a == (c / b)) {
                        result--;
                } else {
                        printf("Spatne!\n");
                }
        }
        
        return (result / 2) + 1;
}
