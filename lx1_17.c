#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char line[], int maxline);

int main(){
    int i = 0, j = 0;
    int count = 0;
    char* buffer[MAXLINE];
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0){
        if(len > 5){
            buffer[i] = line;
            count++;
            i++;
        }
    }

    for(j = 0; j < count; j++){
        printf("%s", buffer[j]);
    }
    return 0;
}

int getline(char line[], int maxline){
    int c,i;
    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
