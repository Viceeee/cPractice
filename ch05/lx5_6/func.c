#include <stdio.h>

int getline(char *s, int lim){
    int c;
    char *t = s;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if(c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

#include <ctype.h>
int atoi(char *s){
    int num, sign;
    for( ; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if(*s == '+' || *s == '-')
        s++;
    for(num = 0; isdigit(*s); s++)
        num = 10 * num + *s - '0';
    return sign * num;
}

#define abs(x) ((x) < 0 ? -(x) : (x))
void itoa(int n, char *s){
    void reverse(char *);

    int sign;
    char *t = s;
    sign = n;
    do{
        *s++ = abs(n % 10) + '0';
    }
    while((n /= 10) != 0);
    if(sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

#include <string.h>
void reverse(char *s){
    int c;
    char *t;
    for(t = s + (strlen(s) - 1); s < t; s++, t--){
        c = *s;
        *s = *t;
        *t = c;
    }
}

int strindex(char *s, char *t){
    char *b = s;
    char *p, *r;
    for( ; *s != '\0'; s++){
        for(p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if(r > t && *r == '\0')
            return s - b;
    }
    return -1;
}

#include <ctype.h>
double atof(char *s){
    double n, power;
    int sign;
    for(; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if(*s == '+' || *s == '-')
        s++;
    for(n = 0.0; isdigit(*s); s++)
        n = 10.0 * n + (*s - '0');
    if(*s == '.')
        s++;
    for(power = 1.0; isdigit(*s); s++){
        power *= 10.0;
        n = 10.0 * n + (*s - '0');
    }
    return sign * n / power;
}

#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

int getop(char *s){
    int c;

    while((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    if(isdigit(c))
        while(isdigit(*++s = c = getch()))
            ;
    if(c == '.')
        while(isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
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
