/******************** power.c *******************
 * Raises a given base integer to the n-th power.
 ************************************************
 */

#include <stdio.h>

int power(int m, int n);

int main() {
    int i; 

    for (i = 0; i < 10; i++)
        printf("%d %4d %6d\n", i, power(2, i), power(-3, i));

    return 0;
}

int power(int m, int n){
    int result = 1;
    for (int i = 0; i <= n; i++){
        result *= m;
    }

    return result;
}