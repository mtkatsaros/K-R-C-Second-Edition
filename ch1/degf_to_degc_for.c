/**************** degf_to_degc_for.c ******************
 * This program shows a list of fahrenheit temperatures
 * converted to celsius. This time with a for loop.
 ******************************************************
 */
#include <stdio.h>

#define LOWER 0    // lower limit of the table
#define UPPER 300  // upper limit of the table
#define STEP  20   // step size

int main(){
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));

    return 0;
}