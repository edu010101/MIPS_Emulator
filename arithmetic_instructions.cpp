#include <bits/stdc++.h>
using namespace std;


void add(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[instruction.rs].value + registers[instruction.rt].value;
}

void addi(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rt].value = registers[instruction.rs].value + instruction.imm;
}

void addiu(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rt].value = registers[instruction.rs].value + instruction.imm;
}

void sub(MIPS_instruction instruction, cpu_register *registers){
    registers[instruction.rd].value = registers[instruction.rs].value - registers[instruction.rt].value;
}

void mult(MIPS_instruction instruction, cpu_register *registers){
    long long int result = registers[instruction.rs].value * registers[instruction.rt].value;
    registers[33].value = result & 0xFFFFFFFF;
    registers[32].value = (result >> 32) & 0xFFFFFFFF;
}

void mdiv(MIPS_instruction instruction, cpu_register *registers){
    registers[33].value = registers[instruction.rs].value / registers[instruction.rt].value;
    registers[32].value = registers[instruction.rs].value % registers[instruction.rt].value;
}
