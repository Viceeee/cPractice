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
int getch(void);
void ungetch(int);
int comment(void);

int main()
{
    char word[MAXWORD];
    int n, i;

    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0]))
            if((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    }
    for(i = 0; i < NKEYS; i++){
        if(keytab[i].count > 0)
            printf("%s %d\n", keytab[i].word, keytab[i].count);
    }
    return 0;
}

int getword(char *word, int lim){
    char *w = word;
    int c, d;

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(isalpha(c) || c == '#' || c == '_'){
        for( ; --lim > 0; w++){
            if(!isalnum(*w = getch()) && *w != '_')
                ungetch(*w);
                break;
        }
    } else if(c == '\'' || c == '"'){
        for( ; --lim > 0; w++)
            if((*w = getch()) != c && *w != EOF)
                *++w = getch();
            else if(*w == c){
                *w++ = c;
                break;
            }
            else if(*w == EOF)
                break;
    } else if( c == '/')
        if((d = getch()) == '*')
           c = comment();
        else
            ungetch(d);
    *w = '\0';
    return c;
}

int comment(void){
    int c;
    while((c = getch()) != EOF)
        if(c == '*'){
            if((c = getch()) == '/')
                break;
            else
                ungetch(c);
        }

    return c;
}


int binsearch(char *word, struct key tab[], int n){
    int cond;
    int low, high, mid;
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
