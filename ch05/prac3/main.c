#include <stdio.h>

void print(char *s[]);
int main()
{
    char *s[] = {"abc", "def", "ghi"};
    //printf("%c", *++s[1]);
    print(s);
    return 0;
}

void print(char *s[]){
    *++s = "rty";
    printf("%s", *s);
}
