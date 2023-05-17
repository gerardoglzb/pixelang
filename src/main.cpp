#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("./bin/quads.txt");
    if (!file.is_open()) {
        cout << "No quads.txt file found" << endl;
        exit(-1);
    }

    string line;
    while (getline(file, line)) {
        cout << "First line: " << line << endl;
    }
    file.close();
}