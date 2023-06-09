#include <bits/stdc++.h>
#include "cpu_register.cpp"
#include "syscalls.cpp"
#include "arithmetic_instructions.cpp"
#include "logic_instructions.cpp"
#include "shift_instructions.cpp"
#include "branch_instructions.cpp"
#include "data_instructions.cpp"
using namespace std;

// map that has an int as a key and a function pointer as a value
map<int8_t, void (*)(MIPS_instruction, cpu_register *)> reg_to_reg_instructions = {
    {32, add},
    {108, addi},
    {109, addiu},
    {34, sub},
    {33, addu},
    {26, mdiv},
    {24, mult},
    {36, and_},
    {112, andi},
    {37, or_},
    {115, lui},
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
    {12, syscal} 
};

map<int8_t, void (*)(MIPS_instruction, cpu_register *, int8_t *)> reg_to_mem_instructions = {
    {135, lw},
    {43, lh}, ////??????????????????????////
    {132, lb},
    {143, sw},
    {140, sb},
    {141, sh}
};

class MipsEmulator{
    public:
        int8_t memory[4 * 4096];
        cpu_register registers[35]; // register 32 is HI, register 33 is LO, register 34 is PC
        bitset<32> current_binary_instruction;
        MIPS_instruction MIPS_current_instruction;

    MipsEmulator(FILE *program_file, FILE *data_file){
        populate_registers();
        load_data_in_memory(data_file);
        load_instructions_in_memory(program_file);
    }

    void run_program(){    
        while (registers[2].value != 10 && registers[34].value < 4 * 4096){
            // printf("PC: %d\n", registers[34].value);
            current_binary_instruction = get_instruction_from_memory(registers[34].value);
            MIPS_current_instruction = bin_to_MIPS(current_binary_instruction);
            execute_instruction(MIPS_current_instruction);
            registers[34].value += 4;

            // cout << "Instruction Rs: " << MIPS_current_instruction.rs << " " << registers[MIPS_current_instruction.rs].value << endl;
            // cout << "Instruction Rt: " << MIPS_current_instruction.rt << " " << registers[MIPS_current_instruction.rt].value << endl;
            // cout << "Instruction Rd: " << MIPS_current_instruction.rd << " " <<registers[MIPS_current_instruction.rd].value << endl;
            // cout << "Instruction Shamt: " << MIPS_current_instruction.shamt << endl;
            // cout << "Instruction Imm: " << MIPS_current_instruction.imm << endl;
            // cout << "Instruction Address: " << MIPS_current_instruction.address << endl;
            
        }
        registers[34].value +=4; //We do this because the while loop will stop when the PC is at the last instruction, so we need to increment it one more time
    }

    bitset<32> get_instruction_from_memory(int address){
        bitset<32> instruction;
        uint8_t byte1 = memory[address];
        uint8_t byte2 = memory[address+1];
        uint8_t byte3 = memory[address+2];
        uint8_t byte4 = memory[address+3];

        instruction = (byte4 << 24) | (byte3 << 16) | (byte2 << 8) | byte1;
        
        return instruction;
    }


    void execute_instruction(MIPS_instruction instruction){
        if (reg_to_mem_instructions.find(instruction.instruction_id) != reg_to_mem_instructions.end()){
            reg_to_mem_instructions[instruction.instruction_id](instruction, registers, memory);
        }
        else if (reg_to_reg_instructions.find(instruction.instruction_id) != reg_to_reg_instructions.end()){
            reg_to_reg_instructions[instruction.instruction_id](instruction, registers); 
        }
        else{
            cout << "Instruction not found" << endl;
        }
    }

    void load_instructions_in_memory(FILE *program_file){
        fread(&memory[0], sizeof(int8_t), get_file_size(program_file), program_file);
    }

    void load_data_in_memory(FILE *data_file){
        fread(&memory[4 * 2048], sizeof(int8_t), get_file_size(data_file), data_file);
    }

    void populate_registers(){
        for (int i = 0; i < 35; i++){
            
            registers[i].name = "$" + to_string(i);
            registers[i].value = 0;
            
            // else if (i == 32){
            //     registers[i].name = "HI";
            //     registers[i].value = 0;
            // }
            // else if (i == 33){
            //     registers[i].name = "LO";
            //     registers[i].value = 0;
            // }
            // else if (i == 34){
            //     registers[i].name = "PC";
            //     registers[i].value = 0;
            // }
        }
        registers[-1].value = 0;
    }
    
    void print_registers(){
        for (int i = 0; i < 32; i++){
            cout << registers[i].name << "\t" << "0x" << setfill('0') << setw(8) << hex << registers[i].value << endl;
        }
    }

    static long int get_file_size(FILE *file){
        fseek(file, 0L, SEEK_END);
        long int sz = ftell(file);
        fseek(file, 0, SEEK_SET);
        return sz;
    }

    void print_memory(){
        for (int i = 0; i < 4 * 4096; i+=16){

            // make all the hexas printed as 8 digits
            //cout << "Mem[0x" << setfill('0') << setw(8) << hex << i << "]\t";
            //cout << "0x"<< setfill('0') << setw(8) << hex << int(memory[i]) << "\t";
            //cout << "0x"<< setfill('0') << setw(8) << hex << int(memory[i+4]) << "\t";
            //cout << "0x"<< setfill('0') << setw(8) << hex << int(memory[i+8]) << "\t";
            //cout << "0x"<< setfill('0') << setw(8) << hex << int(memory[i+12]) << "\t";
            //cout << endl;
            // printf("Mem[0x%08x] 0x%02x \t 0x%02x \t 0x%02x \t 0x%02x\n", i, memory[i], memory[i+1], memory[i+2], memory[i+3]);
            //cout << i << "\t";
            //cout << int(memory[i]) << "\t";
            //cout << int(memory[i+4]) << "\t";
            //cout << int(memory[i+8]) << "\t";
            //cout << int(memory[i+12]) << "\t";
            //cout << endl;

            uint8_t byte1 = memory[i];
            uint8_t byte2 = memory[i+1];
            uint8_t byte3 = memory[i+2];
            uint8_t byte4 = memory[i+3];
            uint8_t byte5 = memory[i+4];
            uint8_t byte6 = memory[i+5];
            uint8_t byte7 = memory[i+6];
            uint8_t byte8 = memory[i+7];
            uint8_t byte9 = memory[i+8];
            uint8_t byte10 = memory[i+9];
            uint8_t byte11 = memory[i+10];
            uint8_t byte12 = memory[i+11];
            uint8_t byte13 = memory[i+12];
            uint8_t byte14 = memory[i+13];
            uint8_t byte15 = memory[i+14];
            uint8_t byte16 = memory[i+15];
            
            //printf("first word: 0x%x%x%x%x\n", byte4, byte3, byte2, byte1);
            printf("Mem[0x%08x] 0x%02x%02x%02x%02x \t 0x%02x%02x%02x%02x \t 0x%02x%02x%02x%02x \t 0x%02x%02x%02x%02x\n", i, byte4, byte3, byte2, byte1, byte8, byte7, byte6, byte5, byte12, byte11, byte10, byte9, byte16, byte15, byte14, byte13);

        }
        
    }
};


