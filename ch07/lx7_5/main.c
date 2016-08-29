#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER '0'
#define MAXWORD 100
int getop(char *);
void push(double );
double pop(void);

int main()
{
    int c;
    double num;
    char s[MAXWORD];
    while((c = getop(s)) != EOF){
        switch(c){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            num = pop() + pop();
            push(num);
            break;
        case '-':
            num = pop();
            num = pop() - num;
            push(num);
            break;
        case '*':
            num = pop() * pop();
            push(num);
            break;
        case '/':
            num = pop();
            if(num == 0.0)
                printf("error: divider can't be zero\n");
            num = pop() / num;
            push(num);
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

#define MAXVAL 100
double val[MAXVAL];
int sp = 0;

void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}
