#include <stdlib.h>

#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO 0

void settab(int argc, char *argv[], char *tab){
    int i, pos, pos1;
    if(argc <= 1)
        for(i = 1; i <= MAXLINE; i++)
            if(i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else{
        for(i = 1; i <= MAXLINE; i++)
            tab[i] = NO;
        while(--argc > 0){
            pos = atoi(*++argv);
            pos1 = pos;
            while(pos > 0 && pos <= MAXLINE){
                tab[pos] = YES;
                pos += pos1;
            }
        }
    }
}
