#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int get(int, long, char *, int);

int main(){
	int fd, n;
	char buf[20];
	fd = open("print", O_RDONLY, 0);
	n = get(fd, 10, buf, 18);
	printf(" %s\n", buf);
	return 0;
}

int get(int fd, long pos, char *buf, int n){
	if(lseek(fd, pos, 0) >= 0)
		return read(fd, buf, n);
	else
		return -1;
}
