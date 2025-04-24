/********************* calcmod.c *********************
 * Extends calculator to include modulo functionality.
 *****************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP  100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

// Stack and buffer values
int sp = 0;
double val[MAXVAL];
int bufp = 0;
char buf[BUFSIZE];

int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

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

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}



int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters.\n");
    else
        buf[bufp++] = c;
}