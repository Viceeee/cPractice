#include <unistd.h>
#include <stdio.h>
#include <string.h>

void *calloc1(unsigned, unsigned);
void *malloc1(unsigned);
void free(void *);

int main(){
	char *s, *t;
	s = (char *) calloc1(5, sizeof(char));
	t = (char *) malloc1(5 * sizeof(char));
	if(s == NULL || t == NULL)
  		return 1;
	strcpy(s, "hell");
	strcpy(t, "hell");
	free(s);
	free(t);
	return 0;
}
