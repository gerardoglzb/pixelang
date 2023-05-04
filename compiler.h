#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

static stack<int> operators; // 0 equal, 1 add, 2 sub, 3 multi, 4 div
static stack<int> types;
static stack<int> operands;

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

struct ArrItem {
    void *val;
    ArrItem *next;

    ArrItem() {
        this->val = nullptr;
        this->next = nullptr;
    }

    ArrItem(void *val) {
        this->val = val;
        this->next = nullptr;
    }
};

struct VariableEntry {
    string name;
    int type;
    int address;
    VariableEntry *next;
    ArrItem *arrHead;

    VariableEntry() {
        this->name = "";
        this->type = 7;
        this->next = nullptr;
        this->arrHead = new ArrItem();
    };

    VariableEntry(string name, int type) {
        this->name = name;
        this->type = type;
        this->address = -1;
        this->next = nullptr;
        this->arrHead = new ArrItem();
    };

    VariableEntry(string name, int type, int address) {
        this->name = name;
        this->type = type;
        this->address = address;
        this->next = nullptr;
        this->arrHead = new ArrItem();
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
    stack<string> *currentFunctions;
    string global; // Si se quiere agregar nesting, se cambia esto.

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

    void removeTable(string name) {
        FunctionEntry *entry = head;
        while (entry) {
            if (entry->name == name) {
                break;
            }
            entry = entry->next;
        }
        entry->removeTable();
    }

    void insert(FunctionEntry *newEntry) {
        FunctionEntry *entry = head;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = newEntry;
    }

    bool has(string name) {
        return find(name) != NULL;
    }

    FunctionEntry *currentFunction() {
        cout << "topping " << currentFunctions->top() << endl;
        return find(currentFunctions->top());
    }

    VariableTable *currentTable() {
        return this->currentFunction()->table;
    }

    FunctionDirectory() {
        this->head = new FunctionEntry();
        this->currentFunctions = new stack<string>();
        this->global = "";
    };

    FunctionDirectory(string global) {
        this->head = new FunctionEntry();
        this->currentFunctions = new stack<string>();
        this->global = global;
    };

};

VariableEntry *declareVariable(string name, int type, VariableTable *table, int lineas);

void declareArray(string name, int type, int size, VariableTable *table, int lineas);

void declareArrays(IDNode* variable, int type, int size, VariableTable *table, int lineas);

void declareVariables(IDNode *variable, int type, VariableTable *table, int lineas);

void declareFunction(string name, int type, FunctionDirectory *funcDir, int lineas);

void declareFunction(string name, int type, FunctionDirectory *funcDir, int lineas, int localSize, int tempSize, int cteSize);

int semanticCube(int oper, int type1, int type2);

void pushOperand(int operand);

void pushOperand(float operand);

void pushOperandOfType(int operand, int type);

void pushOperandByID(string name, FunctionEntry *entry);

void pushOperator(string oper);

void doOperation(FunctionEntry *function);

template<typename T>
int storeVariableCte(T value, int type, FunctionEntry *entry) {
    return entry->cteMemory->addValue(type);
}