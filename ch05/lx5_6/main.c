#include <stdio.h>
#include <math.h>
#include "func.h"

#define MAXOP 100
#define NUMBER '0'

int main()
{
    /*
    char s[] = "data structure and algorithm";
    char t[] = "and";
    int n = strindex(s, t);
    printf("%d\n", n);
    */
    char s2[] = "120.0";
    double n2 = atof(s2);
    printf("%f\n", n2);


    int type;
    double op2;
    char s[MAXOP];
    while((type = getop(s)) != EOF){
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

    return 0;
}
