#include<stdio.h>
#include "Parser.h"

void main(int argc, char *argv[]){
    char line[30];
    parser_construct(argv);
    while (1){
        if (!advance()) break;
        if (commandType(now_command) == A_COMMAND) printf("%s", now_command);
    }
    fclose(f);
    return;
}