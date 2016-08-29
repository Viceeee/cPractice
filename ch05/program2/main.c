#include <stdio.h>
#include <stdlib.h>

int main()
{
    double v1, v2;
    char *s1 = "12";
    char *s2 = "189.90";
    v1 = atof(s1);
    v2 = atof(s2);
    printf("%s %f\n", s1, v1);
    printf("%s %f", s2, v2);
    return 0;
}
