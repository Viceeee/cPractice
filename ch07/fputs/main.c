#include <stdio.h>
#include <stdlib.h>


int main()
{
    int fputs1(char *, FILE *);
    char *s = "hello world";
    fputs1(s, stdout);
    return 0;
}

int fputs1(char *s, FILE *iop){
    int c;
    while(c = *s++)
        putc(c, iop);
    return ferror(iop) ? EOF : 1;
}
