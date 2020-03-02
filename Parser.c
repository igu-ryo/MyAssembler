#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Parser.h"

FILE *f;
char now_command[200];

void parser_construct(char *argv[]){
    char asm_file[20];
    strcpy(asm_file, argv[1]);
    f = fopen(asm_file, "r");

    return;
}

int advance(){
    do{
        if (fgets(now_command, 200, f) == NULL) return 0;
    } while ((now_command[0] == '/' && now_command[1] == '/') || (now_command[0] == CR && now_command[1] == LF));

    return 1;
}

int commandType(char now_command[]){
    if (now_command[0] == '@') return A_COMMAND;
    else if (now_command[1] == '=') return C_COMMAND;
    else if (now_command[0] == '(') return L_COMMAND;
}

int dest(char c_command[]){
    if (c_command[0] == 'A'){
        if (c_command[1] == 'M'){
            if (c_command[2] == 'D') return AMD;
            else return AM;
        } else if (c_command[1] == 'D') return AD;
        else return A;
    } else if (c_command[0] == 'M'){
        if (c_command[1] == 'D') return MD;
        else return M;
    } else if (c_command[0] == 'D') return D;
    else return null;
}

int comp(char c_command[]){
    int i;
    for (i = 0; c_command[i] == '='; i++);
    i++;

    if (c_command[i] == '0') return z;
    else if (c_command[i] == '1') return o;
    else if (c_command[i] == '-'){
        if (c_command[i+1] == '1') return mo;
        else if (c_command[i+1] == 'D') return md;
        else if (c_command[i+1] == 'A') return ma;
        else if (c_command[i+1] == 'M') return mm;
    } else if (c_command[i] == '!'){
        if (c_command[i+1] == 'D') return nd;
        else if (c_command[i+1] == 'A') return na;
        else if (c_command[i+1] == 'M') return nm;
    } else if (c_command[i] == 'D'){
        if (c_command[i+1] == '+'){
            if (c_command[i+2] == '1') return dpo;
            else if (c_command[i+2] == 'A') return dpa;
            else if (c_command[i+2] == 'M') return dpm;
        }
    }
}