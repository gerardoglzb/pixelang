#include <iostream>
#include <unordered_map>
using namespace std;

struct VariableEntry {
    string name;
    string type;
};

struct VariableTable {
    unordered_map<string, VariableEntry> table;
    VariableTable *parent;
};

struct IDNode {
    string name;
    IDNode *next;
};