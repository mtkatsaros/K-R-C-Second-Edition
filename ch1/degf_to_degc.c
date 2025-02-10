
/**~~~~~~~~~~~~~~~~~degf_to_degc.c~~~~~~~~~~~~~~~~~~~~~
 * This program shows a list of fahrenheit temperatures
 * converted to celsius.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#include <stdio.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   // Lower limit of temperature table
    upper = 300; // Upper limit
    step = 20;   // Step size

    fahr = lower;
    while (fahr <= upper){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius); // Decimal, tab, decimal, newline
        fahr = fahr + step;
    }

    return 0;
}