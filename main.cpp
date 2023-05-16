#include <bits/stdc++.h>
#include "bin_to_MIPS.cpp"
#include "emulator.cpp"
using namespace std;

int main()
{
    FILE *fp = fopen("mips1.bin", "rb");
    bitset<32> current_instruction;
    MIPS_instruction MIPS_current_instruction;
    MipsEmulator emulator;

    if (fp == NULL)
    {
        cout << "Ihhh, deu erro.\n";
        return 1;
    }
    
    fseek(fp, 0L, SEEK_END);
    long int sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    long int num_instructions = sz / 4;
    
    for (int i = 0; i < num_instructions; i++) {
        fread(&current_instruction, sizeof(int32_t), 1, fp);
        MIPS_current_instruction = bin_to_MIPS(current_instruction);
        
        emulator.execute_instruction(MIPS_current_instruction);
    }
    emulator.print_registers();
    
    fclose(fp);

    return 0;
}

// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.instruction_id << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rd << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rt << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rs << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.shamt << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.imm << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.address << "\n";