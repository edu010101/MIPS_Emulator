#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main()
{
    FILE *fp = fopen("mips1.bin", "rb");
    bitset<32> current_instruction;
    
    struct instruction{
        int instruction_id;
        string rd;
        string rt;
        string rs;
        int imm;
    };

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
        cout << "intrucao[" << i << "]= " << current_instruction << "\n";
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

    // if (opcode == 8)
    // {
    //     printf("addi(%d) %d, %d, %d\n", opcode, rs, rt, imm);
    // }

    return 0;
}