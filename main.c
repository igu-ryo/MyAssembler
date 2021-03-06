#include<stdio.h>
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

void c_assemble(char now_command[]);

int bi[16], loop2flg = 0, pc = 0;;

void main(int argc, char *argv[]){
    FILE *hack_fp;
    char hack_file_name[50];
    int i = 0;
    
    while (argv[1][i] != '.'){
        hack_file_name[i] = argv[1][i];
        i++;
    }
    sprintf(hack_file_name, "%s.hack", hack_file_name);

    parser_construct(argv);
    symboltable_construct();
    
    while (1){
        if (!advance()) break;

        if (commandType(now_command) == L_COMMAND) symbol(now_command, loop2flg);
        else pc++;
    }

    fclose(f);

    parser_construct(argv);

    loop2flg = 1;

    hack_fp = fopen(hack_file_name, "w");

    while (1){
        if (!advance()) break;
        if (commandType(now_command) == C_COMMAND){
            c_assemble(now_command);
        } else symbol(now_command, loop2flg);

        if (commandType(now_command) != L_COMMAND){
            for (i = 0; i < 16; i++) fprintf(hack_fp, "%d", bi[i]);
            fprintf(hack_fp, "\n");
        }
    }

    fclose(f);
    fclose(hack_fp);

    return;
}

void c_assemble(char now_command[]){
    int i, j = 0;

    c_dest(now_command);

    for (i = 0; i < 3; i++){
        bi[j] = 1;
        j++;
    }

    c_comp(now_command);
    for (i = 0; i < 7; i++){
        bi[j] = b_comp[i];
        j++;
    }

    for (i = 0; i < 3; i++){
        bi[j] = b_dest[i];
        j++;
    }

    c_jump(now_command);
    for (i = 0; i < 3; i++){
        bi[j] = b_jump[i];
        j++;
    }

    return;
}