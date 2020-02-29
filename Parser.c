#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *f;
char now_command[200];

void parser_construct(char *argv[]){
    char asm_file[20];
    strcpy(asm_file, argv[1]);
    f = fopen(asm_file, "r");
    return;
}

void advance(){
    do{
        if (fgets(now_command, 200, f) == NULL) break;
    } while((now_command[0] == '/' && now_command[1] == '/') || now_command[0] == '\n');
    printf("%s", now_command);
}