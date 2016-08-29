#include <stdio.h>
#include <stdlib.h>

struct aircraft{
    int wingspan;
    int passengers;
    union load{
        float fuel_load;
        float bomb_load;
        int pallets;
    };
} fighter;

int main()
{
    int n1, n2;
    union load u;
    n1 = sizeof(fighter);
    n2 = sizeof(char);
    printf("%d", n1);
    printf(" %d", n2);

    return 0;
}
