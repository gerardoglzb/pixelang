#include <iostream>
#include <fstream>

/*
This struct represents a function and contains all of its relevant data, most of which will be written into the object file.
The name of the function works as an ID of sorts to access it through the directory and make sure the name is not repeated.

It also contains a variable table and a parameter table, containing the variables and parameters of the functions. It's worth noting
the parameters are also stored in the variable table. "paramaterTable" is just to keep track of them during calls. It also helps
calculate "paramCount", the parameterCount.

Each function has three instances of Memory, representing local, temporary and constant memory spaces. These help calculate
"localVarCount" and "tempVarCount", the local variable count and temporary variable count.

Other relevant information is the type of the function, the address where the result of the function (if there is one) will be placed,
the quad where the function starts and the memory offset.
*/
struct FunctionEntry {
    string name;
    VariableTable *variableTable;
    VariableTable *parameterTable;
    VariableEntry *currentParameter;
    stack<int> paramTypes;
    int type;
    int resultAddress;
    FunctionEntry *next;

    Memory *localMemory;
    Memory *tempMemory;
    Memory *cteMemory;
    int memoryOffset = 0; // TODO: delete this

    int paramCount;
    int localVarCount;
    int tempVarCount;
    int currQuad = 1;
    int currentParam;

    void printFunction(ofstream &file) {
        file << type << "," << resultAddress << "," << memoryOffset << "," << currQuad << ",";
        file << localMemory->getSizeInt() << "," << localMemory->getSizeFloat() << "," << localMemory->getSizeString() << "," << localMemory->getSizeBool() << ",";
        file << tempMemory->getSizeInt() << "," << tempMemory->getSizeFloat() << "," << tempMemory->getSizeString() << "," << tempMemory->getSizeBool() << ",";
        file << cteMemory->getSizeInt() << "," << cteMemory->getSizeFloat() << "," << cteMemory->getSizeString() << "," << cteMemory->getSizeBool() << ",";
        file << localMemory->getSizeImage() << endl;
    }

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

    FunctionEntry() { // for head
        this->name = "";
        this->variableTable = nullptr;
        this->parameterTable = nullptr;
        this->type = 7;
        this->next = nullptr;
        this->localMemory = nullptr;
        this->tempMemory = nullptr;
        this->cteMemory = nullptr;
    };

    FunctionEntry(string name, int type, VariableTable *variableTable) { // for functions
        this->name = name;
        this->variableTable = variableTable;
        this->parameterTable = new VariableTable();
        this->type = type;
        this->next = nullptr;
        this->localMemory = new Memory(LOCAL_INT);
        this->tempMemory = new Memory(LOCAL_TEMP_INT);
        this->cteMemory = new Memory(LOCAL_CTE_INT);
    };

    FunctionEntry(string name, int type, VariableTable *variableTable, bool isMain) { // for main
        this->name = name;
        this->variableTable = variableTable;
        this->parameterTable = new VariableTable();
        this->type = type;
        this->next = nullptr;
        this->localMemory = new Memory(GLOBAL_INT);
        this->tempMemory = new Memory(GLOBAL_TEMP_INT);
        this->cteMemory = new Memory(GLOBAL_CTE_INT);
    };
};