/************** errorhandler.c ***************
 * Checks that parenthesis, quotes, and braces 
 * are closed and balanced.
 *********************************************
 */

#include <stdio.h>

int findError();

int main(){
    return findError();
}

int findError(){
    char c;

    int openPar, closePar, quoteDouble, quoteSingle, openCurl, closeCurl,
        openSquare, closeSquare;
    openPar = closePar = quoteDouble = quoteSingle = openCurl = closeCurl = 
        openSquare = closeSquare = 0;

    int slashPrev = 0;          // This checks to see if there was a slash previously

    // Count all of the symbols in the text
    while ((c = getchar()) != EOF){
        // First we need to account for comments
        // Start with multiline
        if (c == '*'){
            // We will handle the slashPrev variable later
            if (slashPrev > 0){
                int starPrev = 0; // Now we have to check for the "*/" sequence 
                while ((c = getchar()) != EOF){
                    if (c == '/' && starPrev != 0)  // This will break us out of the comment
                        break;
                    if (c == '*')
                        starPrev++;
                    else
                        starPrev = 0;
                }
                continue;                           // Continue to make sure no extra getchars happen
            }
        }
        // Now for the single line comments
        if (c == '/'){
            if (slashPrev > 0){
                while ((c = getchar()) != EOF && c != '\n')
                    ;               // To ignore everything in the comment, use null statement
                
                slashPrev = 0;  
                continue;
            }
            else{
                slashPrev++;
                continue;
            }
        }
        else
            slashPrev = 0;

        // For quotes, we will ignore anything inside, and end at a newline or matching quote, 
        // excluding any quotes following a backslash. If the process ended with a newline, 
        // we can throw an error already. If there is a matching quote at the end of this process, 
        // we will increment again.
        if (c == '"'){
            quoteDouble++;

            while ((c = getchar()) != EOF && c != '\n' && c != '"')
                if (c == '\\')                      // If there is a backslash read past the next symbol
                    if ((c = getchar()) != EOF)     // We can check for EOF edge case at the same time
                        break;

            if (c == '\n'){
                printf("\nError: Improper string value\n");
                return -1;
            }

            if (c == '"')
                quoteDouble++;
        }
        if (c == '\''){
            quoteSingle++;

            while ((c = getchar()) != EOF && c != '\n' && c != '\'')
                if (c == '\\')          
                    if ((c = getchar()) != EOF)    
                        break;

            if (c == '\n'){
                printf("\nError: Improper char value\n");
                return -1;
            }

            if (c == '\'')
                quoteSingle++;
            
        }

        if (c == '(')
            openPar++;
        if (c == ')')
            closePar++;            
        if (c == '{')
            openCurl++;
        if (c == '}')
            closeCurl++;
        if (c == '[')
            openSquare++;
        if (c == ']')
            closeSquare++;   
    }

    // Now we have to count everything and check to see that there is an even amount of everything
    if (quoteDouble % 2 != 0){
        printf("\nError: Uneven string quotation marks.\n");
        return -1;
    }
    if (quoteSingle % 2 != 0){
        printf("\nError: Uneven char quotation marks.\n");
        return -1;
    }

    if (openPar != closePar){
        if (openPar < closePar)
            printf("\nError: Extra ')' or missing '(' symbol.\n");
        else
            printf("\nError: Extra '(' or missing ')' symbol.\n");
        return -1;
    }
    if (openCurl != closeCurl){
        if (openCurl < closeCurl)
            printf("\nError: Extra '}' or missing '{' symbol.\n");
        else
            printf("\nError: Extra '{' or missing '}' symbol.\n");
        return -1;
    }
    if (openSquare != closeSquare){
        if (openSquare < closeSquare)
            printf("\nError: Extra ']' or missing '[' symbol.\n");
        else
            printf("\nError: Extra '[' or missing ']' symbol.\n");
        return -1;
    }

    // If the program reaches this point, there are no errors.
    printf("Symbols compiled successfully.\n");
    return 0;
}