/**************** rightrot.c ****************
 * Rotates an integer to the right by n bits.
 ********************************************
 */

 #include <stdio.h>

 // This problem requires a lot of prior computer science knowledge of binary arithmetic 
 int rightrot(int x, unsigned n){
   const int WORD_SIZE = sizeof(x) * 8;

   // We want to take shift the integer by n to the right, and then OR that value with
   // the remaining amount of bits in the word attached to the front.
   return (x >> n) | (x << (WORD_SIZE - n));
 }

 int main(){
    int x = 32;
    unsigned n = 2;

    printf("%d rotated right by %d bits: %d\n", x, n, rightrot(x, n));
    return 0;
 }