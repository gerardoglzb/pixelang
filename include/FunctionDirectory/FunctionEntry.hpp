#include <iostream>
#include <fstream>

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
    int memoryOffset;

    int paramCount;
    int localVarCount;
    int tempVarCount;
    int currQuad = 1;
    int currentParam;

    void printFunction(ofstream &file) {
        file << type << "," << resultAddress << "," << memoryOffset << "," << currQuad << ",";
        file << localMemory->getSizeInt() << "," << localMemory->getSizeFloat() << "," << localMemory->getSizeString() << ",";
        file << tempMemory->getSizeInt() << "," << tempMemory->getSizeFloat() << "," << tempMemory->getSizeString() << ",";
        file << cteMemory->getSizeInt() << "," << cteMemory->getSizeFloat() << "," << cteMemory->getSizeString() << endl;
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

    string getID(int address) {
        return variableTable->getID(address);
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
        this->tempMemory = new Memory(3000, this->memoryOffset + 1000 * 3);
        this->cteMemory = new Memory(1000, this->memoryOffset + 1000 * 3 + 3000 * 3);
    };

    FunctionEntry(string name, int type, VariableTable *variableTable) {
        this->name = name;
        this->variableTable = variableTable;
        this->parameterTable = new VariableTable();
        this->type = type;
        this->next = nullptr;
        this->memoryOffset = 8000 * 3;
        this->localMemory = new Memory(1000, this->memoryOffset);
        this->tempMemory = new Memory(3000, this->memoryOffset + 1000 * 3);
        this->cteMemory = new Memory(1000, this->memoryOffset + 1000 * 3 + 3000 * 3);
    };

    FunctionEntry(string name, int type, VariableTable *variableTable, int localSize, int tempSize, int cteSize) {
        this->name = name;
        this->variableTable = variableTable;
        this->parameterTable = new VariableTable();
        this->type = type;
        this->next = nullptr;
        this->memoryOffset = 0;
        this->localMemory = new Memory(localSize, 0);
        this->tempMemory = new Memory(tempSize, 0 + localSize * 3);
        this->cteMemory = new Memory(cteSize, 0 + localSize * 3 + tempSize * 3);
    };
};