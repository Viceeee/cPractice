#include <stdio.h>
#include <string.h>

int strend1(char [], char []);
int strend2(char *, char *);

int main()
{
    char s[] = "hello world";
    char t[] = "rd";
    int i = strend2(s, t);
    printf("%d", i);
    return 0;
}

int strend1(char s[], char t[]){
    int len1, len2;
    len1 = strlen(s);
    len2 = strlen(t);
    while(len2 >= 0 && t[len2] == s[len1]){
        len2--;
        len1--;
    }
    if(len2 == -1)
        return 1;
    else
        return 0;
}

int strend2(char *s, char *t){
    char *bs = s;
    char *bt = t;
    while(*s)
        s++;
    while(*t)
        t++;
    while(*t == *s){
        t--;
        s--;
        if(t == bt || s == bs)
            break;
    }
    if(*t == *s && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}
