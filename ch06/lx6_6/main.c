#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
int getword(char *, int);

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
struct nlist *undef(char *);

struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

int main()
{
    int c;
    char word[MAXWORD];
    char word2[MAXWORD];
    struct nlist *np = (struct nlist *) malloc(sizeof(struct nlist));
    char *def = "define";
    while((c = getword(word, MAXWORD)) != EOF){
        if(c == '#'){
            getword(word, MAXWORD);
            if(strcmp(word, def) == 0){
                getword(word, MAXWORD);
                getword(word2, MAXWORD);
                np = install(word, word2);
            }
        }
    }
    return 0;
}

unsigned hash(char *s){
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
    struct nlist *np;
    for(np = hashtab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *lookup(char *);

struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;
    if((np = lookup(name)) == NULL){
        np = (struct nlist *) malloc(sizeof(* np));
        if(np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

struct nlist *undef(char *s){
   int h;
   struct nlist *prev, *np;
   prev = NULL;
   h = hash(s);
   for(np = hashtab[h]; np != NULL; np = np->next){
        if(strcmp(s, np->name) == 0)
            break;
        prev = np;
   }
   if(np != NULL){
        if(prev == NULL)
            hashtab[h] = np->next;
        else
            prev->next = np->next;
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);
   }
}

int getch(void);
void ungetch(int);

int getword(char *word, int lim){
    int c;
    char *w = word;
    while(isspace(c = getch()) && c != '\n')
        ;
    if(c != EOF)
        *w++ = c;
    if(!isalnum(c)){
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
