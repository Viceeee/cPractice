#include <stdio.h>

int main(){
	char s[] = "hello everyone";
	char *t = "hello myself";
	char *string;
	string = t = s;
	*(string + 1) = 'u';
	printf("string: %s t:%s s: %s\n", string, t, s);
}
