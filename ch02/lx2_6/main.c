#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned, int ,int ,unsigned);

int main()
{
    int value = setbits(0xE7, 6, 4, 0xA2);
    printf("value is %x", value);
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    return x & ~(~(~0 << n) << (p+1-n)) | ((y & (~(~0 << n)) << (p+1-n)));
}
