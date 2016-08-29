#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
	
void *malloc1(unsigned );
void free(void *);
	
void main(){
	char *s;
	s = (char *)malloc1(10 * sizeof(char));
	if(s == NULL)
		exit(1);
	strcpy(s, "Hello");
	printf("%ld\n", sizeof(s));
	printf("%s\n", s);
	free(s);
	s = NULL;
}
