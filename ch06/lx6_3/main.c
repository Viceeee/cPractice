#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define LINES 10

struct tnode {
    char *word;
    int line;
    struct tnode *left;
    struct tnode *right;
};
char *tab[] = {"and", "of", "or", "the"};
#define NTABS (sizeof tab / sizeof(char *))

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
int binsearch(char *, char **, int);

int main()
{
    char word[MAXWORD];
    int c;
    int line = 0;
    struct tnode *root = NULL;
    while((c = getword(word, MAXWORD)) != EOF){
        if(word[0] == '\n'){
            line++;
        }
        if(isalpha(word[0]) && binsearch(word, tab, NTABS) <= 0)
            root = addtree(root, word, line);
    }
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *strdup1(char *);

struct tnode *addtree(struct tnode *p, char *w, int line){
    int cond;
    if(p == NULL){
        p = talloc();
        p->word = strdup1(w);
        p->line = line;
        p->left = p->right = NULL;
    } else if((cond = strcmp(w, p->word)) < 0)
        p->left = addtree(p->left, w, line);
    else if(cond > 0)
        p->right = addtree(p->right, w, line);
    return p;
}

void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->line, p->word);
        treeprint(p->right);
    }
}


int binsearch(char *word, char* tab[], int n){
    int low, high, mid;
    int cond;
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = low + (high - low) / 2;
        if((cond = strcmp(word, tab[mid])) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getch(void);
void ungetch(int);

int getword(char *word, int lim){
    char *w = word;
    int c;
    while((c = getch()) == ' ')
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
