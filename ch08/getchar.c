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
	char c;
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;  
}
