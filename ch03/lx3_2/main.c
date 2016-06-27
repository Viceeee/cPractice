#include <stdio.h>
#include <stdlib.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char t[100] = "adfads\t\nadf";
    char s[100];
    escape(s, t);
    printf("strlen of t is %d\n", strlen(t));
    printf("after escape: %s\n", s);
    printf("strlen of s is %d\n", strlen(s));
    unescape(t, s);
    printf("%s\n", t);
    return 0;
}

void escape(char s[], char t[]){
    int i, j;
    for(i = 0, j = 0; t[i] != '\0'; i++){
        switch(t[i]){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]){
    int i, j;
    for(i = j = 0; t[i] != '\0'; i++){
        if(t[i] != '\\'){
            s[j++] = t[i];
        }
        else
            switch(t[++i]){
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
    }
    s[j] = '\0';
}
