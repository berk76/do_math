/*
*       maratgon.c
*	Jaroslav Beran - jaroslav.beran@gmail.com
*	25.12.2016
*	redistributable under the terms of the GNU/GPLv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINLEN 10

int do_add(int max);
int do_sub(int max);
int get_user_input();


int main(void) {
        int i, wrong, max;
        
        wrong = 0;
        max = 20;
        srand(time(NULL));
        
        for (i = 0; i < 100; i++) {
                if (rand() % 2 == 0) {
                        wrong += do_add(max);
                } else {
                        wrong += do_sub(max);
                }
                printf("Celkem = %d, Chyb = %d\n", i + 1, wrong);
        }
        
        return 0;
}


int do_add(int max) {
        int a, b, c, result, result2;
        
        result = 0;
        a = rand() % (max + 1);
        b = rand() % (max + 1);
        
        if (a > b) {
                a -= b;
        } else {
                b -= a;
        }
        
        do {
                printf("%d + %d = ", a, b);
                c = get_user_input();
                if (c == (a + b)) {
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


int do_sub(int max) {
        int i, a, b, c, result, result2;
        
        result = 0;
        a = rand() % (max + 1);
        b = rand() % (max + 1);
        
        if (a > b) {
                c = a;
        } else {
                c = b;
                b = a;
        }
        
        do {
                printf("%d - %d = ", c, b);
                a = get_user_input();
                if (a == (c - b)) {
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


int get_user_input() {
        char s[LINLEN];
        
        fgets(s, LINLEN, stdin);
        return atoi(s); 
}
