#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10;
    char *p;
    char daytab[2][10] = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    };
    p = daytab[0];
    while(n--){
        printf("%2d", *p++);
    }
    return 0;
}
