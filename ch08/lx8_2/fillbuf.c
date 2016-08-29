#include <unistd.h>
#include <stdlib.h>
#include "header.h"


int _fillbuf(FILE *fp){
	int bufsize;
	
	if((fp->flag.is_read == 0 || fp->flag.is_eof == 1 ||
			fp->flag.is_err == 1))
		return EOF;
	bufsize = (fp->flag.is_unbuf == 1) ? 1 :BUFSIZ; 
	if(fp->base == null)
		if((fp->base = (char *) malloc(bufsize)) == null)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if(--fp->cnt < 0){
		if(fp->cnt == -1)
			fp->flag.is_eof = 1;
		else
			fp->flag.is_err = 1;
		fp->cnt = 0;	
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}
