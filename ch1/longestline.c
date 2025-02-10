/**~~~~~~~~~~~~~~~~longestline.c~~~~~~~~~~~~~~~~~~
 * Prints out the longest line of an input stream.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#include <stdio.h>
#define MAXLINE 1000        // Maximum input line size

int mygetline(char line[], int maxline);  // had to change the function name; conflicted with stdio
void copy(char to[], char from[]);

// Print longest input line
int main(){
    int len;
    int max;

    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0)
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("\n%s", longest);

    return 0;
}

// helper function to read a full line; my version compared to stdio's version added after the book.
int mygetline(char line[], int maxline){
    int c, i;
    for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}

// helper function that copies from into to
void copy(char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}