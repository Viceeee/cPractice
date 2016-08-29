#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int c;
    printf("%s\n", argv[1]);
    if(strcmp(argv[1], "lower") == 0)
        while((c = getchar()) != EOF)
            putchar(tolower(c));
    else
        while((c = getchar()) != EOF)
            putchar(toupper(c));
    return 0;
}
