#ifndef _INCLUDE_PARSER_
#define _INCLUDE_PARSER_

void parser_construct(char *argv[]);
void advance();

extern FILE *f;
extern char now_command[30];

#endif