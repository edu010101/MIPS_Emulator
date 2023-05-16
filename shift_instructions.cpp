#include <bits/stdc++.h>
using namespace std;

struct cpu_register{
        string name;
        int value = 0;
    };

void sll(int rd, int rt, int shamt, cpu_register *registers){
    registers[rd].value = registers[rt].value << shamt;
}

void srl(int rd, int rt, int shamt, cpu_register *registers){
    registers[rd].value = registers[rt].value >> shamt;
}

void sra(int rd, int rt, int shamt, cpu_register *registers){
    registers[rd].value = registers[rt].value >> shamt;
}