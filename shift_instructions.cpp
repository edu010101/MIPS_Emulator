#include <bits/stdc++.h>
using namespace std;

void sll(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[instruction.rt].value << instruction.shamt;
}

void srl(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[instruction.rt].value >> instruction.shamt;
}

void sra(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[instruction.rt].value >> instruction.shamt;
    if (registers[instruction.rt].value & 0x80000000){
        registers[instruction.rd].value = registers[instruction.rd].value | (0xFFFFFFFF << (32 - instruction.shamt));
    }
}