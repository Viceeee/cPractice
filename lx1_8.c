#include <stdio.h>

int main(){
    int c;
    int n1 = 0,n2 = 0,n3 = 0;
    while((c = getchar()) != EOF){
        if(c == ' ')
            n1++;
        if(c == '\t')
            n2++;
        if(c == '\n')
            n3++;
    }
    printf("%6d%6d%6d",n1,n2,n3);
    return 0;
}
