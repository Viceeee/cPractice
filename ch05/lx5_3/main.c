#include <stdio.h>

void strcat(char *, char *);

int main()
{
    char s[] = "hello ";
    char t[] = "world";
    strcat(s, t);
    printf("%s", s);
    return 0;
}

void strcat(char *s, char *t){
    while(*s)
        s++;
    while(*s++ = *t++)
        ;
}




