/**~~~~countwhitespace.c~~~~~~
 * Counts whitespace in input.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#include <stdio.h>

int main() {
    int c, nl, t, s;  // Track new lines, tabs and spaces

    nl = 0;
    t = 0;
    s = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n')
            nl++;
        if (c == '\t')
            t++;
        if (c == ' ')
            s++;
    }
    printf("\nNewline count: %d\nTab count: %d\nSpace count: %d\n", nl, t, s);

    return 0;
}