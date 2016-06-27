#include <stdio.h>
#include <stdlib.h>

int any(char s1[], char s2[]);

int main()
{
    int pos;
    char s1[] = "asdfghjk";
    char s2[] = "r";
    pos = any(s1, s2);
    printf("position is %d", pos);
    return 0;
}

int any(char s1[], char s2[]){
    int i, j;
    for(i = 0; s1[i] != '\0'; i++){
        for(j = 0; s2[j] != '\0'; j++){
            if(s2[j] == s1[i])
                return i;
        }
    }
    return -1;
}
