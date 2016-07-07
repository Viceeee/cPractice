#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main()
{
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

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push 函数：把f压入到值栈中*/
void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop函数：弹出并返回栈顶的值*/
double pop(void){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

#define MAXLINE 100

int getline(char line[], int limit);

int li = 0;
char line[MAXLINE];

int getop(char s[]){
    int i, c;

    if(line[li] == '\0')
        if(getline(line, MAXLINE) == 0)
            return EOF;
        else
            li = 0;
    while((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = line[li++]))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}

int getline(char line[], int limit){
    int c, i;
    i = 0;
    while(--limit > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if(c = '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}
