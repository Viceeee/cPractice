#include <stdio.h>
#include <stdlib.h>

// #define isupper(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0

int isupper(char );

int main()
{
    char *s = "Aa";
    if(isupper(*s++))
        printf("true");
    else
        printf("false");
    return 0;
}

int isupper(char c){
    if(c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}
