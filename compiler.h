#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

static stack<int> operators; // 0 equal, 1 add, 2 sub, 3 multi, 4 div, 5 greater, 6 less, 7 equal to, 8 not equal, 9 and, 10 or
static stack<int> types;
static stack<int> operands;

struct Quadruple {
    int oper;
    int leftOperand;
    int rightOperand;
    int result;

    Quadruple(int oper, int leftOperand, int rightOperand, int result) {
        this->oper = oper;
        this->leftOperand = leftOperand;
        this->rightOperand = rightOperand;
        this->result = result;
    }
};

static queue<Quadruple> quads;

template<typename T>
struct MemoryFrame {
    size_t size;
    int index;

    MemoryFrame(size_t size) {
        this->size = size;
        this->index = 0;
    }

    int addValue() {
        return index++;
    }
};

struct Memory {
    MemoryFrame<int> *memoryInt;
    MemoryFrame<float> *memoryFloat;
    MemoryFrame<string> *memoryString;

    Memory(size_t size) {
        this->memoryInt = new MemoryFrame<int>(size);
        this->memoryFloat = new MemoryFrame<float>(size);
        this->memoryString = new MemoryFrame<string>(size);
    }

    int addValue(int type) {
        if (type == 0) {
            return memoryInt->addValue();
        }
        if (type == 1) {
            return memoryFloat->addValue();
        }
        if (type == 2) {
            return memoryFloat->addValue();
        }
        return -1;
    }
};

struct VariableEntry {
    string name;
    int type;
    int address;
    int length;
    VariableEntry *next;

    VariableEntry() {
        this->name = "";
        this->type = 7;
        this->next = nullptr;
        this->length = 1;
    };

    VariableEntry(string name, int type) {
        this->name = name;
        this->type = type;
        this->address = -1;
        this->next = nullptr;
        this->length = 1;
    };

    VariableEntry(string name, int type, int address) {
        this->name = name;
        this->type = type;
        this->address = address;
        this->next = nullptr;
        this->length = 1;
    };

    VariableEntry(string name, int type, int address, int length) {
        this->name = name;
        this->type = type;
        this->address = address;
        this->next = nullptr;
        this->length = length;
    };
};

struct VariableTable {
    VariableEntry *head;
    VariableTable *parent;

    VariableEntry *find(string name) {
        VariableEntry *entry = head;
        while (entry) {
        if (entry->name == name) {
            return entry;
        }
            entry = entry->next;
        }
        return NULL;
    }

    VariableEntry *fullFind(string name) {
        VariableEntry *result = find(name);
        if (!result) {
            result = parent->find(name);
        }
        if (!result) {
            cout << "Error: Variable " << name << " is not defined." << endl;
            exit(-1);
        }
        return result;
    }

    int findAddress(string name) {
        return fullFind(name)->address;
    }

    int findType(string name) {
        return fullFind(name)->type;
    }

    void insert(VariableEntry *newEntry) {
        VariableEntry *entry = head;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
    }

    bool has(string name) {
        return find(name) != NULL;
    }

    VariableTable() {
        this->head = new VariableEntry();
        this->parent = nullptr;
    };

    VariableTable(VariableTable *parent) {
        this->head = new VariableEntry();
        this->parent = parent;
    };
};

struct IDNode {
    string name;
    IDNode *next;

    IDNode() {
        this->name = "";
        this->next = nullptr;
    };

    IDNode(string name) {
        this->name = name;
        this->next = nullptr;
    };

    IDNode(string name, IDNode *next) {
        this->name = name;
        this->next = next;
    };
};

struct FunctionEntry {
    string name;
    VariableTable *table;
    int type;
    FunctionEntry *next;

    Memory *localMemory;
    Memory *tempMemory;
    Memory *cteMemory;

    int declareTemp(int type) {
        return tempMemory->addValue(type);
    }

    void removeTable() {
        delete table;
        table = NULL;
    }

    int findAddress(string name) {
        return table->findAddress(name);
    }

    int findType(string name) {
        return table->findType(name);
    }

    FunctionEntry() {
        this->name = "";
        this->table = new VariableTable();
        this->type = 7;
        this->next = nullptr;
        this->localMemory = new Memory(1000);
        this->tempMemory = new Memory(3000);
        this->cteMemory = new Memory(1000);
    };

    FunctionEntry(string name, int type, VariableTable *table) {
        this->name = name;
        this->table = table;
        this->type = type;
        this->next = nullptr;
        this->localMemory = new Memory(1000);
        this->tempMemory = new Memory(3000);
        this->cteMemory = new Memory(1000);
    };

    FunctionEntry(string name, int type, VariableTable *table, int localSize, int tempSize, int cteSize) {
        this->name = name;
        this->table = table;
        this->type = type;
        this->next = nullptr;
        this->localMemory = new Memory(localSize);
        this->tempMemory = new Memory(tempSize);
        this->cteMemory = new Memory(cteSize);
    };
};

struct FunctionDirectory {
    FunctionEntry *head;
    FunctionEntry *main;
    unordered_set<string> previousFunctions;

    FunctionEntry *findMain() {
        return main;
    }

    FunctionEntry *find(string name) {
        FunctionEntry *entry = head;
        while (entry) {
            if (entry->name == name) {
                return entry;
            }
            entry = entry->next;
        }
        return NULL;
    }

    void remove(string name) {
        FunctionEntry *entry = head;
        FunctionEntry *prev = NULL;
        while (entry) {
            if (entry->name == name) {
                break;
            }
            prev = entry;
            entry = entry->next;
        }
        prev->next = entry->next;
        delete entry;
    }

    void insert(FunctionEntry *newEntry) {
        FunctionEntry *entry = head;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
        previousFunctions.insert(newEntry->name);
    }

    bool has(string name) {
        return find(name) != NULL;
    }

    FunctionEntry *currentFunction() {
        FunctionEntry *entry = head;
        if (!entry->next) {
            return main;
        }
        while (entry->next) {
            entry = entry->next;
        }
        return entry;
    }

    VariableTable *currentTable() {
        return this->currentFunction()->table;
    }

    FunctionDirectory() {
        this->head = new FunctionEntry();
        this->main = nullptr;
        this->previousFunctions = unordered_set<string>();
    };

};

static FunctionDirectory *funcDir;

VariableEntry *declareVariable(string name, int type, int lineas);

void declareArray(string name, int type, int size, int lineas);

void declareArrays(IDNode* variable, int type, int size, int lineas);

void declareVariables(IDNode *variable, int type, int lineas);

void declareFunction(string name, int type, int lineas);

void declareMainFunction(string name, int lineas, int localSize, int tempSize, int cteSize, FunctionDirectory *directory);

int semanticCube(int oper, int type1, int type2);

void pushOperand(int operand);

void pushOperand(float operand);

void pushOperandOfType(int operand, int type);

void pushOperandByID(string name, FunctionEntry *entry);

void pushOperator(string oper);

void doOperation();

void checkIfShouldDoOperation(vector<int> myOperators);

template<typename T>
int storeVariableCte(T value, int type, FunctionEntry *entry) {
    return entry->cteMemory->addValue(type);
}