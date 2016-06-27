#include <stdio.h>
#include <stdlib.h>

int brace, brack, paren;

extern void in_quote(int c);
extern void in_comment(void);
extern void search(int c);

/* rudimentary syntax checker for C program*/
int main()
{
    int c;
    extern int brace, brack, paren;
    while((c = getchar()) != EOF){
        if(c == '/'){
            if((c = getchar()) == '*')
                in_comment();
            else
                search(c);
        } else if(c == '\'' || c == '"' )
                in_quote(c);
        else
            search(c);
        if(brace < 0){
            printf("Unbalanced braces\n");
            brace = 0;
        } else if(brack < 0){
            printf("Unbalanced brackets\n");
            brack = 0;
        } else if(paren < 0){
            printf("Unbalanced parentheses\n");
            paren = 0;
        }
    }
    if(brace > 0)
        printf("Unbalanced braces\n");
    if(brack > 0)
        printf("Unbalanced brackets\n");
    if(paren > 0)
        printf("Unbalanced parentheses\n");
    return 0;
}
