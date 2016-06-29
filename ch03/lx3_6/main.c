#include <stdio.h>
#include <limits.h>
#include <math.h>

void itoa(int n, char s[], int w);
void reverse(char []);

int main()
{
    int n = -139 ;
    char s[100];
    itoa(n, s, 8);
    printf("%s",s);
    return 0;
}

void itoa(int n, char s[], int w){
    int i, sign;
    sign = n;
    i = 0;
    do{
        s[i++] = abs(n % 10) + '0';
    } while((n /= 10) != 0);
    if(sign < 0)
        s[i++] = '-';
    while(i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

