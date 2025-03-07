/***************** countlwc.c ******************
 * Counts lines, words, and characters in input.
 ***********************************************
 */

#include <stdio.h>

#define IN 1        // Inside a word
#define OUT 0       // Outside a word

int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF){
        nc++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t') // set state to out if whitespace
            state = OUT;
        else if (state == OUT){                 // we also need to check if the state was 
            state = IN;                         // previously out before incrementing word
            nw++;
        }
    }

    printf("\n%d %d %d\n", nl, nw, nc);

    return 0;
}