/**~~~~~~~~~~~~~~~bitcount.c~~~~~~~~~~~~~~~~~
 * Counts the amount of 1 bits in an integer.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

 #include <stdio.h>

 /* The book asks the question "In a two's complement number system, 
    x &= (x-1) deletes the rightmost 1-bit in x. Explain why." This is
    because the 1-bit at the end will flip to zero, and since there 
    is an AND operation with it, the zeros will remain zero
    and any other 1s will remain.
 */

 int bitcount(unsigned x){
    // Edge case: If x is 0 return 0 
    if (x == 0)
        return 0;

    int b = 1;
    // This states that if removing the rightmost bit still gives a value
    // greater than zero, increment.
    while(x &= (x-1))
        b++;

    return b;
 }

 int main(){
    unsigned word = 23;

    printf("Number of 1-bits in integer %d: %d\n", word, bitcount(word));
    return 0;
 }