#include <bits/stdc++.h>
using namespace std;

void syscal(int syscall_number, cpu_register *registers){
    if (syscall_number == 1){
        cout << registers[4].value;
    }
    else if (syscall_number == 4){
        cout << (char *) &memory[registers[4].value];
    }
    else if (syscall_number == 5){
        cin >> registers[2].value;
    }
    else if (syscall_number == 8){
        char *string = (char *) &memory[registers[4].value];
        cin >> string;
    }
    else if (syscall_number == 10){
        registers[34].value = -1000;
    }
    else if (syscall_number == 11){
        cout << (char) registers[4].value;
    }
    else if (syscall_number == 12){
        char character;
        cin >> character;
        registers[2].value = character;
    }
    else if (syscall_number == 34){
        cout << hex << registers[4].value;
    }
    else if (syscall_number == 35){
        cout << bitset<32>(registers[4].value);
    }
    else if (syscall_number == 36){
        cout << unsigned(registers[4].value);
    }
}   