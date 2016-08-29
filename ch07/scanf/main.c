#include <stdio.h>

int main()
{
    int day, year;
    char a, b, c;
    char s[20] = "hello world";
    char t[20];
    char monthname[20];
    int n = sscanf(s,"%5s", t);
    c = getchar();
    printf("n : %d s: %s\n", n, t);
    printf("%c\n", c);
    return 0;
}
