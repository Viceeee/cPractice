#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int remove1(char s[]);

int main(){
    char line[MAXLINE];
    while(getline(line, MAXLINE) > 0)
        if(remove1(line) > 0)
            printf("%s",line);
    return 0;
}

int getline(char line[], int maxline){
    int c;
    int i;
    for(i = 0; i < maxline -1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

int remove1(char s[]){
    int i;
    i = 0;
    while(s[i] != '\n'){
        i++;
    }
    --i;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if(i >= 0){
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}
