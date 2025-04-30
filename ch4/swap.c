/*********** swap.c *************
 * Swaps two arguments of type t.
 ********************************
 */

 #include <stdio.h>

 #define swap(t, x, y) { t temp = x; x = y; y = temp; }

 int main(){

    int x = 5, y = 7;

    printf("Before swap - x: %d y: %d\n", x, y);

    swap(int, x, y);

    printf("After swap - x: %d y: %d\n", x, y);
    return 0;
 }