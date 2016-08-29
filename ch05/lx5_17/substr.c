#include <string.h>

void error(char *);

void substr(char *s, char *str, int MAXSTR){
    int i, j, len;
    extern int pos1, pos2;

    len = strlen(s);
    if(len > MAXSTR)
        error("substr: string too long");
    if(pos2 > 0 && len > pos2)
        len = pos2;
    else if(pos2 > 0 && len < pos2)
        error("substr: string too short");
    for(j = 0, i = pos1; i < len; i++, j++)
        str[j] = s[i];
    str[j] = '\0';
}
