#include <stdio.h>
#include <stddef.h>
#include <string.h>

int strlen1(char *);
int strlen2(char *);
void strcpy1(char *, char *);
void strcpy2(char *, char *);
void strcpy3(char *, char *);
int strcmp1(char *s, char *t);
int strcmp2(char *s, char *t);

int main()
{
    char *t = "hello world";
    char *s = malloc(sizeof(char *));
    strcpy(s, t);
    printf("%s", s);
    //printf("%d", n);
    return 0;
}

int strlen1(char *s){
    int n;
    for(n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int strlen2(char *s){
    char *p = s;
    while(*p != '\0')
        p++;
    return p - s;
}

void strcpy1(char *s, char *t){
    int i;
    i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

void strcpy2(char *s, char *t){
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

void strcpy3(char *s, char *t){
    while(*s++ = *t++)
        ;
}

int strcmp1(char *s, char *t){
    int i;
    for(i = 0; s[i] == t[i]; i++)
        if(s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int strcmp2(char *s, char *t){
    int i;
    for(i = 0; *s == *t; s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}


