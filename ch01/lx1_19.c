#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

int main(){
    char line[MAXLINE];
    int len;
    while( len = getline(line, MAXLINE) > 0){
        reverse(line);
        printf("%s", line);
    }
}

int getline(char line[], int maxline){
    int c, i;
    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if( c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

// reverse: reverse string s
void reverse(char s[]){
    int i, j;
    char temp;

    i = 0;
    while(s[i] != '\0')
        ++i;
    --i;
    if(s[i] == '\n')
        --i;
    j = 0;
    while(j < i){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}
