/******************** strrindex.c *******************
 * Returns the rightmost index of a char in a string.
 ****************************************************
 */

 #include <stdio.h>
 #define BUFF 1000

 void readstring(char s[]);

 /**
  * Flow of logic: loop thought each value of the string. Save any indexes that have
  * the same character as t, and overwrite the index stored if an index is already 
  * stored. return the result after null termination or EOF has been reached.
  */
 int strrindex(char s[], char t){
    int result = -1; // Not found case

    for (int i = 0; s[i] != '\0' && s[i] != EOF; i++)
        if(s[i] == t)
            result = i;

    return result;
 }

 int main(){
    char s[BUFF];
    char t;

    printf("Enter target character: ");
    t = getchar();

    printf("\nEnter phrase (%d characters or less):\n", BUFF);
    readstring(s);

    printf("\nIndex of char %c in string: %d\n", t, strrindex(s, t));

    return 0;
 }

 // Helper function to read input data and write to a string
 void readstring(char s[]){
    char c;
    int i = 0;
    while((c = getchar()) != EOF)
        s[i++] = c;
    s[i] = '\0';
 }