#include <stdio.h>
#include <stdlib.h>

char *keytab[] = {"int", "void", "char"};

#define NKEYS (sizeof keytab / sizeof(char *))

int main()
{
    printf("%d", NKEYS);
    return 0;
}

