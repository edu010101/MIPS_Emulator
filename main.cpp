#include <bits/stdc++.h>
#include "bin_to_MIPS.cpp"

using namespace std;

int main()
{
    FILE *fp = fopen("mips1.bin", "rb");
    bitset<32> current_instruction;
    MIPS_instruction MIPS_current_instruction;
    
    struct cpu_register{
        string name;
        int value = 0;
    };

    cpu_register registers[35];

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
    
    int memory[4 * 4096];
    int pc = 0;
    int hi = 0;
    int lo = 0;

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
        // cout << "intrucao[" << i << "]= " << hex << instrucao[i] << "\n"; // para printar em hexadecimal
        // cout << "intrucao[" << i << "]= " << current_instruction << "\n";

        MIPS_current_instruction = bin_to_MIPS(current_instruction);
        cout << "intrucao[" << i << "]= " << MIPS_current_instruction.instruction_id << "\n";
        cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rd << "\n";
        cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rt << "\n";
        cout << "intrucao[" << i << "]= " << MIPS_current_instruction.rs << "\n";
        cout << "intrucao[" << i << "]= " << MIPS_current_instruction.shamt << "\n";
        cout << "intrucao[" << i << "]= " << MIPS_current_instruction.imm << "\n";
        cout << "intrucao[" << i << "]= " << MIPS_current_instruction.address << "\n";

    }
    
    fclose(fp);
    

    //  OP     RS   RT    IMMEDIATE
    // ,--6-,,-5-,,-5-,,-------16-----, I
    // ,--6-,,-5-,,-5-,,-5-,,-5-,,--6-, R
    // ,--6-,,-----------26-----------, J
    // 11111100111111111011110100100011
    // 11111100000000000000000000000000 = 0x3f << 26
    // 00000011111000000000000000000000 = 0x1f << 21
    // 00000000000111110000000000000000 = 0x1f << 16
    // 00000000000000001111111111111111 = 0xffff
    
    //opcode = (instrucao & (0x3f << 26)) >> 26;
    //rs     = (instrucao & (0x1f << 21)) >> 21;
    //rt     = (instrucao & (0x1f << 16)) >> 16;
    //imm    = (instrucao & 0xffff);


    // opcode = (instrucao >> 26).to_ulong();
    // rs = (instrucao >> 21).to_ulong();
    // rt = (instrucao >> 16).to_ulong();
    

    // if (opcode == 8)
    // {
    //     printf("addi(%d) %d, %d, %d\n", opcode, rs, rt, imm);
    // }

    return 0;
}