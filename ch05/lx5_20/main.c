#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int main()
{
     while(gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
