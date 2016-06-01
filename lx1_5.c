#include <stdio.h>

int main(){

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("摄氏转华氏温度转换表\n");

    celsius = upper;
    while(celsius >= lower){
        fahr = celsius * 1.8 + 32.0;
        printf("%3.0f %6.1f\n",celsius,fahr);
        celsius -= step;
    }

    return 0;
}
