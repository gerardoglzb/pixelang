#include "../include/VirtualMachine/VirtualMachine.hpp"

int main() {
    // vector<Quadruple> quads;
    // vector<Constant> constants;
    // vector<FunctionEntry> functions;

    ifstream file("./bin/quads.txt");
    if (!file.is_open()) {
        cout << "No quads.txt file found" << endl;
        exit(-1);
    }

    string line;
    while (getline(file, line)) {
        stringstream stream(line);
        string item[4]; // Operator -> operand1 -> operand2 -> result
        int idx = 0;
        while (getline(stream, item[idx++], ','));
        for (int i = 0; i < 4; i++) {
            item[i] = item[i].substr(0, item[i].length());
        }
    }
    file.close();

    // VirtualMachine vm = VirtualMachine();
}