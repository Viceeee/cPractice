#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

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

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            if((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for(n = 0; n < NKEYS; n++)
        if(keytab[n].count > 0)
            printf("%4d %s\n",
                   keytab[n].count, keytab[n].word);
    return 0;
}

int binsearch(char *word, struct key tab[], int n){
    int low, high, mid;
    int cond;
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getword(char *word, int lim){
    int getch(void);
    void ungetch(int);

    int c;
    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *word++ = c;
    if(!isalpha(c)){
        *word = '\0';
        return c;
    }
    for(; --lim > 0; word++)
        if(!isalnum(*word = getch())){
            ungetch(*word);
            break;
        }
    *word = '\0';
    return word[0];
}

#define BUFSIZE 100

int bufp = 0;
int buf[BUFSIZE];

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
