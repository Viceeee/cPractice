#include <stdio.h>
#include <stdlib.h>

int getfloat(float *);

int main()
{
    float n;
    int c = getfloat(&n);
    printf(" %f %d", n, c);
    return 0;
}

#include <ctype.h>

int getfloat(float * pn){
    int getch(void);
    void ungetch(int);

    int c, d, sign;
    float power;
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-'){
        d = c;
        if(!isdigit(c = getchar())){
            if(c != EOF)
                ungetch(c);
            ungetch(d);
            return d;
        }
    }
    for(*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if(c == '.')
        c = getch();
    for(power = 1.0; isdigit(c); c = getch()){
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;
    if(c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 1000

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp > BUFSIZE)
        printf("too many buffer data");
    else
        buf[bufp++] = c;
}
