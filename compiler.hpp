#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
#include "./Semantics/Operator.hpp"
using namespace std;

static stack<int> operators; // 0 equal, 1 add, 2 sub, 3 multi, 4 div, 5 greater, 6 less, 7 equal to, 8 not equal, 9 and, 10 or,
                            // 11 leftpar, 12 rightpar, 13 gotoF, 14 goto, 15 gosub, 16 era, 17 param, 18 endfunc, 19 print
static stack<int> types;
static stack<int> operands;
static stack<int> jumps;

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

static vector<Quadruple> quads;

template<typename T>
struct MemoryFrame {
    int size;
    int index;
    int offset;

    MemoryFrame(int size, int offset) {
        this->size = size;
        this->index = 0;
        this->offset = offset;
    }

    int addValue() {
        int temp = index;
        index++;
        return temp + offset;
    }
};

struct Memory {
    MemoryFrame<int> *memoryInt;
    MemoryFrame<float> *memoryFloat;
    MemoryFrame<string> *memoryString;

    Memory(int size, int offset) {
        this->memoryInt = new MemoryFrame<int>(size, offset);
        this->memoryFloat = new MemoryFrame<float>(size, offset + size);
        this->memoryString = new MemoryFrame<string>(size, offset + size * 2);
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

    void clean() {
        VariableEntry *entry = head;
        while (entry) {
            VariableEntry *next = entry->next;
            entry->next = nullptr;
            // delete entry;
            entry = next;
        }
    }

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
    VariableTable *variableTable;
    VariableTable *parameterTable;
    VariableEntry *currentParameter;
    stack<int> paramTypes;
    int type;
    FunctionEntry *next;

    Memory *localMemory;
    Memory *tempMemory;
    Memory *cteMemory;
    int memoryOffset;

    int paramCount;
    int localVarCount;
    int tempVarCount;
    int currQuad;
    int currentParam;

    void resetParamCount() {
        currentParam = 0;
    }

    VariableEntry *nextCurrentParameter() {
        currentParameter = parameterTable->head;
        int paramIdx = currentParam++;
        while (paramCount - paramIdx++ > 0) {
            if (!currentParameter->next)
                exit(-1);
            currentParameter = currentParameter->next;
        }
        return currentParam > paramCount ? nullptr : currentParameter;
    }

    void removeVariableTable() {
        if (!variableTable)
            return;
        // variableTable->clean();
        // delete variableTable;
        // variableTable = nullptr;
    }

    int findAddress(string name) {
        return variableTable->findAddress(name);
    }

    int findType(string name) {
        return variableTable->findType(name);
    }

    FunctionEntry() {
        this->name = "";
        this->variableTable = new VariableTable();
        this->parameterTable = new VariableTable();
        this->type = 7;
        this->next = nullptr;
        this->memoryOffset = 8000;
        this->localMemory = new Memory(1000, this->memoryOffset);
        this->tempMemory = new Memory(3000, this->memoryOffset + 1000);
        this->cteMemory = new Memory(1000, this->memoryOffset + 1000 + 3000);
    };

    FunctionEntry(string name, int type, VariableTable *variableTable) {
        this->name = name;
        this->variableTable = variableTable;
        this->parameterTable = new VariableTable();
        this->type = type;
        this->next = nullptr;
        this->memoryOffset = 8000;
        this->localMemory = new Memory(1000, this->memoryOffset);
        this->tempMemory = new Memory(3000, this->memoryOffset + 1000);
        this->cteMemory = new Memory(1000, this->memoryOffset + 3000);
    };

    FunctionEntry(string name, int type, VariableTable *variableTable, int localSize, int tempSize, int cteSize) {
        this->name = name;
        this->variableTable = variableTable;
        this->parameterTable = new VariableTable();
        this->type = type;
        this->next = nullptr;
        this->memoryOffset = 0;
        this->localMemory = new Memory(localSize, 0);
        this->tempMemory = new Memory(tempSize, 0 + localSize);
        this->cteMemory = new Memory(cteSize, 0 + localSize + tempSize);
    };
};

static FunctionEntry *currentCall;

struct FunctionDirectory {
    FunctionEntry *head;
    FunctionEntry *main;
    unordered_set<string> previousFunctions;

    FunctionEntry *findMain() {
        return main;
    }

    int getFunctionID(string name) {
        FunctionEntry *entry = head;
        int counter = 0;
        while (entry) {
            if (entry->name == name) {
                return counter;
            }
            entry = entry->next;
            counter++;
        }
        return -1;
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

    void removeVariableTable(string name) {
        FunctionEntry *entry = head;
        FunctionEntry *prev = NULL;
        while (entry) {
            if (entry->name == name) {
                break;
            }
            prev = entry;
            entry = entry->next;
        }
        if (entry) {
            entry->removeVariableTable();
        }
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

    VariableTable *currentVariableTable() {
        return this->currentFunction()->variableTable;
    }

    VariableTable *currentParameterTable() {
        return this->currentFunction()->parameterTable;
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

void declareMainFunction(string name, int lineas, FunctionDirectory *directory);

int semanticCube(int oper, int type1, int type2);

void pushOperand(int operand);

void pushOperand(float operand);

void pushOperandOfType(int operand, int type);

void pushOperandByID(string name);

void pushOperator(string oper);

void doOperation();

void checkIfShouldDoOperation(vector<int> myOperators);

int declareCte(int type);

void printQuad(Quadruple *quad, int idx);

void printQuads();

void pushOperator(int oper);

void generateIf();

void fillJumpIf();

void generateElse();

void pushJumpCurrent();

void generateWhile();

void fillJumpWhile();

void setCurrentParamCount(int count);

void setCurrentLocalVarCount(int count);

void setCurrentTempVarCount(int count);

void setCurrentCurrQuad();

void generateEndFunc();

VariableEntry *declareParameter(string name, int type, int lineas);

void verifyFunctionExists(string name, int lineas);

void generateEra(string name);

VariableEntry *nextParameter(FunctionEntry *function);

void generateParam();

void generateGosub();

void verifyParameters(string name);

void generateGosub(string name);

void setCurrentCall(string name);

void fillMain();

void generatePrint();

void resetParameterCount(string name);

void printOperands();

void printOperators();

string operatorName(int _oper);