#include <bits/stdc++.h>
using namespace std;

void beq(MIPS_instruction instruction, cpu_register *registers){
    if (registers[instruction.rs].value == registers[instruction.rt].value){
        registers[34].value += instruction.imm * 4;
    }
}

void bne(MIPS_instruction instruction, cpu_register *registers){
    if (registers[instruction.rs].value != registers[instruction.rt].value){
        registers[34].value += instruction.imm * 4;
    }
}

void jump(MIPS_instruction instruction, cpu_register *registers){
    registers[34].value = (instruction.address * 4) - 4;
}

void jr(MIPS_instruction instruction, cpu_register *registers){
    registers[34].value = registers[instruction.rs].value;
}

void jal(MIPS_instruction instruction, cpu_register *registers){
    registers[34].value = instruction.address;
    registers[31].value = registers[34].value + 4;
}