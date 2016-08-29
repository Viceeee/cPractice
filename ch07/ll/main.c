#include <stdio.h>
#include <stdlib.h>

void func(char *);

int main()
{
    char s[20];
    func(s);
    printf("%s\n", s);
    return 0;
}

void func(char *s){
    s = "hello, world";
    *s++ = 'u';
    *s = '\0';
}
