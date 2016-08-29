#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

void minprintf(char *, ...);

int main()
{
    char *s = "hello world";
    minprintf("%15.10s", s);
    return 0;
}

void minprintf(char *fmt, ...){
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    int c, minus = 1, d = 1;
    double num = 0.0;
    va_start(ap, fmt);
    for(p = fmt; *p; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        if((c = *++p) == '-')
            minus = -1;
        else if(isdigit(c))
            while(isdigit(c)){
                num = num * 10 + c - '0';
                c = *++p;
            }
        if(*p++ == '.')
            while(isdigit(*p)){
                num = num * 10 + *p - '0';
                p++;
                d *= 10;
            }
        else
            p--;
        num = num / d;
        printf("%f\n", num);
        switch(*p){
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
