#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	char *s;
	s = (char *)malloc(10 * sizeof(char));
	if(s == NULL)
		exit(1);
	strcpy(s, "Helloworl");
	printf("s: %d\n", sizeof(s));
	printf("char: %d\n", sizeof(char));
	printf("%s\n", s);
	free(s);
	s = NULL;
}
