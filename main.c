#include<stdio.h>
#include "Parser.h"

void main(int argc, char *argv[]){
    char line[30];
    int i;
    parser_construct(argv);
    for (i = 0; i < 4; i++){
        advance();
    }
    fclose(f);
    return;
}