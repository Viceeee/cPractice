#include <stdio.h>

#define swap(t, x, y)   {\
                        t _z;\
                        _z = x;\
                        x = y;\
                        y = _z;\
                        }
#undef swap
void swap(int*, int*);

int main()
{
    int x = 0, y = 1;
    swap(&x, &y);
    printf(" %d  %d", x, y);
    return 0;
}

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
