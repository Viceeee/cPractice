#include <ctype.h>


int main()
{
    double atof(char s[]);

    char s[] = "12.456";
    double value = atof(s);
    printf("%f",value);
    return 0;
}

double atof(char s[]){
    double val, power;
    int i, sign, sign2, exp;
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;
    if(s[i] == 'e'|| s[i] == "E"){
        i++;
    sign2 = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(exp = 0; isdigit(s[i]); i++){
        exp = 10 * exp + (s[i] - '0');
    }
    if(sign2 == 1)
        while(exp-- > 0)
            val *= 10;
    else
        while(exp-- > 0)
            val /= 10;
    }
    return val;
}

