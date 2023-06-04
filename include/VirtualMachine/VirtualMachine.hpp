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

/*
This struct is the virtual machine that executes all the instructions provided by the quads.txt object using the functions data and
constants provided by this same object file.

The "run" method essentially starts executing every given quadruple starting from quad 1 until it gets to the END_ quad.
Execution depends on the operator and uses the VMHelper struct to execute it.s

The VM contains data of all of the functions and constants, as well as all of the quads in a vector since it's accessed by index.

It also contains stacks for the functions since the scope of a function depends on the scope of the function that called it.

Other relevant methods are "createMemory" for creating a VFunctionMemory, one of which is needed for each function.
Also "storeConstants", which store all the constant values into the global constant frame.
*/
struct VirtualMachine {
    VFunctionMemory *globalMemory;

    vector<Quadruple> quads;
    vector<Function> functions;
    vector<Constant> constants;

    stack<VFunctionMemory*> subStack;
    stack<VFunctionMemory*> eraStack;
    stack<int> returnStack;

    queue<int> iparams;
    ofstream executionFile;

    VirtualMachine(vector<Function> functions, vector<Constant> constants, vector<Quadruple> quads, string filename, string executionFilename) {
        this->quads = vector<Quadruple>({Quadruple()});
        this->quads.insert(this->quads.end(), quads.begin(), quads.end());
        this->functions = functions;
        this->constants = constants;

        this->globalMemory = new VFunctionMemory(&functions[0], nullptr, "main");
        this->subStack.push(this->globalMemory);
        this->executionFile = ofstream(executionFilename);
        if (!executionFile.is_open()) {
            cout << "ERROR: Can't write to execution.txt" << endl;
            exit(-1);
        }
        this->executionFile << "PID,Operator,LeftOperand,RightOperand,Result" << endl;
    }

    void createMemory(int id) {
        eraStack.push(new VFunctionMemory(&functions[id], globalMemory));
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
            } else if (cte.type == BOOL_) {
                bool val = cte.value != "0";
                globalMemory->cteMemory->setValue(cte.address, val);
            }
        }
    }

    vector<int> pids;
    int executions = 0;
    int executeQuad(int pid) {
        executionFile << pid << ",";
        pids.push_back(pid);
        Quadruple *quad = &quads[pid++];
        int oper = quad->oper, leftOperand = quad->leftOperand, rightOperand = quad->rightOperand, result = quad->result;
        executionFile << quad->oper << "," << quad->leftOperand << "," << quad->rightOperand << "," << quad->result << endl;
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
            case GREATEREQ_:
                helper.executeGreaterEq();
                break;
            case LESSEQ_:
                helper.executeLessEq();
                break;
            case IPARAM_:
                helper.executeIParam(&iparams);
                break;
            case OPEN_:
                helper.executeOpen(&iparams);
                break;
            case SAVE_:
                helper.executeSave(&iparams);
                break;
            case GRAYSCALE_:
                helper.executeGrayscale();
                break;
            case BANDW_:
                helper.executeBlackAndWhite();
                break;
            case CHANGECOLOR_:
                helper.executeChangeColor(&iparams); // TODO: checar params
                break;
            case HFLIP_:
                helper.executeHFlip();
                break;
            case VFLIP_:
                helper.executeVFlip();
                break;
            case CROP_:
                helper.executeCrop(&iparams);
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