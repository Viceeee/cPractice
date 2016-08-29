#include <stdio.h>
#include <stdlib.h>

char *month_name(int n);

int main()
{
    char *name = month_name(4);
    printf("print %s", name);
    return 0;
}

char *month_name(int n){
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}
