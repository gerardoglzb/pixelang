#include <iostream>
using namespace std;

struct VariableTable {
    string name;
    string type;
    string kind;
    VariableTable *scope;
};