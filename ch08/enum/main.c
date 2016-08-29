#include <stdio.h>

int main(){
	typedef enum Color{
		RED = 0x01,
		BLUE,
		GREEN,
		YELLOW
	}Color_Type;
	Color_Type color;
	printf("%x\n", color);
	printf("%x\n", YELLOW);
}
