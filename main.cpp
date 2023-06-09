#include <bits/stdc++.h>
#include "bin_to_MIPS.cpp"
#include "emulator.cpp" 
using namespace std;

int main()
{
    FILE *text_file = fopen("bubble_text.bin", "rb");
    FILE *data_file = fopen("bubble_data.bin", "rb");
    bitset<32> current_instruction;
    MIPS_instruction MIPS_current_instruction;

    if (text_file == NULL || data_file == NULL) {
        cout << "Deu erro.\n";
        return 1;
    }

    MipsEmulator emulator(text_file, data_file);

    emulator.run_program();

    // emulator.get_instruction_from_memory(45);
    
    emulator.print_registers();

    return 0;
}

// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.instruction_id << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rd << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rt << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rs << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.shamt << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.imm << "\n";
// cout << "intrucao[" << i << "]= " << MIPS_current_instruction.address << "\n";