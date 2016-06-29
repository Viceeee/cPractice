#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int, char []);
void reverse(char []);

int main()
{
    int n = INT_MAX ;
    char s[100];
    itoa(n, s);
    printf("%s",s);
    return 0;
}

void itoa(int n, char s[]){
    int i, sign;
    sign = n;
    i = 0;
    do{
        s[i++] = abs(n % 10) + '0';
    } while((n /= 10) != 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void itoa2(int n, char s[]){
    int i, sign;
    sign = n;
    if(sign < 0){
        n = -n;
    }
    do{
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
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
