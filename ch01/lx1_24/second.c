

void search(int c){
    extern int brace, brack, paren;

    if(c == '{')
        ++brace;
    else if(c == '}')
        --brace;
    else if(c == '[')
        ++brack;
    else if(c == ']')
        --brack;
    else if(c == '(')
        ++paren;
    else if(c == ')')
        --paren;
}

void in_comment(void){
    int c, d;
    c = getchar();
    d = getchar();
    while(c != '*' || d != '/'){
        c = d;
        d = getchar();
    }
}

void in_quote(int c){
    int d;
    while((d = getchar()) != c)
        if(d == '\\')
            getchar();
}
