#include <stdio.h>
#include <string.h>
#include <limits.h>

void itob(int, char [], int);
void reverse(char []);

int main()
{
    int n = INT_MAX;
    char s[100];
    int b = 12;
    itob(n, s, b);
    printf("%s",s);
    return 0;
}

void itob(int n, char s[], int b){
    int i, j, sign;
    sign = n;
    i = 0;
    do{
        j = abs(n % b);
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while((n /= b) != 0);
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
