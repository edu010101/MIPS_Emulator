#include <bits/stdc++.h>
using namespace std;

void syscal(MIPS_instruction instruction, cpu_register *registers){
    if (registers[2].value == 1){
        cout << int(registers[4].value);
    }
    else if (registers[2].value == 4){
        cout << (char *) &memory[registers[4].value] << endl;
    }
    else if (registers[2].value == 5){
        cin >> registers[2].value;
    }
    else if (registers[2].value == 8){
        char *string = (char *) &memory[registers[4].value];
        cin >> string;
    }
    else if (registers[2].value == 10){
        registers[34].value = -1000; // ends the program
    }
    else if (registers[2].value == 11){
        cout << (char) registers[4].value;
    }
    else if (registers[2].value == 12){
        char character;
        cin >> character;
        registers[2].value = character;
    }
    else if (registers[2].value == 34){
        cout << hex << registers[4].value;
    }
    else if (registers[2].value == 35){
        cout << bitset<32>(registers[4].value);
    }
    else if (registers[2].value == 36){
        cout << unsigned(registers[4].value);
    }
    if (instruction.instruction_id < 0){ // just fot he wall not complain
        cout<< ""<< endl;
    }
}   