#include <stdio.h>
#include <string.h>

void lower(char *lineptr[], int nlines);

int main()
{
    /*
    int nlines = 3, i;
    char s1[] = "DATA";
    char s2[] = "C";
    char s3[] = "Programming";
    char *lineptr[] = {s1, s2, s3};
    lower(lineptr, nlines);
    for(i = 0; i < nlines; i++)
        printf("%s  ", lineptr[i]);
    */
    return 0;
}

#include <ctype.h>

void lower(char *lineptr[], int nlines){
    int i, j;
    char *line;
    for(i = 0; i < nlines; i++){
        line = lineptr[i];
        for(j = 0; j < strlen(line); j++)
            line[j] = tolower(line[j]);
    }
}


