/**~~~~~~~~~~~~itoa.c~~~~~~~~~~~~~~~~
 * Writes integer values to a string.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

 #include <stdio.h>
 #include <string.h>

 void reverse(char s[]);

 void itoa(int n, char s[], int width) {
    int i, sign;

    if ((sign = n) < 0)
        n =  -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0 || i < width);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
 }

 int main(){
    int n = -327;
    char s[1000];
    int width = 7;

    itoa(n, s, width);
    printf("%d written with minimum width %d: %s\n", n, width, s);

    return 0;
 }

 // Function to reverse a string
 void reverse(char s[]){
    int c, i, j;

    // Use strlen from string.h instead of sizeof calculation
    for (i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
 }