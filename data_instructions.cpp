#include <bits/stdc++.h>
using namespace std;

struct cpu_register{
        string name;
        int value = 0;
    };

int memory[4 * 4096];

void lw(int rt, int rs, int imm, cpu_register *registers, int *memory){
    registers[rt].value = memory[registers[rs].value + imm];
}

void lh(int rt, int rs, int imm, cpu_register *registers, int *memory){
    registers[rt].value = memory[registers[rs].value + imm];
    registers[rt].value = registers[rt].value & 0xFFFF;
    if (registers[rt].value & 0x8000){
        registers[rt].value = registers[rt].value | 0xFFFF0000;
    }
}

void lb(int rt, int rs, int imm, cpu_register *registers, int *memory){
    registers[rt].value = memory[registers[rs].value + imm];
    registers[rt].value = registers[rt].value & 0xFF;
    if (registers[rt].value & 0x80){
        registers[rt].value = registers[rt].value | 0xFFFFFF00;
    }
}

void sw(int rt, int rs, int imm, cpu_register *registers, int *memory){
    memory[registers[rs].value + imm] = registers[rt].value;
}

void sh(int rt, int rs, int imm, cpu_register *registers, int *memory){
    memory[registers[rs].value + imm] = registers[rt].value & 0xFFFF;
}

void sb(int rt, int rs, int imm, cpu_register *registers, int *memory){
    memory[registers[rs].value + imm] = registers[rt].value & 0xFF;
}

void lui(int rt, int imm, cpu_register *registers){
    registers[rt].value = imm << 16;
}

void mfhi(int rd, int rs, int rt, cpu_register *registers){
    registers[rd].value = registers[32].value;
}

void mflo(int rd, int rs, int rt, cpu_register *registers){
    registers[rd].value = registers[33].value;
}