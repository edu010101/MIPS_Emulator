#include <bits/stdc++.h>
using namespace std;


struct MIPS_instruction{
        int instruction_id; //a internal id that identifies the instruction
        int rd = -1;
        int rt = -1;
        int rs = -1;
        int shamt = -1;
        int imm = -1;
        int address = -1;
};

MIPS_instruction bin_to_MIPS_R(bitset<32> bin_instruction){
    MIPS_instruction instruction;
    instruction.rs = ((bin_instruction << 6) >> 27).to_ulong();
    instruction.rt = ((bin_instruction << 11) >> 27).to_ulong();
    instruction.rd = ((bin_instruction << 16) >> 27).to_ulong();
    instruction.shamt = ((bin_instruction << 21) >> 27).to_ulong();
    instruction.instruction_id = ((bin_instruction << 26) >> 26).to_ulong();
    
    return instruction;
}

MIPS_instruction bin_to_MIPS_I(bitset<32> bin_instruction){
    MIPS_instruction instruction;
    int opcode;
    // the I instrucrion will have an internal id superior than 100
    opcode = (bin_instruction >> 26).to_ulong();
    instruction.rs = ((bin_instruction << 6) >> 27).to_ulong();
    instruction.rt = ((bin_instruction << 11) >> 27).to_ulong();
    instruction.imm = ((bin_instruction << 16) >> 16).to_ulong();
    instruction.instruction_id = opcode + 100;
    return instruction;
}

MIPS_instruction bin_to_MIPS_J(bitset<32> bin_instruction){
    MIPS_instruction instruction;
    int opcode;
    // the J instrucrion will have an internal id superior than 200
    opcode = (bin_instruction >> 26).to_ulong();
    instruction.address = ((bin_instruction << 6) >> 6).to_ulong();
    instruction.instruction_id = opcode + 200;
    return instruction;
}

char find_instruction_type(bitset<32> bin_instruction){
    char instruction_type;
    int opcode;
    opcode = (bin_instruction >> 26).to_ulong();
    if (opcode == 0){
        instruction_type = 'R';
    }
    else if (opcode == 2 || opcode == 3){
        instruction_type = 'J';
    }
    else{
        instruction_type = 'I';
    }
    return instruction_type;
}

MIPS_instruction bin_to_MIPS(bitset<32> bin_instruction){
    MIPS_instruction instruction;
    char instruction_type = find_instruction_type(bin_instruction);
    if (instruction_type == 'R'){
        instruction = bin_to_MIPS_R(bin_instruction);
    }
    else if (instruction_type == 'I'){
        instruction = bin_to_MIPS_I(bin_instruction);
    }
    else if (instruction_type == 'J'){
        instruction = bin_to_MIPS_J(bin_instruction);
    }
    return instruction;
}
