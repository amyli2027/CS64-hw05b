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

string getRegister(string bin) {
    if (bin == "01000") {
        return "$t0";
    }
    else if (bin == "01001") {
        return "$t1";
    }
    else if (bin == "01010") {
        return "$t2";
    }
    else if (bin == "01011") {
        return "$t3";
    }
    else if (bin == "01100") {
        return "$t4";
    }
    else if (bin == "01101") {
        return "$t5";
    }
    else if (bin == "01110") {
        return "$t6";
    }
    else if (bin == "01111") {
        return "$t7";
    }
    else {
        return "ERROR";
    }
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

    // Can only be addi, addiu, ori, andi
    string opcodeName = "";
    // addi = 8 hex --> 001000
    if (opcode == "001000") {
        opcodeName = "addi";
    }
    else if (opcode == "001001") { //addiu = opcode 9hex = 001001
        opcodeName = "addiu";
    }
    else if (opcode == "001101") {  //ori = opcode dhex = 13 = 001101
        opcodeName = "ori";
    }
    else if (opcode == "001100") {  // andi
        opcodeName = "andi";
    }
    else { //Error check
        return "error";
    }


    //rs and rt register
    string rsName = getRegister(rs);
    string rtName = getRegister(rt);

    // immediate value, always 16 bit - start at 2^14
    int val = 0;
    if (immediate.at(0) == '0') { //positive
        for (int i = 1; i < immediate.size(); i++) {
            if (immediate.at(i) == '1') {
                val = val + pow(2, 15-i);
            }
        }
    }
    else { //negative
        // two's complement
        for (int i = 1; i < immediate.size(); i++) {
            if (immediate.at(i) == '1') {
                immediate[i] = '0';
            }
            else {
                immediate[i] = '1';
            }
        }

        // add 1
        int carryover = 1;
        for (int i = immediate.size()-1; i > 0; i--) {
            if (immediate.at(i) == '1' && carryover == 1) {
                immediate[i] = '0';
            }
            else if (immediate.at(i) == '0' && carryover == 1) {
                immediate[i] = '1';
                carryover = 0;
            }
        }

        //calculate number and add negative 
        for (int i = 1; i < immediate.size(); i++) {
            if (immediate.at(i) == '1') {
                val = val + pow(2, 15-i);
            }
        }

        val = val * -1;
    }
    
    return opcodeName + " " + rtName + ", " + rsName + ", " + to_string(val);  // remove stub and replace it with correct variable
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
