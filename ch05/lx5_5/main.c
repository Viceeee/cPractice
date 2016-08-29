#include <stdio.h>
#include <stdlib.h>

void strncpy1(char *, char *, int);
void strncat1(char *, char *, int);
int strncmp1(char *, char *, int);

int main()
{
    char s1[20];
    char t1[20] = "hello world";
    strncpy1(s1, t1, 8);
    printf("%s\n",s1);

    char s2[] = "hello ";
    char t2[] = "world is";
    strncat1(s2, t2, 7);
    printf("%s\n", s2);


    char s3[] = "hello";
    char t3[] = "hell";
    int n = strncmp1(s3, t3, 4);
    printf(" %d", n);

    return 0;
}

void strncpy1(char *s, char *t, int n){
    while(*t && n-- > 0)
        *s++ = *t++;
    *s = '\0';
}

void strncat1(char *s, char *t, int n){
    while(*s)
        s++;
    while(*t && n-- > 0)
        *s++ = *t++;
    *s = '\0';
}

int strncmp1(char *s, char *t, int n){
    for(; *s == *t; s++, t++)
        if(*s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}
