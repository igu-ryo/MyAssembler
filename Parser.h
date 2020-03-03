#ifndef _INCLUDE_PARSER_
#define _INCLUDE_PARSER_

#define CR 13
#define LF 10

enum {
    A_COMMAND,
    C_COMMAND,
    L_COMMAND
};

enum {
    M,
    D,
    MD,
    A,
    AM,
    AD,
    AMD,
    null
};

enum {
    z,
    o,
    mo,
    d,
    a,
    nd,
    na,
    md,
    ma,
    dpo,
    apo,
    dmo,
    amo,
    dpa,
    dma,
    amd,
    danda,
    dora,
    m,
    nm,
    mm,
    mpo,
    mmo,
    dpm,
    dmm,
    mmd,
    dandm,
    dorm,
};

enum {
    JGT,
    JEQ,
    JGE,
    JLT,
    JNE,
    JLE,
    JMP
};

void parser_construct(char *argv[]);
int advance();
int commandType(char now_command[]);
void symbol(char al_command[]);
int p_dest(char c_command[]);
int p_comp(char c_command[]);
int p_jump(char c_command[]);

extern FILE *f;
extern char now_command[200];
extern int bi[16];

#endif