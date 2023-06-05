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
    string name; // Function ID
    VariableTable *variableTable;
    VariableTable *parameterTable;
    VariableEntry *currentParameter; // Helps traverse the parameters
    int type;
    int resultAddress; // Address where the value returned by the address will be stored
    FunctionEntry *next; // Next FunctionEntry since directory is a linked list

    Memory *localMemory;
    Memory *tempMemory;
    Memory *cteMemory;
    int memoryOffset = 0; // TODO: delete this

    int paramCount; // Number of parameters in function
    int localVarCount; // Number of local variables in table
    int tempVarCount; // Number of temporary variables used in function
    int currQuad = 1; // Quad in which the function starts
    int currentParam; // Helps traverse the parameter

    // Prints function's data to a file
    void printFunction(ofstream &file) {
        file << type << "," << resultAddress << "," << memoryOffset << "," << currQuad << ",";
        file << localMemory->getSizeInt() << "," << localMemory->getSizeFloat() << "," << localMemory->getSizeString() << "," << localMemory->getSizeBool() << ",";
        file << tempMemory->getSizeInt() << "," << tempMemory->getSizeFloat() << "," << tempMemory->getSizeString() << "," << tempMemory->getSizeBool() << ",";
        file << cteMemory->getSizeInt() << "," << cteMemory->getSizeFloat() << "," << cteMemory->getSizeString() << "," << cteMemory->getSizeBool() << ",";
        file << localMemory->getSizeImage() << endl;
    }

    // Sets currentParam to 0
    void resetParamCount() {
        currentParam = 0;
    }

    // Gets next parameter in parameter table
    VariableEntry *nextCurrentParameter() {
        currentParameter = parameterTable->head;
        int paramIdx = currentParam++;
        while (paramCount - paramIdx++ > 0) {
            if (!currentParameter->next) {
                exit(-1);
            }
            currentParameter = currentParameter->next;
        }
        return currentParam > paramCount ? nullptr : currentParameter;
    }

    void removeVariableTable() {
        if (variableTable) {
            variableTable = nullptr;
        }
    }

    // Finds address of variable
    int findAddress(string name) {
        return variableTable->findAddress(name);
    }

    // Finds type of variable
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