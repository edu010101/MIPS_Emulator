#include <bits/stdc++.h>
using namespace std;

struct cpu_register{
        string name;
        int value = 0;
    };
    
void add(int rd, int rs, int rt, cpu_register *registers){
    registers[rd].value = registers[rs].value + registers[rt].value;
}

void addi(int rt, int rs, int imm, cpu_register *registers){
    registers[rt].value = registers[rs].value + imm;
}

void addiu(int rt, int rs, int imm, cpu_register *registers){
    registers[rt].value = registers[rs].value + imm;
}

void sub(int rd, int rs, int rt, cpu_register *registers){
    registers[rd].value = registers[rs].value - registers[rt].value;
}

void mult(int rd, int rs, int rt, cpu_register *registers){
    long long int result = registers[rs].value * registers[rt].value;
    registers[33].value = result & 0xFFFFFFFF;
    registers[32].value = (result >> 32) & 0xFFFFFFFF;
}

void mdiv(int rd, int rs, int rt, cpu_register *registers){
    registers[33].value = registers[rs].value / registers[rt].value;
    registers[32].value = registers[rs].value % registers[rt].value;
}
