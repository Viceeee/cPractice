#include <stdio.h>
#include <stdlib.h>

struct key{
    char c;
    char i;
};
int main()
{
    printf("%d", sizeof(struct key));
    return 0;
}
