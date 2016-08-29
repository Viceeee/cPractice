#define MAXTOKEN 100

enum{ NAME, PARENS, BRACKETS};
enum{ NO, YES};

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int prevtoken;

