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

    void executeQuad(Quadruple *quad) {
        int oper = quad->oper, leftOperand = quad->leftOperand, rightOperand = quad->rightOperand, result = quad->result;
        switch(oper) {
            case EQUALS_:
                break;
            case ADD_:
                break;
            case SUB_:
                break;
            case MULTI_:
                break;
            case DIV_:
                break;
            case GREATER_:
                break;
            case LESS_:
                break;
            case EQUALTO_:
                break;
            case NOTEQUAL_:
                break;
            case AND_:
                break;
            case OR_:
                break;
            case LEFTPAR_:
                break;
            case RIGHTPAR_:
                break;
            case GOTOF_:
                break;
            case GOTO_:
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
                break;
            case RETURN_:
                break;
        }
    }

    void executeQuads() {
        int pid = 1;
        executeQuad(&quads[pid-1]);
    }

    void run() {
        storeFunctions();
        storeConstants();
        executeQuads();
    }
};