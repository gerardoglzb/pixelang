#include "../include/VirtualMachine/VirtualMachine.hpp"
using namespace std;

void buildQuad(string line, vector<Quadruple> *quads) {
    stringstream stream(line);
    string item[4]; // Operator -> operand1 -> operand2 -> result
    int idx = 0;
    while (getline(stream, item[idx++], ','));
    for (int i = 0; i < 4; i++) {
        item[i] = item[i].substr(0, item[i].length());
    }
    quads->push_back(Quadruple(item));
}

int main() {
    vector<Quadruple> quads;
    // vector<Constant> constants;
    // vector<FunctionEntry> functions;

    ifstream file("./bin/quads.txt");
    if (!file.is_open()) {
        cout << "No quads.txt file found" << endl;
        exit(-1);
    }

    string line;
    int step = 0;
    while (getline(file, line)) {
        if (line == "%%") {
            step++;
            continue;
        }
        if (step == 0) {
            // buildFunction(line);
        } else if (step == 1) {
            // buildConstant(line);
        } else {
            buildQuad(line, &quads);
        }
    }
    file.close();

    // VirtualMachine vm = VirtualMachine();
}