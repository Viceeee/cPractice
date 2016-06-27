#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);

int main()
{
    int i;
    int v[10];
    for(i = 0; i < 10; i++){
        v[i] = 'a' + i;
    }
    int pos = binsearch('d',v,10);
    for(i = 0; i < 10; i++){
        printf("%5c",v[i]);
    }
    printf("\n");
    printf("%d",pos);
    return 0;
}
/*
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
*/
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while(low <= high && x != v[mid]){
        if(x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if(x == v[mid])
        return mid;
    else
        return -1;
}
