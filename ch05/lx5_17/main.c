#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define DIR 8
#define LINES 100


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int order);
void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);
void error(char *);
void readargs(int argc, char *argv[]);


char option = 0;
int pos1 = 0;
int pos2 = 0;

int main(int argc, char *argv[])
{
    char *lineptr[LINES];
    int nlines;
    int rc = 0;

    readargs(argc, argv);
    if((nlines = readlines(lineptr, LINES)) > 0){
        if(option & NUMERIC)
            qsort((void **) lineptr, 0, nlines - 1,
                (int (*)(void *, void *)) numcmp);
        else
            qsort((void **) lineptr, 0, nlines - 1,
                (int (*)(void *, void *)) charcmp);
            writelines(lineptr, nlines, option & DECR);
    } else{
        printf("input too big to sort\n");
        rc = -1;
    }
    return rc;
}

void readargs(int argc, char *argv[]){
    int c;
    int atoi(char *);
    while(--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+'){
        if(c == '-' && !isdigit(*(argv[0] + 1)))
            while(c = *++argv[0])
                switch(c){
                    case 'd':
                        option |= DIR;
                        break;
                    case 'f':
                        option |= FOLD;
                        break;
                    case 'n':
                        option |= NUMERIC;
                        break;
                    case 'r':
                        option |= DECR;
                        break;
                    default:
                        printf("sort: illegal option %c\n", c);
                        error("Usage: sort -dfnr [+pos1] [-pos2]");
                        break;
                }
        else if(c == '-')
            pos2 = atoi(argv[0] + 1);
        else if((pos1 = atoi(argv[0] + 1)) < 0)
            error("Usage: sort -dnfr [+pos1] [-pos2]");
    }
    if(argc || pos1 > pos2)
        error("Usage: sort -dnfr [+pos1] [-pos2]");
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *)){
    int i, last;
    void swap(void *v[], int, int);
    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXLEN 1000
int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){

    int getline(char *, int);

    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int decr){
    int i;
    if(decr)
        for(i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for(i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

int getline(char *line, int lim){
    int c;
    char *start = line;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *line++ = c;
    if(c == '\n')
        *line++ = c;
    *line = '\0';
    return line - start;
}


