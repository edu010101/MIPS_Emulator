#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <string>
int main()
{
    FILE *f = fopen("mips1.bin", "rb");
    int8_t byte = 0;
    int8_t memoria[4096*4] = {0};
    size_t fileSize = 0;

    if (f == NULL)
    {
        printf("Deu erro.\n");
        return 1;
    }
    
    fseek(f, 0, SEEK_END);
    fileSize = ftell(f);
    fseek(f, 0, SEEK_SET);

    fread(&memoria[0], 1, fileSize, f);
    
    for (int i = 0; i < 4096*4; i++) {
        // if (i <= 10){
        printf("%hhx %hhx %hhx %hhx\n", memoria[i], memoria[i+1], memoria[i+2], memoria[i+3]);
        // }
        
    }
    
    fclose(f);
    

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
