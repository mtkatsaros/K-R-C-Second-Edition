/*************** calc_no_unget.c ****************
 * Calculator without the extra character buffer.
 ************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP  100
#define NUMBER '0'
#define MAXVAL 100

// Stack and buffer values
int sp = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);

// Reverse Polish calculator
int main(){

    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch(type){

            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: Divide by zero.\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else 
                    printf("Error: Divide by zero.\n");
                break;
            case '\n':
                printf("Result: %.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;

        }
    }


    return 0;
}

void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: Full stack. Cannot push more values.\n");
}

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: Empty stack. Cannot retrieve more values.\n");
        return 0.0;
    }
}

int getop(char s[]){
    int i, c;
    static int prevc = 0;

    // We need to check if there are any characters in storage from a previous call
    if (prevc != 0){
        c = prevc;
        prevc = 0;
    }
    else    
        c = getchar();

    while ((s[0] = c) == ' ' || c == '\t')
        c = getchar();
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;
    if(c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    // Now we go back using our static variable
    if (c != EOF)
        prevc = c;
    return NUMBER;
}

