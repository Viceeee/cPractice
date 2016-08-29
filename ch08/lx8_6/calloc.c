#include <unistd.h>
void *malloc1(unsigned);

void *calloc1(unsigned n, unsigned size){
	unsigned i, nb;
	char *p, *q;
	
	nb = n * size;
	if((p = q = (char *) malloc1(nb)) != NULL)
		for(i = 0; i < nb; i++)
			*p++ = 0;
	return q;
}
