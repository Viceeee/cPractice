#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getword(char *, int);
int getword2(char *, int);

int main()
{
    char w[100];
    int n = getword2(w, 100);
    printf("change: %s %c\n", w, n);
    return 0;
}

int getword2(char *word, int lim){
    char *w = word;
    int c;

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int getword(char *word, int lim){
    int getch(void), comment(void);
    void ungetch(int);

    int c, d;
    char *w = word;

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(isalpha(c) || c == '_' || c == '#'){
        for( ; --lim > 0; w++)
            if(!isalnum(*w = getch()) && *w != '_'){
                ungetch(*w);
                break;
            }
    } else if(c == '\'' || c == '"'){
        for( ; --lim > 0; w++)
            if((*w = getch()) != c)
                *++w = getch();
            else if(*w == c){
                w++;
                break;
            } else if(*w == EOF)
                break;
    } else if(c == '/'){
        if((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);
    }
    *w = '\0';
    return c;
}

int comment(void){
    int getch(void);
    void ungetch(int);

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
