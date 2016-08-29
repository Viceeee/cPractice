#include "header.h"
#include <stdlib.h>
#include <unistd.h>

FILE _iob[OPEN_MAX] = {
	{0, (char *) 0, (char *) 0, _READ, 0},
	{0, (char *) 0, (char *) 0, _WRITE, 1},
	{0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

void filecopy(FILE *, FILE *);
FILE *fopen(char *, char *);
void error(char *, ...);

int main(int argc, char *argv[]){
	FILE *fp, *fp2;
	
	if(argc == 1)
		filecopy(stdin, stderr);
	else if(argc == 3){
		
		if((fp = fopen(*++argv, "r")) == null || (fp2 = fopen(*++argv, "w"))== null){
			error( "error");
			exit(1);
		} else{
			filecopy(fp, fp2);
			fclose(fp2);
		}	
	}else
		error("error: not 3 arguments");
	exit(0);		
}

void filecopy(FILE *ifp, FILE *ofp){
	int c;
	while((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
