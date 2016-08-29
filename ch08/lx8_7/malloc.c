#include <stdio.h>
#include "header.h"

#define MAXBYTES (unsigned) 10240

static unsigned maxalloc;
static Header base;
static Header *freep = NULL;
static Header *morecore(unsigned);

void *malloc1(unsigned nbytes){
	Header *p, *prevp;
	unsigned nunits;
	
	if(nbytes > MAXBYTES){
		fprintf(stderr, "alloc: can't allocate more than %u bytes\n",
			 MAXBYTES);
		return NULL;
	}	
	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
	if((prevp = freep) == NULL){
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}
	for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
		if(p->s.size >= nunits){
			if(p->s.size == nunits)
				prevp->s.ptr = p->s.ptr;
			else{
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *) (p + 1);
		}
		if(p == prevp)
			if((p = morecore(nunits)) == NULL)
				return NULL;
	}
}

#define NALLOC 1024

static Header *morecore(unsigned nu){
        char *cp, *sbrk(int);
	Header *up;	
	void free(void *);
	
	if(nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if(cp == (char *) -1)
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	maxalloc = (up->s.size > maxalloc) ? up->s.size : maxalloc;
	free((void *) (up + 1));
	return freep;
}

void free(void *ap){  
    	Header *p, *bp;  
		
	bp = (Header *) ap - 1;

	if(bp->s.size == 0 || bp->s.size > maxalloc){
		fprintf(stderr, "free: can't free %u units\n",
				bp->s.size);
		return; 
	}
	for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break;
	
	if(bp + bp->s.size == p->s.ptr){ /* join to the upper part */
		bp->s.size += p->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;	
	} else
		bp->s.ptr = p->s.ptr;
	
	if(p + p->s.size == bp){  /* join to the lower part */
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else
		p->s.ptr = bp;
	freep = p;
}  
