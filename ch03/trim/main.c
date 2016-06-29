#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trim(char []);

int main()
{
    char s[100] = "adfa    ";
    int d = trim(s);
    printf("%d%s", d,s);
    return 0;
}

int trim(char s[]){
    int n;
    for(n = strlen(s) - 1; n >= 0; n--)
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}
