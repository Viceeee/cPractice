#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, int n);
int wordLength(void);

int main()
{
    int value = rightrot(0x00ef, 4);
    printf("%x", value);
    return 0;
}

/*
unsigned rightrot(unsigned x, int n){
    int wordLength(void);
    int rbit;

    while(n-- > 0){
        rbit = (x & 1) << (wordLength() - 1);
        x = x >> 1;
        x = x | rbit;
    }
    return x;
}
*/

unsigned rightrot(unsigned x, int n){
    int wordLength(void);
    int rbit;

    if((n = n % wordLength()) > 0){
        rbit = x & ~(~0 << n);
        rbit = rbit << (wordLength() - n);
        x = (x >> n) | rbit;
    }
    return x;
}


int wordLength(void){
    int i;
    unsigned v =(unsigned) ~0;
    for(i = 1; (v = v >> 1) > 0; i++);
    return i;
}
