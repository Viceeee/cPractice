#include <stdio.h>

struct Header{
	int size;
 	struct Header *ptr;	
};
int main(){
	struct Header base, *p, *prevp;
	base.ptr = p = prevp = &base;
	base.size = 1; 
	struct Header *bp, base2;
	bp = &base2;
	bp->size = 4;
	p->ptr = bp;
	
}
