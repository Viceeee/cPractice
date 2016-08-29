#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

int max = 0;
struct tnode *temp;

int main()
{
    char word[MAXWORD];
    struct tnode *root = NULL;
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0]))
            root = addtree(root, word);
    }
    treeprint(root);
    printf("%s: %d", temp->word, max);
    return 0;
}

struct tnode *talloc(void);

struct tnode *addtree(struct tnode *p, char *w){
    int cond;
    if(p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if(cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void treeprint(struct tnode *p){
    extern int max;
    extern struct tnode *temp;
    if(p != NULL){
        treeprint(p->left);
        if(p->count > max){
            max = p->count;
            temp = p;
        }
        treeprint(p->right);
    }
}

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

int getch(void);
void ungetch(int);

int getword(char *w, int lim){
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
    return w[0];
}

#define BUFSIZE 100
int bufp = 0;
char buf[BUFSIZE];

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
