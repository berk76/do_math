#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINLEN 100

int get_user_input() {
        char s[LINLEN];
        
        fgets(s, LINLEN, stdin);
        return atoi(s); 
}


int do_add() {
        int i, a, b, c, n1, n2, result, max;
        
        max = 10;
        result = 0;
        for (i = 0; i < 10; i++) {
                a = rand() % max;
                b = rand() % max;
                n1 = ((rand() % (max - 1)) + 1) * 10;
                n2 = ((rand() % (max - 1)) + 1) * 10;
                
                
                if (a > b) {
                        a -= b;
                } else {
                        b -= a;
                }
                
                if (n1 == n2) {
                        n1 = n2 = 10;
                } else {
                        if (n1 > n2) {
                                n1 -= n2;
                        } else {
                                n2 -= n1;
                        }
                }
                
                do {
                        printf("%d + %d = ", a + n1, b + n2);
                        c = get_user_input();
                        if (c != (a + b + n1 + n2)) {
                                printf("Spatne!\n");
                                result++;
                        }
                } while (c != (a + b + n1 + n2));
        }
        
        return result;
}


int do_sub() {
        int i, a, b, c, n1, n2, n3, result, max;
        
        max = 10;
        result = 0;
        for (i = 0; i < 10; i++) {
                a = rand() % max;
                b = rand() % max;
                n1 = ((rand() % (max - 1)) + 1) * 10;
                n2 = ((rand() % (max - 1)) + 1) * 10;
                
                if (a > b) {
                        c = a;
                } else {
                        c = b;
                        b = a;
                }
                
                if (n1 > n2) {
                        n3 = n1;
                } else {
                        n3 = n2;
                        n2 = n1;
                }
                
                do {
                        printf("%d - %d = ", c + n3, b + n2);
                        a = get_user_input();
                        if (a != ((c +n3) - (b + n2))) {
                                printf("Spatne!\n");
                                result++;
                        } 
                } while (a != ((c +n3) - (b + n2)));
        }
        
        return result;
}

int main(void) {
        int res;
        
        srand(time(NULL));
        
        res = do_add();
        printf("Pocet chyb: %d\n\n", res);
        
        res = do_sub();
        printf("Pocet chyb: %d\n\n", res);
        
        printf("\nStiskni klavesu...\n");
        getchar();
        
        return 0;
}
