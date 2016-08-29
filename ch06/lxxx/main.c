#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tab[] = {"and", "of", "or", "that", "the", "this"};

int binsearch(char *);
#define NTABS (sizeof tab / sizeof(char *))
int main()
{
    char *word = "and";
    int n = binsearch(word);
    printf("%d\n", n);
    return 0;
}

int binsearch(char *word){
    int low, high, mid;
    int cond;
    extern char *tab[];
    low = 0;
    high = sizeof(tab) / sizeof(char *) - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if((cond = strcmp(word, tab[mid])) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

