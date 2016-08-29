#include <stdio.h>


int main(int argc, char *argv[]){
	int c;
	FILE *fp;

	if(argc == 1)
		c = getc(stdin);
	else if(argc == 2){
		fp = fopen(*++argv, "r");
		c = getc(fp);
		
	}	
	else
		printf("error");
	printf("%c\n", c);
	return 0;
}

