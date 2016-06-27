#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* lower(char s[]);
static int to[100];

int main()
{
    char s[] = "ABDedf";
    //lower(s);
    int* to = lower(s);
    printf("%s",to);
    return 0;
}

int* lower(char s[]){
    int i,j = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            to[j] = s[i] - 'A' + 'a';
            j++;
        }
    }
    return to;
}

