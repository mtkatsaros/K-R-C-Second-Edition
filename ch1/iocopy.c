/********* iocopy.c ********
 * Copies input into output.
 ***************************
 */

#include <stdio.h>

int main() {
    int c;

    printf("EOF value: %d\n", EOF);  // Let's see what EOF value is!

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}