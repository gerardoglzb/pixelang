#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "./VFunctionMemory.hpp"
#include "../Quadruples/Quadruple.hpp"
#include "./Constant.hpp"
#include "./VMHelper.hpp"
#include "../Semantics/Operator.hpp"

struct VirtualMachine {
    VFunctionMemory *globalMemory;

    vector<Quadruple> quads;
    vector<Function> functions;
    vector<Constant> constants;

    stack<VFunctionMemory*> subStack;
    stack<VFunctionMemory*> eraStack;
    stack<int> returnStack;

    VirtualMachine(vector<Function> functions, vector<Constant> constants, vector<Quadruple> quads, string filename) {
        this->quads = vector<Quadruple>({Quadruple()});
        this->quads.insert(this->quads.end(), quads.begin(), quads.end());
        this->functions = functions;
        this->constants = constants;

        this->globalMemory = new VFunctionMemory(&functions[0], 2000, 4000, 2000, nullptr, "main");
        this->subStack.push(this->globalMemory);
        cout << filename << ":" << endl;
    }

    void createMemory(int id) {
        eraStack.push(new VFunctionMemory(&functions[id], 1000, 3000, 1000, globalMemory, "func"));
    }

    void storeConstants() {
        for (Constant cte : constants) {
            if (cte.type == INT_) {
                int val = stoi(cte.value);
                globalMemory->cteMemory->setValue(cte.address, val);
            } else if (cte.type == FLOAT_) {
                float val = stof(cte.value);
                globalMemory->cteMemory->setValue(cte.address, val);
            } else if (cte.type == STRING_) {
                string val = cte.value;
                globalMemory->cteMemory->setValue(cte.address, val);
            }
        }
    }

    vector<int> pids;
    int executions = 0;
    int executeQuad(int pid) {
        if (executions++ > 5000) {
            cout << "Too long" << endl;
            exit(-1);
        }
        // cout << "PID: " << pid << endl;
        pids.push_back(pid);
        Quadruple *quad = &quads[pid++];
        int oper = quad->oper, leftOperand = quad->leftOperand, rightOperand = quad->rightOperand, result = quad->result;
        VFunctionMemory *currMemory = subStack.top();
        VMHelper helper(oper, leftOperand, rightOperand, result, currMemory);
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
                subStack.push(eraStack.top());
                eraStack.pop();
                returnStack.push(pid);
                pid = functions[result + 1].startQuad;
                break;
            case ERA_:
                createMemory(result + 1);
                break;
            case PARAM_:
                helper.executeParam(eraStack.top());
                break;
            case ENDFUNC_:
                pid = returnStack.top(); returnStack.pop();
                break;
            case PRINT_:
                helper.executePrint();
                break;
            case RETURN_:
                subStack.pop();
                helper.executeReturn(subStack.top());
                pid = returnStack.top(); returnStack.pop();
                break;
            case END_:
                pid = -1;
                break;
                cout << "PIDS: ";
                for (int id : pids) {
                    cout << id << " ";
                }
                cout << endl;
                break;
            case VERIFY_:
                helper.executeVerify();
                break;
            case NOT_:
                helper.executeNot();
                break;
            case MOD_:
                helper.executeMod();
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
        storeConstants();
        executeQuads();
    }
};