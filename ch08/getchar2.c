#include <stdio.h>
#include <unistd.h>

#undef getchar

int getchar(void);

int main(){
	int c;
	while((c = getchar()) != EOF)
		write(1, &c, 1);
	return 0;
}

int getchar(void){
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if(n == 0){
		n = read(0, buf, sizeof(buf));
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
