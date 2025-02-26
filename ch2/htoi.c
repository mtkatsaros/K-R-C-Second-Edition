/**~~~~~~~~~~~~~~~~~~htoi.c~~~~~~~~~~~~~~~~~~~~~~
 * Converts hexidecimal values to decimal values.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#include <stdio.h>

int mypow(int b, int n);

int htoi(char s[]){
    int i = 0, result = 0, n = 0;

    // If we have the optional 0x, skip those values
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    // First we figure out the size of the line (+ i in case i starts at 2)
    while (s[n + i] != '\0')
        n++;

    // Now for the calculation
    while (s[i] != '\0'){
        if (s[i] >= '0' && s[i] <= '9')
            result += (s[i] - '0') * mypow(16, n - 1);
        else if (s[i] >= 'a' && s[i] <= 'f')
            result += (s[i] - 'a' + 10) * mypow(16, n - 1);
        else if (s[i] >= 'A' && s[i] <= 'F')
            result += (s[i] - 'A' + 10) * mypow(16, n - 1);

        i++;
        n--;
    }

    return result;
}

int main(){
    char hex[] = "0xF13";
    printf("%d\n", htoi(hex));
    return 0;
}

// Basic power function for positive values
int mypow(int b, int n){
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= b;
    return result;
}

/**
 * I had to code this again because I bricked my previous system without backing up my 
 * Chapter 2 progress. I skipped the first two ch2 exercises this time around since 
 * they were very intuitive, but I wanted to do this one again to have for my notes. 
 * On the previous version, I also implemented readline, but this time around I did not
 * for the sake of time and moving on to the next topic.
*/