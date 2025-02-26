/**~~~~~~~~~~~~~~~~~~any.c~~~~~~~~~~~~~~~~~~~~~~~
 * Retrieves the first index of a string where 
 * any character from the second string occurs.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

 #include <stdio.h>

 int any(char s1[], char s2[]){
    // First we want to find the unique characters of s2
    // I know I don't exactly need to do this, but I thought
    // it would be fun practice :)
    int s2_len = 0;
    for (s2_len = 0; s2[s2_len] != '\0'; s2_len++)
        ;
    char unique[s2_len];
    int unique_count = 0;
    // Now copy the unique characters into the new string
    int isUniqueChar = 1;
    for(int i = 0; i < s2_len; i++){
        for (int j = 0; j < i; j++)
            if(s2[i] == unique[j])
                isUniqueChar = 0;
        // Now we will only copy if it is unique
        if (isUniqueChar){
            unique[unique_count++] = s2[i];
        }
        // Reset the flag otherwise
        else
            isUniqueChar = 1;
    }
    // Null terminate the string
    unique[unique_count] = '\0';

    // Now we can find the index
    for (int i = 0; s1[i] != '\0'; i++){
        for (int j = 0; j < unique_count; j++)
            if (s1[i] == unique[j])
                return i; 
    }

    // If nothing was found, return -1
    return -1;
 }

 int main(){
    char s1[] = "Hello World!";
    char s2[] = "Yo.";

    int location = any(s1, s2);

    if (location > -1)
        printf("\nIndex of character match: %d\n", location);

    else 
        printf("No similar characters found.\n");

    return 0;
 }