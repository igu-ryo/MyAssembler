#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Parser.h"
#include "SymbolTable.h"

FILE *f;
char now_command[100];

void parser_construct(char *argv[]){
    char asm_file[20];
    strcpy(asm_file, argv[1]);
    f = fopen(asm_file, "r");

    return;
}

int advance(){
    char raw_command[100];
    int i, j;

    do{
        i = 0;
        j = 0;
        
        if (fgets(raw_command, 99, f) == NULL) return 0;

        while (raw_command[i] != CR){
        if (raw_command[i] != ' ') now_command[j++] = raw_command[i];
        i++;
        }

        for (i = j; i < 100; i++) now_command[i] = '\0';

        for (i = 0; (now_command[i] != '/' || now_command[i+1] != '/') && i != 98; i++);

        for (i = i; i < 100; i++) now_command[i] = '\0';
    } while (now_command[0] == '\0');

    return 1;
}

int commandType(char now_command[]){
    if (now_command[0] == '@') return A_COMMAND;
    else if (now_command[0] == '(') return L_COMMAND;
    else return C_COMMAND;
}

void symbol(char al_command[], int loop2flg){
    int i = 1;
    int j, num, quot, surplus;
    char char_num[20] = {'\0'};
    while (al_command[i] != '\0'){
        char_num[i-1] = al_command[i];
        i++;
    }

    switch (loop2flg)
    {
    case 0:
        addEntry(char_num, pc);
        break;
    
    case 1:
        

        if (commandType(al_command) == A_COMMAND){
            if (char_num[0] >= '0' && char_num[0] <= '9') num = atoi(char_num);
            else if (contains(char_num)) num = getAddress(char_num);
            else addEntry(char_num, start_address + added_size);
        }

        quot = num;
        for (i = 0, j = 15; i < 16; i++, j--){
            surplus = quot % 2;
            quot = quot / 2;
            bi[j] = surplus;
        }

        break;
    }

    return;
}

int p_dest(char c_command[]){
    int i = 0;

    while (c_command[i] != '=' && c_command[i] != '\0') i++;

    if (c_command[i] == '\0') return null;
    else if (c_command[0] == 'A'){
        if (c_command[1] == 'M'){
            if (c_command[2] == 'D') return AMD;
            else return AM;
        } else if (c_command[1] == 'D') return AD;
        else return A;
    } else if (c_command[0] == 'M'){
        if (c_command[1] == 'D') return MD;
        else return M;
    } else if (c_command[0] == 'D') return D;
}

int p_comp(char c_command[]){
    int i = 0;
    while (c_command[i] != '=' && c_command[i] != '\0') i++;

    if (c_command[i] == '\0') i = 0;
    else i++;

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
        } else if (c_command[i+1] == '-'){
            if (c_command[i+2] == '1') return dmo;
            else if (c_command[i+2] == 'A') return dma;
            else if (c_command[i+2] == 'M') return dmm;
        } else if (c_command[i+1] == '&'){
            if (c_command[i+2] == 'A') return danda;
            else if (c_command[i+2] == 'M') return dandm;
        } else if (c_command[i+1] == '|'){
            if (c_command[i+2] == 'A') return dora;
            else if (c_command[i+2] == 'M') return dorm;
        } else return d;
    } else if (c_command[i] == 'A'){
        if (c_command[i+1] == '+'){
            if (c_command[i+2] == '1') return apo;
        } else if (c_command[i+1] == '-'){
            if (c_command[i+2] == '1') return amo;
            else if (c_command[i+2] == 'D') return amd;
        } else return a;
    } else if (c_command[i] == 'M'){
        if (c_command[i+1] == '+'){
            if (c_command[i+2] == '1') return mpo;
        } else if (c_command[i+1] == '-'){
            if (c_command[i+2] == '1') return mmo;
            else if (c_command[i+2] == 'D') return mmd;
        } else return m;
    }
}

int p_jump(char c_command[]){
    int i = 0;
    while (c_command[i] != ';' && c_command[i] != '\0') i++;

    if (c_command[i] == '\0') return null;
    else i++;

    if (c_command[i+1] == 'G'){
        if (c_command[i+2] == 'T') return JGT;
        else if (c_command[i+2] == 'E') return JGE;
    } else if (c_command[i+1] == 'L'){
        if (c_command[i+2] == 'T') return JLT;
        else if (c_command[i+2] == 'E') return JLE;
    } else if (c_command[i+1] == 'E' && c_command[i+2] == 'Q') return JEQ;
    else if (c_command[i+1] == 'N' && c_command[i+2] == 'E') return JNE;
    else if (c_command[i+1] == 'M' && c_command[i+2] == 'P') return JMP;
}