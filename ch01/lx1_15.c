#include <stdio.h>
#include <stdlib.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int fahr2celsius(int fahr);

int main(){

    int fahr, celsius;
    for(fahr = 0; fahr <= UPPER; ){
        celsius = fahr2celsius(fahr);
        printf("%5d %5d\n", fahr, celsius);
        fahr += STEP;
    }
    return 0;
}

int fahr2celsius(int fahr){

    int celsius;
    celsius = 5 * (fahr - 32) / 9;
    return celsius;
}
