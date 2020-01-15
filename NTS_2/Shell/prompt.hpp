

#ifndef PROMPT_HPP_
#define PROMPT_HPP_
#define SUCCESS 0
#define FAIL -1
#define EXIT_SUCCESS 0
#define CONTINUE 42

struct instruct
{
    const char *instr;
    void (*func)(void);
};

int shell(void);
int check_command(char *command);
void display(void);
void simulate(void);
void loop(void);
void dump(void);
void intHandler(int);
char *get_next_line(const int);
#endif 