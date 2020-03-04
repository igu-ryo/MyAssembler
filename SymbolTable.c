#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "SymbolTable.h"

symbol_adress symbol_table[50];
int symbol_size = 0;
int added_size = 0;
int start_address = 16;

void symboltable_construct(){
    strcpy(symbol_table[0].symbol, "R0");
    symbol_table[0].address = 0;
    symbol_size++;

    strcpy(symbol_table[1].symbol, "R1");
    symbol_table[1].address = 1;
    symbol_size++;
    
    strcpy(symbol_table[2].symbol, "R2");
    symbol_table[2].address = 2;
    symbol_size++;
    
    strcpy(symbol_table[3].symbol, "R3");
    symbol_table[3].address = 3;
    symbol_size++;
    
    strcpy(symbol_table[4].symbol, "R4");
    symbol_table[4].address = 4;
    symbol_size++;
    
    strcpy(symbol_table[5].symbol, "R5");
    symbol_table[5].address = 5;
    symbol_size++;
    
    strcpy(symbol_table[6].symbol, "R6");
    symbol_table[6].address = 6;
    symbol_size++;
    
    strcpy(symbol_table[7].symbol, "R7");
    symbol_table[7].address = 7;
    symbol_size++;
    
    strcpy(symbol_table[8].symbol, "R8");
    symbol_table[8].address = 8;
    symbol_size++;
    
    strcpy(symbol_table[9].symbol, "R9");
    symbol_table[9].address = 9;
    symbol_size++;
    
    strcpy(symbol_table[10].symbol, "R10");
    symbol_table[10].address = 10;
    symbol_size++;
    
    strcpy(symbol_table[11].symbol, "R11");
    symbol_table[11].address = 11;
    symbol_size++;
    
    strcpy(symbol_table[12].symbol, "R12");
    symbol_table[12].address = 12;
    symbol_size++;
    
    strcpy(symbol_table[13].symbol, "R13");
    symbol_table[13].address = 13;
    symbol_size++;
    
    strcpy(symbol_table[14].symbol, "R14");
    symbol_table[14].address = 14;
    symbol_size++;
    
    strcpy(symbol_table[15].symbol, "R15");
    symbol_table[15].address = 15;
    symbol_size++;
    
    strcpy(symbol_table[16].symbol, "SP");
    symbol_table[16].address = 0;
    symbol_size++;
    
    strcpy(symbol_table[17].symbol, "LCL");
    symbol_table[17].address = 1;
    symbol_size++;
    
    strcpy(symbol_table[18].symbol, "ARG");
    symbol_table[18].address = 2;
    symbol_size++;
    
    strcpy(symbol_table[19].symbol, "THIS");
    symbol_table[19].address = 3;
    symbol_size++;
    
    strcpy(symbol_table[20].symbol, "THAT");
    symbol_table[20].address = 4;
    symbol_size++;
    
    strcpy(symbol_table[21].symbol, "SCREEN");
    symbol_table[21].address = 16384;
    symbol_size++;
    
    strcpy(symbol_table[22].symbol, "KBD");
    symbol_table[22].address = 24576;
    symbol_size++;
    
}

void addEntry(char symbol[], int address){
    strcpy(symbol_table[symbol_size].symbol, symbol);
    symbol_table[symbol_size].address = address;
    symbol_size++;
    added_size++;
}

int contains(char symbol[]){
    int i;

    for (i = 0; i < symbol_size; i++) if (!strcmp(symbol, symbol_table[i].symbol)) return 1;

    return 0;
}

int getAddress(char symbol[]){
    int i;

    for (i = 0; i < symbol_size; i++) if (!strcmp(symbol, symbol_table[i].symbol)) return symbol_table[i].address;
}