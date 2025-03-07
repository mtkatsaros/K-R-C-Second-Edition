/**************** lower.c ******************
 * Converts string to all lower case values.
 *******************************************
 */

 #include <stdio.h>

 // Either returns the difference between lower and uppercase ascii added to the 
 // character value if it's uppercase, or just the character itself otherwise
 char lower(char c){
    return (c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c;
 }

 int main(){
    printf("Enter a character: ");
    char c = getchar();

    printf("\nResult: %c\n", lower(c));

    return 0;
 }