#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
    char s[10];
    int n = 12345;
    itoa(n, s);
    printf("%s",s);
    return 0;
}

void itoa(int n, char s[]){
    static int i;
    if(n / 10)
        itoa(n / 10, s);
    else{
        i = 0;
        if(n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

void itoa2(int n, char s[]){

    void reverse(char []);

    int i, sign;
    sign = n;
    i = 0;
    if(n < 0)
        n = -n;
    do{
        s[i++] = n % 10 + '0';
    }
    while((n /= 10) > 0) ;
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

#include <string.h>

void reverse(char s[]){
    int i, j;
    int tmp;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
