#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

void minprintf(char *, ...);

int main()
{
    char *s = "hello world";
    int num = 1000;
    //printf("%x\n", num);
    minprintf("%20.10s\n", s);
    return 0;
}

void minprintf(char *fmt, ...){
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;

    char localfmt[20];
    int i = 0;
    va_start(ap, fmt);
    for(p = fmt; *p; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        localfmt[i++] = *p++;
        while(isalnum(*p) || *p == '.')
            localfmt[i++] = *p++;
        localfmt[i] = '\0';
       // printf("%s\n", localfmt);

        switch(*--p){
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                printf(localfmt, ival);
                break;
            case 'x':
            case 'X':
            case 'u':
            case 'o':
                uval = va_arg(ap, unsigned);
                printf(localfmt, uval);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf(localfmt, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf(localfmt, sval);
                break;
            default:
                printf(localfmt);
                break;
        }
    }
    va_end(ap);
}
