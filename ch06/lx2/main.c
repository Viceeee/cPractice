#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct key{
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    /* ... */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

#define NKEYS (sizeof keytab / sizeof(struct key))

struct key *binsearch(char *, struct key *, int);

int main()
{
    char *word = "auto";
    struct key *a = binsearch(word, keytab, NKEYS);
    if(a != NULL)
        printf("%4d %s", a->count, a->word);
    return 0;
}

struct key * binsearch(char *word, struct key tab[], int n){
    int cond;
    struct key *low, *high, *mid;
    low = &tab[0];
    high = &tab[n];
    while(low < high){
        mid = low + (high - low) / 2;
        if((cond = strcmp(word, mid->word)) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}
