#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define GROUP 6
#define MAXWORD 100

enum{ NO, YES};

struct tnode {
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};


struct tnode *addtree(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getvar(char *, int);

int main(int argc, char *argv[])
{
    int num;
    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;

    struct tnode *root;
    root = NULL;
    char var[MAXWORD];
    int found = NO;
    while(getvar(var, MAXWORD) != EOF){
        printf("%s", var);
        root = addtree(root, var, num, &found);
        found = NO;
    }
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *strdup1(char *);
int compare(char *, struct tnode *, int, int *);

struct tnode *addtree(struct tnode *p, char *w, int num, int *found){
    int cond;
    if(p == NULL){
        p = talloc();
        p->word = strdup1(w);
        p->match = *found;
        p->left = p->right = NULL;
    } else if((cond = compare(w, p, num, found)) < 0)
        p->left = addtree(p->left, w, num, found);
    else if(cond > 0)
        p->right = addtree(p->right, w, num, found);
    return p;
}

int compare(char *s, struct tnode *p, int n, int *found){
    int i;
    char *t = p->word;
    for(i = 0; *s == *t; s++, t++, i++)
        if(*s == '\0')
            return 0;
    if(i >= n){
        *found = YES;
        p->match = YES;
    }
    return *s - *t;
}
void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        if(p->match)
            printf("%s\n", p->word);
        treeprint(p->right);
    }
}

int binsearch(char *, char **, int);
char *keytab[] = {"int", "void", "char"};

#define NKEYS (sizeof keytab / sizeof(char *))
int getword(char *, int);

int getvar(char *var, int lim){

    char word[MAXWORD];
    int flag = 0;
    int c, n;
    if((c = getword(word, lim)) != EOF)
        if((n = binsearch(word, keytab, NKEYS)) >= 0)
            flag = 1;
    if(flag == 1)
        getword(var, lim);
    if(c == EOF)
        return c;
    return 0;
}

int binsearch(char *word, char *keytab[], int n){
    int low, high, mid;
    int cond;
    low = 0;
    high = n;
    while(low <= high){
        mid = low + (high - low) / 2;
        if((cond = strcmp(word, keytab[mid])) < 0)
            high = mid - 1;
        else if (cond > 0)
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

