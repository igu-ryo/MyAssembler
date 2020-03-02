#include<stdio.h>
#include "Parser.h"
#include "Code.h"

void main(int argc, char *argv[]){
    char line[30];
    parser_construct(argv);
    while (1){
        if (!advance()) break;
        printf("%s", now_command);
    }
    fclose(f);
    return;
}