#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "./VMemory.hpp"
#include "../Quadruples/Quadruple.hpp"
#include "./Constant.hpp"
#include "./Function.hpp"
#include "../Semantics/Type.hpp"
#include "../Semantics/Operator.hpp"

struct VirtualMachine {
    VMemory *globalMemory;
    VMemory *tempMemory;
    VMemory *cteMemory;

    vector<Quadruple> quads;
    vector<Function> functions;
    vector<Constant> constants;

    VirtualMachine(vector<Function> functions, vector<Constant> constants, vector<Quadruple> quads) {
        this->quads = vector<Quadruple>({Quadruple()});
        this->quads.insert(this->quads.end(), quads.begin(), quads.end());
        this->functions = functions;
        this->constants = constants;

        globalMemory = new VMemory(functions[0].localVals[0], functions[0].localVals[1], functions[0].localVals[2], functions[0].memoryOffset, functions[0].memoryOffset + 2000, functions[0].memoryOffset + 2000 * 2);
        tempMemory = new VMemory(functions[0].tempVals[0], functions[0].tempVals[1], functions[0].tempVals[2], functions[0].memoryOffset + 2000 * 3, functions[0].memoryOffset + 2000 * 3 + 4000, functions[0].memoryOffset + 2000 * 3 + 4000 * 2);
        cteMemory = new VMemory(functions[0].cteVals[0], functions[0].cteVals[1], functions[0].cteVals[2], functions[0].memoryOffset + 2000 * 3 + 4000 * 3, functions[0].memoryOffset + 2000 * 3 + 4000 * 3 + 2000, functions[0].memoryOffset + 2000 * 3 + 4000 * 3 + 2000 * 2);
    }

    VMemory *getVMemory(int address) {
        if (address < 6000)
            return globalMemory;
        if (address < 17999)
            return tempMemory;
        // if (address < 23999)
        return cteMemory;
    }

    void setValue(int address, int value) {
        getVMemory(address)->setValue(address, value);
    }

    template<typename T>
    T getValue(int address) {
        return getVMemory(address)->getValue<T>(address);
    }

    void storeFunctions() {
        return;
    }

    void storeConstants() {
        for (Constant cte : constants) {
            if (cte.type == INT_) {
                int val = stoi(cte.value);
                cteMemory->setValue(cte.address, val);
            } else if (cte.type == FLOAT_) {
                float val = stof(cte.value);
                cteMemory->setValue(cte.address, val);
            } else if (cte.type == STRING_) {
                string val = cte.value;
                cteMemory->setValue(cte.address, val);
            }
        }
    }

    int executeQuad(int pid) {
        Quadruple *quad = &quads[pid++];
        int oper = quad->oper, leftOperand = quad->leftOperand, rightOperand = quad->rightOperand, result = quad->result;
        switch(oper) {
            case EQUALS_:
                setValue(result, rightOperand);
                break;
            case ADD_:
                setValue(result, leftOperand + rightOperand);
                break;
            case SUB_:
                setValue(result, leftOperand - rightOperand);
                break;
            case MULTI_:
                setValue(result, leftOperand * rightOperand);
                break;
            case DIV_:
                setValue(result, leftOperand / rightOperand);
                break;
            case GREATER_:
                setValue(result, leftOperand > rightOperand);
                break;
            case LESS_:
                setValue(result, leftOperand < rightOperand);
                break;
            case EQUALTO_:
                setValue(result, leftOperand == rightOperand);
                break;
            case NOTEQUAL_:
                setValue(result, leftOperand != rightOperand);
                break;
            case AND_:
                setValue(result, leftOperand && rightOperand);
                break;
            case OR_:
                setValue(result, leftOperand || rightOperand);
                break;
            case GOTOF_:
                pid = leftOperand ? pid : result;
                break;
            case GOTO_:
                pid = result;
                break;
            case GOSUB_:
                break;
            case ERA_:
                break;
            case PARAM_:
                break;
            case ENDFUNC_:
                break;
            case PRINT_:
                cout << rightOperand << endl;
                break;
            case RETURN_:
                break;
            case END_:
                pid = -1;
                break;
        }
        return pid;
    }

    void executeQuads() {
        int pid = 1;
        while (executeQuad(pid) != -1);
    }

    void run() {
        storeFunctions();
        storeConstants();
        executeQuads();
    }
};