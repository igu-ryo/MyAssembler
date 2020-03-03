#ifndef _INCLUDE_SYMBOLTABLE_
#define _INCLUDE_SYMBOLTABLE_

typedef struct{
    char symbol[20];
    int address;
} symbol_adress;

extern symbol_adress symbol_table[50];

void symboltable_construct();
void addEntry(char symbol[], int address);

#endif