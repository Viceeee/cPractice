#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);

int main()
{
    int x = 0xe
    f;
    int counts = bitcount(x);
    printf("bit counts is %d", counts);
    return 0;
}

int bitcount(unsigned x){
    int b;
    for(b = 0; x != 0; x &= x-1){
        b++;
    }
    return b;
}

