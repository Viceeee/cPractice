#include "header.h"
#include <stdlib.h>
#include <unistd.h>

FILE _iob[OPEN_MAX] = {
	{0, (char *) 0, (char *) 0, _READ, 0},
	{0, (char *) 0, (char *) 0, _WRITE, 1},
	{0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

void filecopy(FILE *, int );
FILE *fopen(char *, char *);
void error(char *, ...);
int _fillbuf(FILE *);

int main(int argc, char *argv[]){
	FILE *fp;
	
	if(argc == 1)
		filecopy(stdin, 1);
	else {
		while(--argc > 0){
			if((fp = fopen(*++argv, "r")) == null){
				error( "error");
				exit(1);
			} else{
				filecopy(fp, 1);
			}
				
		}
	}
	exit(0);		
}

void filecopy(FILE *ifp, int f){
	int c;
	while((c = getc(ifp)) != EOF)
		write(f, &c, 1);
	
}
