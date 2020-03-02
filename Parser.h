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
    null,
    M,
    D,
    MD,
    A,
    AM,
    AD,
    AMD
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
    null,
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
int dest(char c_command[]);
int comp(char c_command[]);

extern FILE *f;
extern char now_command[200];

#endif