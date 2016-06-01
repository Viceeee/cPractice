#include <stdio.h>
#include <stdlib.h>

int main(){
    long int sum = 0;
    int n = 10;
    int A[n];
    int i,j;
    long int product = 1;

    for(i = 0; i < n; i++){
        A[i] = i + 1;
        for(j = 0; j < i; j++){
            product *= 4;
        }
        sum += A[i]*product;
        product = 1;
    }
    printf("%d",sum);
    return 0;
}
