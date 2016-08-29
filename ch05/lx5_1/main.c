#include <stdio.h>
#define SIZE 10
int getint(int *);

int main()
{
    int num;
    int t = getint(&num);
    printf(" %d  %d", num, t);
    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn){
    int c, d, sign;
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-'){
        d = c;
        if(!isdigit(c = getch())){
            if(c != EOF)
                ungetch(c);
            ungetch(d);
            return d;
        }
    }
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
