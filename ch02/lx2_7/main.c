#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned, int, int);

int main()
{
    int value = invert(0XE7, 6 ,3);
    printf("value is %x", value);
    return 0;
}

unsigned invert(unsigned x, int p, int n){
    return x ^ ~(~0 << n) << (p+1-n);
}
