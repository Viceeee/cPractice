#include <stdio.h>

void qsort(int v[], int left, int right);

int main()
{
    int i;
    int v[10] = {12, 4, 5, 89, 6, 3, 0, 2, 45, 88};
    qsort(v, 0, 9 );
    for(i = 0; i < 10; i++){
        printf("  %d", v[i]);
    }
    return 0;
}

void qsort(int v[], int left, int right){
    int i, last;
    void swap(int v[], int i, int j);
    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j){
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

}
