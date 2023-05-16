#include <bits/stdc++.h>
using namespace std;

struct cpu_register{
        string name;
        int value = 0;
    };

void beq(int rs, int rt, int offset, cpu_register *registers){
    if (registers[rs].value == registers[rt].value){
        registers[34].value += offset;
    }
}

void bne(int rs, int rt, int offset, cpu_register *registers){
    if (registers[rs].value != registers[rt].value){
        registers[34].value += offset;
    }
}

void jump(int target, cpu_register *registers){
    registers[34].value = target;
}

void jr(int rs, int rt, int rd, cpu_register *registers){
    registers[34].value = registers[rs].value;
}

void jal(int target, cpu_register *registers){
    registers[31].value = registers[34].value;
    registers[34].value = target;
}