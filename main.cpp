#include <bits/stdc++.h>
#include "bin_to_MIPS.cpp"
#include "emulator.cpp" 
using namespace std;

int main(int argc, char *argv[])
{
    const char* arquivo_binario1 = argv[1];
    const char* arquivo_binario2 = argv[2];

    if (argc != 3) {
        cout << "Erro: numero de argumentos invalido.\n";
        return 1;
    }

    FILE *text_file = fopen(arquivo_binario1, "rb");
    FILE *data_file = fopen(arquivo_binario2, "rb");
    bitset<32> current_instruction;
    MIPS_instruction MIPS_current_instruction;

    if (text_file == NULL || data_file == NULL) {
        cout << "Deu erro.\n";
        return 1;
    }

    MipsEmulator emulator(text_file, data_file);

    emulator.run_program();    
    cout << endl;
    emulator.print_registers();
    emulator.print_memory();

    return 0;
}
