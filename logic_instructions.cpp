#include <bits/stdc++.h>
using namespace std;

struct cpu_register{
        string name;
        int value = 0;
    };

void and_(int rd, int rs, int rt, cpu_register *registers){
    registers[rd].value = registers[rs].value & registers[rt].value;
}

void andi(int rt, int rs, int imm, cpu_register *registers){
    registers[rt].value = registers[rs].value & imm;
}

void or_(int rd, int rs, int rt, cpu_register *registers){
    registers[rd].value = registers[rs].value | registers[rt].value;
}

void ori(int rt, int rs, int imm, cpu_register *registers){
    registers[rt].value = registers[rs].value | imm;
}

void slt(int rd, int rs, int rt, cpu_register *registers){
    if (registers[rs].value < registers[rt].value){
        registers[rd].value = 1;
    }
    else{
        registers[rd].value = 0;
    }
}

void slti(int rt, int rs, int imm, cpu_register *registers){
    if (registers[rs].value < imm){
        registers[rt].value = 1;
    }
    else{
        registers[rt].value = 0;
    }
}