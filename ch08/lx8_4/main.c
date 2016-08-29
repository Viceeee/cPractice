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
int get(FILE *, long, char *, int);

int main(int argc, char *argv[]){
	int n, i = 5;
	FILE *fp;
        char buf[100], c;
        char *name = *++argv;
	fp = fopen(name, "r");
	while(--i > 0)
		getc(fp); 
//	n = get(fp, 5, buf, 18);
	lseek(fp->fd, -38, 1);  	      
	n = read(fp->fd, buf, BUFSIZ);
	error("n: %d %s", n, buf);
        return 0;
}

int get(FILE *fp, long pos, char *buf, int n){
	if(fseek(fp, pos, 1) >= 0)
		return read(fp->fd, buf, n);
	else 	
		return -1;
}
