#include <iostream>     // for use of cin, cout, endl
#include <string>       // for use of strings
#include <cmath>        // for use of pow(x,y) function
// NO OTHER LIBRARIES ARE ALLOWED!

using namespace std;

// function: disassemble takes in a string representing
//          an assembled MIPS instruction as a string
//          and returns the instruction itself
//
//          Level 1 difficulty: assume the input is:
//          a) legitimate (an actual MIPS instruction)
//          b) is ONLY an I-type and ONLY one of: addi, addiu, andi, ori
//          c) has only registers $t0 thru $t7 in the instruction

// helper to convert each hex digit to binary
string hexDigitToBinary(char x) {
    if (x == '0') {
        return "0000";
    }
    else if (x == '1') {
        return "0001";
    }
    else if (x == '2') {
        return "0010";
    }
    else if (x == '3') {
        return "0011";
    }
    else if (x == '4') {
        return "0100";
    }
    else if (x == '5') {
        return "0101";
    }
    else if (x == '6') {
        return "0110";
    }
    else if (x == '7') {
        return "0111";
    }
    else if (x == '8') {
        return "1000";
    }
    else if (x == '9') {
        return "1001";
    }
    else if (x == 'A') {
        return "1010";
    }
    else if (x == 'B') {
        return "1011";
    }
    else if (x == 'C') {
        return "1100";
    }
    else if (x == 'D') {
        return "1101";
    }
    else if (x == 'E') {
        return "1110";
    }
    else if (x == 'F') {
        return "1111";
    }
    return "error";
}
string disassemble( string hex ) {

    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // YOUR CODE GOES HERE!!

    // Plan: Turn hex into binary 

    string binary = "";
    for (int i = 0; i <hex.size(); i++) {
        char h = hex.at(i);
        string bin = hexDigitToBinary(h);
        binary = binary + bin;
    }

    // Split into 4 parts opcode(6), rs(5), rt(5), immediate(16)
    string opcode = binary.substr(0, 6);
    string rs = binary.substr(6, 5);
    string rt = binary.substr(11, 5);
    string immediate = binary.substr(16, 16);

    
    return immediate;  // remove stub and replace it with correct variable
}

int main() {
// Don't change any code in main() function!!

    string hex, inst;
    
    cout << "Enter your assembled instruction as a hex number: 0x";
    cin >> hex;
    
    inst = disassemble( hex );
    cout << "Your instruction is:\n" << inst << endl;

    return 0;
}
