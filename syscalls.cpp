#include <bits/stdc++.h>
using namespace std;

void syscall(int syscall_number, cpu_register *registers){
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
        exit(0);
    }
    else if (syscall_number == 11){
        cout << (char) registers[4].value;
    }
    else if (syscall_number == 12){
        char character;
        cin >> character;
        registers[2].value = character;
    }
    else if (syscall_number == 13){
        cout << registers[4].value;
    }
    else if (syscall_number == 14){
        cout << registers[4].value;
    }
    else if (syscall_number == 17){
        exit(registers[4].value);
    }
    else if (syscall_number == 34){
        cout << registers[4].value;
    }
    else if (syscall_number == 35){
        cout << registers[4].value;
    }
    else if (syscall_number == 36){
        cout << registers[4].value;
    }
    else if (syscall_number == 37){
        cout << registers[4].value;
    }
    else if (syscall_number == 38){
        cout << registers[4].value;
    }
    else if (syscall_number == 39){
        cout << registers[4].value;
    }
    else if (syscall_number == 40){
        cout << registers[4].value;
    }
    else if (syscall_number == 41){
        cout << registers[4].value;
    }
    else if (syscall_number == 42){
        cout << registers[4].value;
    }
    else if (syscall_number == 43){
        cout << registers[4].value;
    }
    else if (syscall_number == 44){
        cout << registers[4].value;
    }
    else if (syscall_number == 45){
        cout << registers[4].value;
    }
    else