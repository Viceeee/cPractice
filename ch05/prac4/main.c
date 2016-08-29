#include <stdio.h>

void strcpy(char *, char *);

int main()
{
    char s;
    char t = 10;
    strcpy(&s, &t);

    printf("%d", s);
    return 0;
}

void strcpy(char *s, char *t){
    *s = *t;
}
