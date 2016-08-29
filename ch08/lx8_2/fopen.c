#include <fcntl.h>
#include <unistd.h>
#include "header.h"

#define PERMS 0666


FILE *fopen(char *name, char *mode){
	int fd;
	FILE *fp;
	
	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return null;
	for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if(fp->flag.is_read == 0 && fp->flag.is_write == 0)
			break;
	if(fp >= _iob + OPEN_MAX)
		return null;
	
	if(*mode == 'w')
		fd = creat(name, PERMS);
	else if(*mode == 'a'){
		if((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	}else
		fd = open(name, O_RDONLY, 0);
	if(fd == -1)
		return null;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = null;
	fp->flag.is_unbuf = 0;
	fp->flag.is_buf = 1;
	fp->flag.is_eof = 0;
	fp->flag.is_err = 0;
	if(*mode == 'r'){
		fp->flag.is_read = 1;
		fp->flag.is_write = 0;	
	} else{
		fp->flag.is_read = 0;
		fp->flag.is_write = 1;
	}
	return fp;
}
