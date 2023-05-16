#include <bits/stdc++.h>
#include "cpu_register.cpp"
#include "arithmetic_instructions.cpp"
#include "logic_instructions.cpp"
#include "shift_instructions.cpp"
#include "branch_instructions.cpp"
#include "data_instructions.cpp"
using namespace std;


// map that has an int as a key and a function pointer as a value
map<int, void (*)(MIPS_instruction, cpu_register *)> reg_to_reg_instructions = {
    {32, add},
    {108, addi},
    {109, addiu},
    {34, sub},
    {26, mdiv},
    {24, mult},
    {36, and_},
    {112, andi},
    {37, or_},
    {113, ori},
    {42, slt},
    {110, slti},
    {0, sll},
    {2, srl},
    {3, sra},
    {104, beq},
    {105, bne},
    {8, jr},
    {203, jal},
    {202, jump},
    {16, mfhi},
    {18, mflo},
    // {12, syscall} //////////??????????????????///////////
};

map<int, void (*)(MIPS_instruction, cpu_register *, int *)> reg_to_mem_instructions = {
    {135, lw},
    {43, lh}, ////??????????????????????////
    {132, lb},
    {143, sw},
    {140, sb},
    {141, sh}
};

// cpu_register registers[35];
// register 32 is HI, register 33 is LO, register 34 is PC
// int memory[4 * 4096];

class MipsEmulator{
    public:
        int memory[4 * 4096];
        cpu_register registers[35];

    MipsEmulator(){
        populate_registers();
    }

    void execute_instruction(MIPS_instruction instruction){
        if (reg_to_reg_instructions.find(instruction.instruction_id) != reg_to_reg_instructions.end()){
            reg_to_reg_instructions[instruction.instruction_id](instruction, registers);
        }
        else if (reg_to_mem_instructions.find(instruction.instruction_id) != reg_to_mem_instructions.end()){
            reg_to_mem_instructions[instruction.instruction_id](instruction, registers, memory);
        }
        else{
            cout << "Instruction not found" << endl;
        }
    }

    void populate_registers(){
        for (int i = 0; i < 35; i++){
            if (i < 32){
                registers[i].name = "R" + to_string(i);
            }
            else if (i == 32){
                registers[i].name = "HI";
            }
            else if (i == 33){
                registers[i].name = "LO";
            }
            else if (i == 34){
                registers[i].name = "PC";
            }
        }
    }

    void print_registers(){
        for (int i = 0; i < 35; i++){
            cout << registers[i].name << ": " << "0x" << setfill('0') << setw(8) << hex << registers[i].value << endl;
        }
    }
};
