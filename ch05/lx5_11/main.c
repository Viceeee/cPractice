#include <stdio.h>

#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO 0

void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);

/*replace strings of blanks with tabs*/
int main(int argc, char *argv[]){

    int i;
    char tab[MAXLINE + 1];
    settab(argc, argv, tab);
    entab(tab);
    return 0;
}

/* entab: replace strings of blanks with tabs and blanks */
void entab(char *tab){
    int c, pos;
    int nb = 0;
    int nt = 0;

    for(pos = 1; (c = getchar()) != EOF; pos++)
        if(c == ' '){
            if(tabpos(pos, tab) == NO)
                ++nb;
            else{
                nb = 0;
                ++nt;
            }
        } else{
            for( ; nt > 0; nt--)
                putchar('\t');
            if(c == '\t')
                nb = 0;
            else
                for( ; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if(c == '\n')
                pos = 0;
            else if(c == '\t')
                while(tabpos(pos, tab) != YES)
                    ++pos;
        }
}
