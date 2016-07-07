include <stdio.h>

int main(){
    int i;
    char c;
    i = -1;
    c = i;
    printf("%x\n",c);
    i = c;
    printf("%x\n",i);
    return 0;
}
