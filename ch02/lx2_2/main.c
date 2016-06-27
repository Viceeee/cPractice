                        #include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0)
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if(max > 0)
        printf("%s", longest);
    return 0;
}

int getline(char s[], int lim){
    int c, i;
   /* 第一种
    for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    */

    /* 第二种
    i = 0;
    while((c = getchar()) != EOF){
        if(i >= lim -1)
            break;
        if(c == '\n')
            break;
        s[i] = c;
        ++i;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    */

    enum loop { NO, YES };
    enum loop okloop = YES;

    i = 0;
    while(okloop == YES){
        if(i >= lim - 1)
            okloop = NO;
        else if((c = getchar()) == '\n')
            okloop = NO;
        else if(c == EOF)
            okloop = NO;
        else{
            s[i] = c;
            ++i;
        }
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
