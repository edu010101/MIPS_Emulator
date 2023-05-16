#include <bits/stdc++.h>
using namespace std;

void lw(MIPS_instruction instruction, cpu_register *registers, int *memory){
    registers[instruction.rt].value = memory[registers[instruction.rs].value + instruction.imm];
}

void lh(MIPS_instruction instruction, cpu_register *registers, int *memory){
    registers[instruction.rt].value = memory[registers[instruction.rs].value + instruction.imm];
    registers[instruction.rt].value = registers[instruction.rt].value & 0xFFFF;
    if (registers[instruction.rt].value & 0x8000){
        registers[instruction.rt].value = registers[instruction.rt].value | 0xFFFF0000;
    }
}

void lb(MIPS_instruction instruction, cpu_register *registers, int *memory){
    registers[instruction.rt].value = memory[registers[instruction.rs].value + instruction.imm];
    registers[instruction.rt].value = registers[instruction.rt].value & 0xFF;
    if (registers[instruction.rt].value & 0x80){
        registers[instruction.rt].value = registers[instruction.rt].value | 0xFFFFFF00;
    }
}

void sw(MIPS_instruction instruction, cpu_register *registers, int *memory){
    memory[registers[instruction.rs].value + instruction.imm] = registers[instruction.rt].value;
}

void sh(MIPS_instruction instruction, cpu_register *registers, int *memory){
    memory[registers[instruction.rs].value + instruction.imm] = registers[instruction.rt].value & 0xFFFF;
}

void sb(MIPS_instruction instruction, cpu_register *registers, int *memory){
    memory[registers[instruction.rs].value + instruction.imm] = registers[instruction.rt].value & 0xFF;
}

void lui(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rt].value = instruction.imm << 16;
}

void mfhi(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[32].value;
}

void mflo(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[33].value;
}