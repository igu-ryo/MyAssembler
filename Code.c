#include<stdio.h>
#include "Parser.h"
#include "Code.h"

int b_dest[3], b_comp[7], b_jump[3];

void c_dest(char c_command[]){
    switch (p_dest(c_command))
    {
    case null:
        b_dest[0] = 0;
        b_dest[1] = 0;
        b_dest[2] = 0;
        break;
    
    case M:
        b_dest[0] = 0;
        b_dest[1] = 0;
        b_dest[2] = 1;
        break;
    
    case D:
        b_dest[0] = 0;
        b_dest[1] = 1;
        b_dest[2] = 0;
        break;
    
    case MD:
        b_dest[0] = 0;
        b_dest[1] = 1;
        b_dest[2] = 1;
        break;
    
    case A:
        b_dest[0] = 1;
        b_dest[1] = 0;
        b_dest[2] = 0;
        break;
    
    case AM:
        b_dest[0] = 1;
        b_dest[1] = 0;
        b_dest[2] = 1;
        break;
    
    case AD:
        b_dest[0] = 1;
        b_dest[1] = 1;
        b_dest[2] = 0;
        break;
    
    case AMD:
        b_dest[0] = 1;
        b_dest[1] = 1;
        b_dest[2] = 1;
        break;
    }
}

void c_comp(char c_command[]){
    switch (p_comp(c_command))
    {
    case z:
        b_comp[0] = 0;
        b_comp[1] = 1;
        b_comp[2] = 0;
        b_comp[3] = 1;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 0;
        break;
    
    case o:
        b_comp[0] = 0;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 1;
        b_comp[4] = 1;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case mo:
        b_comp[0] = 0;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 1;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 0;
        break;
    
    case d:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 1;
        b_comp[4] = 1;
        b_comp[5] = 0;
        b_comp[6] = 0;
        break;
    
    case a:
        b_comp[0] = 0;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 0;
        b_comp[6] = 0;
        break;
    
    case nd:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 1;
        b_comp[4] = 1;
        b_comp[5] = 0;
        b_comp[6] = 1;
        break;
    
    case na:
        b_comp[0] = 0;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 0;
        b_comp[6] = 1;
        break;
    
    case md:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 1;
        b_comp[4] = 1;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case ma:
        b_comp[0] = 0;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case dpo:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 1;
        b_comp[3] = 1;
        b_comp[4] = 1;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case apo:
        b_comp[0] = 0;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 1;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case dmo:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 1;
        b_comp[4] = 1;
        b_comp[5] = 1;
        b_comp[6] = 0;
        break;
    
    case amo:
        b_comp[0] = 0;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 0;
        break;
    
    case dpa:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 0;
        break;
    
    case dma:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case amd:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 0;
        b_comp[4] = 1;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case danda:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 0;
        b_comp[6] = 0;
        break;
    
    case dora:
        b_comp[0] = 0;
        b_comp[1] = 0;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 1;
        b_comp[5] = 0;
        b_comp[6] = 1;
        break;
    
    case m:
        b_comp[0] = 1;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 0;
        b_comp[6] = 0;
        break;
    
    case nm:
        b_comp[0] = 1;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 0;
        b_comp[6] = 1;
        break;
    
    case mm:
        b_comp[0] = 1;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case mpo:
        b_comp[0] = 1;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 1;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case mmo:
        b_comp[0] = 1;
        b_comp[1] = 1;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 0;
        break;
    
    case dpm:
        b_comp[0] = 1;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 0;
        break;
    
    case dmm:
        b_comp[0] = 1;
        b_comp[1] = 0;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case mmd:
        b_comp[0] = 1;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 0;
        b_comp[4] = 1;
        b_comp[5] = 1;
        b_comp[6] = 1;
        break;
    
    case dandm:
        b_comp[0] = 1;
        b_comp[1] = 0;
        b_comp[2] = 0;
        b_comp[3] = 0;
        b_comp[4] = 0;
        b_comp[5] = 0;
        b_comp[6] = 0;
        break;
    
    case dorm:
        b_comp[0] = 1;
        b_comp[1] = 0;
        b_comp[2] = 1;
        b_comp[3] = 0;
        b_comp[4] = 1;
        b_comp[5] = 0;
        b_comp[6] = 1;
        break;
    }
}

void c_jump(char c_command){
    switch (p_jump(c_command))
    {
    case null:
        b_jump[0] = 0;
        b_jump[1] = 0;
        b_jump[2] = 0;
        break;

    case JGT:
        b_jump[0] = 0;
        b_jump[1] = 0;
        b_jump[2] = 1;
        break;

    case JEQ:
        b_jump[0] = 0;
        b_jump[1] = 1;
        b_jump[2] = 0;
        break;

    case JGE:
        b_jump[0] = 0;
        b_jump[1] = 1;
        b_jump[2] = 1;
        break;

    case JLT:
        b_jump[0] = 1;
        b_jump[1] = 0;
        b_jump[2] = 0;
        break;

    case JNE:
        b_jump[0] = 1;
        b_jump[1] = 0;
        b_jump[2] = 1;
        break;

    case JLE:
        b_jump[0] = 1;
        b_jump[1] = 1;
        b_jump[2] = 0;
        break;

    case JMP:
        b_jump[0] = 1;
        b_jump[1] = 1;
        b_jump[2] = 1;
        break;
    }
}