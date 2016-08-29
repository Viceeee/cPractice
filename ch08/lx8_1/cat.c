#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void error(char *, ...);

int main(int argc, char *argv[]){
	char buf[BUFSIZ];
	int f1, f2;
	int n;
	char *prog = argv[0];

	if(argc == 1){
		while((n = read(0, buf, BUFSIZ)) > 0){
			write(1, buf, n);
		}
	}else{
		while(--argc > 0){
			if((f1 = open(*++argv, O_RDONLY, 0)) == -1){
				error("%s: can't open %s", prog, *argv);
				exit(1);
			} else{
				while((n = read(f1, buf, BUFSIZ)) > 0)
					if(write(1, buf, n) != n){
						error("%s: write error on file %s", prog, *argv);
					}
			}
		}	
	}
	exit(0);
}
