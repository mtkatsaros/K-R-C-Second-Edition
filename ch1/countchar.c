/******** countchar.c ********
 * Counts characters in input.
 *****************************
 */
#include <stdio.h>

int main(){
    long nc;

    // You can just put a semicolon if you only want to increment.
    // Makes sense, but something I never thought about!
    for (nc = 0; getchar() != EOF; nc++)
        ; 

    printf("%ld\n", nc); // "%ld" for longs

    return 0;
}