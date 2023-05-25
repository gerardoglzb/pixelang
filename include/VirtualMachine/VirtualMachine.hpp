#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "./VMemory.hpp"
#include "../Quadruples/Quadruple.hpp"
#include "./Constant.hpp"
#include "./Function.hpp"
#include "./VMHelper.hpp"
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

        globalMemory = new VMemory(functions[0].localVals[0], functions[0].localVals[1], functions[0].localVals[2], functions[0].memoryOffset, 0, 2000, 2000 * 2);
        tempMemory = new VMemory(functions[0].tempVals[0], functions[0].tempVals[1], functions[0].tempVals[2], functions[0].memoryOffset + 2000 * 3, 0, 4000, 4000 * 2);
        cteMemory = new VMemory(functions[0].cteVals[0], functions[0].cteVals[1], functions[0].cteVals[2], functions[0].memoryOffset + 2000 * 3 + 4000 * 3, 0, 2000, 2000 * 2);
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

    int executions = 0;
    int executeQuad(int pid) {
        if (executions++ > 200) {
            cout << "Too long" << endl;
            exit(-1);
        }
        Quadruple *quad = &quads[pid++];
        int oper = quad->oper, leftOperand = quad->leftOperand, rightOperand = quad->rightOperand, result = quad->result;
        VMHelper helper(oper, leftOperand, rightOperand, result, globalMemory, tempMemory, cteMemory);
        switch(oper) {
            case EQUALS_:
                helper.executeEquals();
                break;
            case ADD_:
                helper.executeAdd();
                break;
            case SUB_:
                helper.executeSub();
                break;
            case MULTI_:
                helper.executeMulti();
                break;
            case DIV_:
                helper.executeDiv();
                break;
            case GREATER_:
                helper.executeGreater();
                break;
            case LESS_:
                helper.executeLess();
                break;
            case EQUALTO_:
                helper.executeEqualTo();
                break;
            case NOTEQUAL_:
                helper.executeNotEqual();
                break;
            case AND_:
                helper.executeAnd();
                break;
            case OR_:
                helper.executeOr();
                break;
            case GOTOF_:
                pid = helper.executeGotoF(pid);
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
                helper.executePrint();
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
        while (pid != -1) {
            pid = executeQuad(pid);
        }
    }

    void run() {
        storeFunctions();
        storeConstants();
        executeQuads();
    }
};