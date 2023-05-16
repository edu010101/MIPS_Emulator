#include <bits/stdc++.h>
using namespace std;

void and_(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[instruction.rs].value & registers[instruction.rt].value;
}

void andi(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rt].value = registers[instruction.rs].value & instruction.imm;
}

void or_(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[instruction.rs].value | registers[instruction.rt].value;
}

void ori(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rt].value = registers[instruction.rs].value | instruction.imm;
}

void slt(MIPS_instruction instruction, cpu_register *registers){
    if (registers[instruction.rs].value < registers[instruction.rt].value){
        registers[instruction.rd].value = 1;
    }
    else{
        registers[instruction.rd].value = 0;
    }
}

void slti(MIPS_instruction instruction, cpu_register *registers){
    if (registers[instruction.rs].value < instruction.imm){
        registers[instruction.rt].value = 1;
    }
    else{
        registers[instruction.rt].value = 0;
    }
}