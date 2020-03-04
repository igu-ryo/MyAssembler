#ifndef _INCLUDE_SYMBOLTABLE_
#define _INCLUDE_SYMBOLTABLE_

typedef struct{
    char symbol[30];
    int address;
} symbol_adress;

extern symbol_adress symbol_table[50];
extern int symbol_size;
extern int added_size;
extern int start_address;

void symboltable_construct();
void addEntry(char symbol[], int address, int loop2flg);
int contains(char symbol[]);
int getAddress(char symbol[]);

#endif