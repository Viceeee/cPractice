#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void lower(char s[]);
static int to[100];

int main()
{
    char s[] = "###ABD57657edf67";
    //lower(s);
    lower(s);
    printf("%s",s);
    return 0;
}

void lower(char s[]){
    int i,j = 0;
    extern int to[];
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            to[j++] = s[i] - 'A' + 'a';
        } else if(s[i] >= 'a' && s[i] <= 'z'){
            to[j++] = s[i];
        }
    }
    for(i = 0; (s[i] = to[i]) != '\0'; i++);
    s[i] = '\0';
}

