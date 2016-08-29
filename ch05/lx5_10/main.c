#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char [], char *);
void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    while(--argc > 0 && (type = getop(s, *++argv)) != EOF ){
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
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
    printf("\t%.8g\n", pop());
    return 0;
}

#include <ctype.h>

int getop(char s[], char arg[]){
    int i, c;

    while((s[0] = c = *arg++) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = *arg))
            arg++;
    if(c == '.')
        while(isdigit(s[++i] = c = *arg))
            arg++;
    s[i] = '\0';

    return NUMBER;
}

