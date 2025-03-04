/**~~~~~~~~~~~~~~escape.c~~~~~~~~~~~~~~~~
 * Converts escape sequences to character 
 * representations and vice versa.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

 #include <stdio.h>

 void escape(char s[], const char t[]){
    int j = 0;
    // Loop through each value of t. if there is a '\', check the escape sequences.
    for (int i = 0; t[i] != '\0' && t[i] != EOF; i++){
        if (t[i] == '\\'){
            switch (t[i+1]){
                case 'a':
                    s[j] = '\a';
                    i++;
                    break;
                case 'b':
                    s[j] = '\b';
                    i++;
                    break;
                case 'f':
                    s[j] = '\f';
                    i++;
                    break;
                case 'n':
                    s[j] = '\n';
                    i++;
                    break;
                case 'r':
                    s[j] = '\r';
                    i++;
                    break;
                case 't':
                    s[j] = '\t';
                    i++;
                    break;
                case 'v':
                    s[j] = '\v';
                    i++;
                    break;
                case '\\':
                    s[j] = '\\';
                    i++;
                    break;
                case '\'':
                    s[j] = '\'';
                    i++;
                    break;
                case '\"':
                    s[j] = '\"';
                    i++;
                    break;
                default:
                    break;
            }
        }
        else
            s[j] = t[i];
        j++;
    }
    // Now null terminate it 
    s[j] = '\0';

 }

 void unescape(char s[], const char t[]){
    int j = 0;
    // Same as the last one, just reverse logic!
    for (int i = 0; t[i] != '\0' && t[i] != EOF; i++){
        switch (t[i]){
            case '\a':
                s[j++] = '\\';
                s[j] = 'a';
                break;
            case '\b':
                s[j++] = '\\';
                s[j] = 'b';
                break;
            case '\f':
                s[j++] = '\\';
                s[j] = 'f';
                break;
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\r':
                s[j++] = '\\';
                s[j] = 'r';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\v':
                s[j++] = '\\';
                s[j] = 'v';
                break;
            case '\\':
                s[j++] = '\\';
                s[j] = '\\';
                break;
            case '\'':
                s[j++] = '\\';
                s[j] = '\'';
                break;
            case '\"':
                s[j++] = '\\';
                s[j] = '\"';
                break;
            default:
                s[j] = t[i];
                break;
        }
        
        j++;
    }
    // Now null terminate it 
    s[j] = '\0';

 }

int main(){
    char original[] = "\\a This is a test.  \\b I want \\n to use \\t as many escapes \\\\as possible\\vI say \\'hello\\' and \\\"hi\\\"";
    int len = sizeof(original) / sizeof(original[0]);
    char copy[len];
    char copy_of_copy[len];

    // Now we make our calculations
    escape(copy, original);
    unescape(copy_of_copy, copy);

    printf("Original: %s\n", original);
    printf("Escape conversion: %s\n", copy);
    printf("Reverted string: %s\n", copy_of_copy);

    return 0;
}