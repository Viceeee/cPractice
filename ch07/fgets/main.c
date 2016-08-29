#include <stdio.h>

char *fgets1(char *, int, FILE *);

int main()
{
    char line[100];
    char *s = fgets1(line, 10, stdin);
    printf("%s\n", line);
    printf("s: %s\n", s);
    return 0;
}

char *fgets1(char *s, int n, FILE *iop){
    register int c;
    register char *cs;
    cs = s;
    while(--n > 0 && (c = getc(iop)) != EOF)
        if((*cs++ = c) == '\n')
            break;
    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}
