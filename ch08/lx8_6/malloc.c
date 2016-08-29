#include <stdio.h>
#include "header.h"

static Header base;
static Header *freep = NULL;
static Header *morecore(unsigned);

void *malloc1(unsigned nbytes){
	Header *p, *prevp;
	unsigned nunits;
	
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
	free((void *) (up + 1));
	return freep;
}

void free(void *ap){  
    Header *p, *bp;  
  
    bp =(Header *)ap -1;    /*指向ap块的头部*/  
    for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)    /*找到bp所在空闲链表中的位置*/  
        if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))   /*判断是否在链表的开头或末尾*/  
            break;  
  
    if(bp + bp->s.size == p->s.ptr){  /*先判断能否与高地址的空闲块合并，即与后一块合并*/  
        bp->s.size += p->s.ptr->s.size;  
        bp->s.ptr = p->s.ptr->s.ptr;  
    }  
    else  
        bp->s.ptr = p->s.ptr; /*不能合并，bp指向后一块地址*/  
  
    if(p + p->s.size == bp){ /*再判断能否与地地址的空闲块合并，即与前一块合并*/  
        p->s.size += bp->s.size;  
        p->s.ptr = bp->s.ptr;  
    }  
    else  
        p->s.ptr =bp;    /*不能合并，p指向bp地址*/  
    freep =p;  
}  
