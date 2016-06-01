#include <stdio.h>
#include <stdlib.h>

long int Pow(long int X, unsigned int N);

int main(){
    int i;
    int n = 10;
    int sum = 0;
    int A[n];
    for(i = 0; i < n; i++){
        A[i] = i+1;
    }
    for(i = 0; i < n; i++){
        sum += A[i]*Pow(4,i);
    }
    printf("%d",sum);
    return 0;
}

long int Pow(long int X, unsigned int N){
    if(N == 0)
        return 1;
    if(N == 1)
        return X;
    if(N % 2 == 0){
        return Pow(X,N/2)*Pow(X,N/2);
    }else
        return X*Pow(X,(N-1)/2)*Pow(X,(N-1)/2);
}
