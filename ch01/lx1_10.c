#include <stdio.h>
#include <stdlib.h>

int main(){
    int c;
    while( (c = getchar()) != EOF){
        if((c != '\t') && (c != '\b') && (c != '\\'))
            putchar(c);
        if(c == '\t')
            printf("\\t");
        if(c == '\b')
            printf("\\b");
        if(c == '\\')
            printf("\\\\");
    }
    return 0;
}
