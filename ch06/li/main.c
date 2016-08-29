#include <stdio.h>

typedef struct
{
    int show:1,
        color:3,
        volume:4,
        type:8,
        size:24;
} BitStruct_1;

typedef struct
{
    int show:3;
    int color:3;
    int volume:4;
    int type:8;
    int :30;
} BitStruct_2;


int main()
{
    BitStruct_1 bs_1 = {1,5,10,34,78};
    BitStruct_2 bs_2;
    bs_2.show = 5; // Òç³ö
    bs_2.color = 6;
    bs_2.volume = 9;
    bs_2.type = 57;

    printf("sizeof bs_1:%d\n", sizeof(bs_1));
    printf("sizeof bs_2:%d\n", sizeof(bs_2));
    printf("bs_1: %d, %d, %d, %d, %d\n", bs_1.show, bs_1.color, bs_1.volume, bs_1.type, bs_1.size);
    printf("bs_2: %d, %d, %d, %d\n", bs_2.show, bs_2.color, bs_2.volume, bs_2.type);

    return 0;
}
