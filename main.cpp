#include <bits/stdc++.h>
#include "bin_to_MIPS.cpp"
#include "emulator.cpp" 
using namespace std;

int main()
{
    FILE *file = fopen("mips1.bin", "rb");
    bitset<32> current_instruction;
    MIPS_instruction MIPS_current_instruction;
    MipsEmulator emulator;

    if (file == NULL)
    {
        cout << "Deu erro.\n";
        return 1;
    }
    
    fseek(file, 0L, SEEK_END);
    long int sz = ftell(file);
    fseek(file, 0, SEEK_SET);

    long int num_instructions = sz / 4;
    
    for (int i = 0; i < num_instructions; i++) {
        fread(&current_instruction, sizeof(int32_t), 1, file);
        MIPS_current_instruction = bin_to_MIPS(current_instruction);
        
        emulator.execute_instruction(MIPS_current_instruction);
    }
    emulator.print_registers();
    
    fclose(file);

    return 0;
}

// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.instruction_id << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rd << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rt << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rs << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.shamt << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.imm << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.address << "\n";