/************* atof.c ***************
 * Writes a string value to a double.
 ************************************
 */

 #include <stdio.h>
 #include <ctype.h>

 double atof(char s[]){
    double val, power, exp, exp_coeff;
    int i, sign, j;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] = '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // Now we have to check for an 'e' and handle that case
    while (isspace(s[i]))
        i++;
    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        while (isspace(s[i]))
            i++;
        exp_coeff = (s[i] == '-') ? 0.1 : 10.0;
        if (s[i] == '-')
            i++;
        for (j = 0; isdigit(s[i]); i++)
            j = 10 * j + (s[i] - '0');
        for (exp = 1.0; j > 0; j--)
            exp *= exp_coeff;
    }

    return sign * val / power * exp;

 }

 int main(){
    char s[] = "  -3725.4e-3";

    printf("Result: %f\n", atof(s));
    return 0;
 }