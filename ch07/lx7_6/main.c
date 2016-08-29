#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compare(FILE *, FILE *);

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    if(argc != 3)
        fprintf(stderr, "error: not two file\n");
    else{
        if((fp1 = fopen(*++argv, "r")) == NULL){
            fprintf(stderr, "can't open file %s\n", *argv);
            exit(1);
        }
        if((fp2 = fopen(*++argv, "r")) == NULL){
            fprintf(stderr, "can't open file %s\n", *argv);
            exit(2);
        }
        compare(fp1, fp2);
        fclose(fp1);
        fclose(fp2);
    }
    return 0;
}

#define MAXLINE 100
void compare(FILE *ifp, FILE *iop){
    int i = 0;
    char line1[MAXLINE], line2[MAXLINE];
    do{
        fgets(line1, MAXLINE, ifp);
        fgets(line2, MAXLINE, iop);
        i++;
    } while(strcmp(line1, line2) == 0);
    printf("%d %s\n", i, line1);
}
