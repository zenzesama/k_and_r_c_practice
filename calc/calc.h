#define NUMBER '0'
#define MAXVAL 100

// stack.c
void push(double);
double pop(void);

// to_postfix.c
void to_postfix(char[], char[]);

// getop.c
int getop(char *);

// getch.c
int getch(void);
void ungetch(int);
void set_exp(char *);

// atof.c
double atof(char *);
