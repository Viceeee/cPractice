#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 10;
    int i;
    int A[n];
    int poly = 0;
    for(i = 0; i < n; i++){
        A[i] = i + 1;
    }
    for(i = n - 1; i >= 0; i--){
        poly = 4 * poly + A[i];
    }
    printf("%d",poly);
    return 0;
}
