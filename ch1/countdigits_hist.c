/**~~~~~~~~countdigits_hist.c~~~~~~~~~
 * Counts digits in input and displays 
 * a histogram for digit results.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#include <stdio.h>

int main() {
    int c, i, j, nwhite, nother, max;   // keep track of the maximum value as well
    int ndigit[10];

    max = -1;                           // Max will never be lower than 0 after calculating
    nwhite = nother = 0;
    for(i = 0; i < 10; i++)
        ndigit[i] = 0;
    
    while ((c = getchar()) != EOF){
        if (c >= '0' && c <= '9')
            ndigit[c-'0']++;  // subtract '0' to convert the char to an integer value
        else if (c == ' ' || c == '\n' || c == '\t')
            nwhite++;
        else 
            nother++;
    }

    // Determine the maximum value 
    for (i = 0; i < 10; i++){
        if(ndigit[i] > max)
            max = ndigit[i];
    }

    /**
     * Something to consider about this histgram: I figured that nobody is going to have the
     * mental fortitude to write a thousand or more of a single digit, so I limited the y axis 
     * label to 3 units wide. If I wanted to scale the project, I would have to increase the 
     * printf width for the labels.
     */
    printf("\ndigits =\n");
    for(i = max; i >= 0; i--){
        if(i != 0)                  // Y axis label
            printf("%3d", i);
        else
            printf("   ");
        for(j = 0; j < 10; j++){
            if (i == 0)             // X axis label
                printf(" %d", j);
            else if (ndigit[j] >= i)
                printf(" |");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("white space = %d, other = %d\n", nwhite, nother);
    return 0;
}