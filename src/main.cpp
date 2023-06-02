#include "../include/VirtualMachine/VirtualMachine.hpp"
#include <chrono>
using namespace std;

void buildQuad(string line, vector<Quadruple> *quads) {
    stringstream stream(line);
    string item[4];
    int idx = 0;
    while (getline(stream, item[idx++], ','));
    for (int i = 0; i < 4; i++) {
        item[i] = item[i].substr(0, item[i].length());
    }
    quads->push_back(Quadruple(item));
}

void buildConstant(string line, vector<Constant> *constants, int *type) {
    stringstream stream(line);
    string value, address;
    getline(stream, value, ',');
    getline(stream, address, ',');
    if (value == "%") {
        (*type)++;
        return;
    }
    constants->push_back(Constant(value, stoi(address), *type));
}

void buildFunction(string line, vector<Function> *functions) {
    stringstream stream(line);
    string item[17];
    int idx = 0;
    while (getline(stream, item[idx++], ','));
    for (int i = 0; i < 17; i++) {
        item[i] = item[i].substr(0, item[i].length());
    }
    functions->push_back(Function(item));
}

void printMemoryFrameUsed(int vals[4], ofstream &file, string frameName) {
    file << frameName << " variables:" << endl;
    file << "Integers: " << vals[0] << endl;
    file << "Floats: " << vals[1] << endl;
    file << "Strings: " << vals[2] << endl;
    file << "Booleans: " << vals[3] << endl << endl;
}

void printMemoryUsed(Function* function, ofstream &file, string scope) {
    printMemoryFrameUsed(function->localVals, file, scope);
    printMemoryFrameUsed(function->tempVals, file, scope + " temp");
    printMemoryFrameUsed(function->cteVals, file, scope + " const");
    file << scope << " image variables: " << function->imageVals << endl << endl;
}

void printMemoryUsed(vector<Function> *functions, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "MAIN FUNCTION: " << endl << endl;
        printMemoryUsed(&(*functions)[0], file, "Global");
        for (int i = 1; i < functions->size(); i++) {
            file << "FUNCTION " << i << ":" << endl << endl;
            printMemoryUsed(&(*functions)[i], file, "Local");
        }
        file.close();
    }
}

void printExecutionTime(chrono::high_resolution_clock::time_point start) {
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double milliseconds = duration.count() * 1000.0;
    cout << "Execution time: " << milliseconds << " ms." << endl;
}

int main() {
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    vector<Quadruple> quads;
    vector<Constant> constants;
    vector<Function> functions;

    ifstream file("./bin/quads.txt");
    if (!file.is_open()) {
        cout << "No quads.txt file found" << endl;
        exit(-1);
    }

    string line;
    int step = 0;
    int type = 0;
    string filename;
    getline(file, filename);
    while (getline(file, line)) {
        if (line == "%%") {
            step++;
            continue;
        }
        if (step == 0) {
            buildFunction(line, &functions);
        } else if (step == 1) {
            buildConstant(line, &constants, &type);
        } else {
            buildQuad(line, &quads);
        }
    }
    file.close();

    VirtualMachine vm = VirtualMachine(functions, constants, quads, filename, "./output/execution.txt");
    cout << "Running '" << filename << "':" << endl;
    vm.run();
    printExecutionTime(start);
    printMemoryUsed(&functions, "./output/memory.txt");
}