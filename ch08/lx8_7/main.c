#include <stdio.h>
#include "header.h"

void *malloc1(unsigned );
void free(void *);

int main(){
	char *s;
	s = (char *) malloc1(10 * sizeof(char));
	if(s == NULL)
		printf("error: out of memory\n");
	free(s);
	Header ll;
	printf("Header: %ld, long: %ld\n", sizeof(ll.s), sizeof(long));
	char *t;
	t = (void *)malloc1(0 * sizeof(char));
	Header *up = (Header *) t;
	up->s.size = 0;
	free((void *)up + 1);
}
