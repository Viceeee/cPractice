#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000


int except = 0, number = 0, found = 0;

void fileprint(FILE *, char *, char *, int);

int main(int argc, char *argv[])
{
    int c;
    FILE *fp;
    char *pattern;
    char *prog = argv[0];
    char *filename;

    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                fprintf(stderr, "find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if(argc == 0)
        fprintf(stderr, "find -x -n pattern\n");
    else if(argc == 1){
        pattern = *argv;
        fp = stdin;
        fileprint(fp, "stdin", pattern, MAXLINE);
    }
    else{
        pattern = *argv;
        while(--argc > 0){
            filename = *++argv;
            if((fp = fopen(filename, "r")) == NULL){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else{
                fileprint(fp, filename, pattern, MAXLINE);
                fclose(fp);
            }
        }
    }
    exit(0);
}

void fileprint(FILE *fp, char *filename, char *pattern, int max){
    char line[MAXLINE];
    long lineno = 0;
    extern int except, number;

    while(fgets(line, MAXLINE, fp) != NULL){
        lineno++;
        if((strstr(line, pattern) != NULL) != except){
            if(*filename)
                printf("%s -", filename);
            if(number)
                printf("%ld: ", lineno);
            printf("%s", line);
        }
    }
}


