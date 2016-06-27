#include <stdio.h>
#include <stdlib.h>

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);
