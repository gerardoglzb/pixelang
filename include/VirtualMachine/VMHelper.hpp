#include <iostream>
#include <string>
using namespace std;

struct VMHelper {
    int oper, leftOperandAddress, rightOperandAddress, resultAddress;
    int leftType, rightType;
    VFunctionMemory *memory;

    VMHelper(int oper, int leftOperandAddress, int rightOperandAddress, int resultAddress, VFunctionMemory *memory) {
        this->oper = oper;
        this->leftOperandAddress = leftOperandAddress;
        this->rightOperandAddress = rightOperandAddress;
        this->resultAddress = resultAddress;
        this->memory = memory;
        this->leftType = getType(leftOperandAddress);
        this->rightType = getType(rightOperandAddress);
    }

    void printValues() {
        cout << oper << " " << leftOperandAddress << " " << rightOperandAddress << " " << resultAddress << endl;
    }

    int getType(int address) {
        if (address < -1) { // TODO: space for pointers
            return memory->getType(memory->getVMemory(-address)->getValueInt(-address));
        }
        return memory->getType(address);
    }

    int getType(int address, VFunctionMemory *functionMemory) {
        if (address < -1) {
            return functionMemory->getType(functionMemory->getVMemory(-address)->getValueInt(-address));
        }
        return functionMemory->getType(address);
    }

    int getValueInt(int address) {
        if (address < -1) {
            return getVMemory(address)->getValueInt(memory->getVMemory(-address)->getValueInt(-address));
        }
        return getVMemory(address)->getValueInt(address);
    }

    float getValueFloat(int address) {
        if (address < -1) {
            return getVMemory(address)->getValueFloat(memory->getVMemory(-address)->getValueInt(-address));
        }
        return getVMemory(address)->getValueFloat(address);
    }

    string getValueString(int address) {
        if (address < -1) {
            return getVMemory(address)->getValueString(memory->getVMemory(-address)->getValueInt(-address));
        }
        return getVMemory(address)->getValueString(address);
    }

    VMemory *getVMemory(int address) {
        if (address < -1) {
            return this->memory->getVMemory(this->memory->getVMemory(-address)->getValueInt(-address));
        }
        return this->memory->getVMemory(address);
    }

    VMemory *getVMemory(int address, VFunctionMemory *functionMemory) {
        if (address < -1) {
            return functionMemory->getVMemory(this->memory->getVMemory(-address)->getValueInt(-address));
        }
        return functionMemory->getVMemory(address);
    }

    template<typename T>
    void setValue(int address, T value) {
        if (address < -1) {
            this->memory->setValue(this->memory->getVMemory(-address)->getValueInt(-address), value);
            return;
        }
        this->memory->setValue(address, value);
    }

    template<typename T>
    void setValue(int address, T value, VFunctionMemory *functionMemory) {
        if (address < -1) {
            functionMemory->setValue(functionMemory->getVMemory(-address)->getValueInt(-address), value);
            return;
        }
        functionMemory->setValue(address, value);
    }

    void executeEquals() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (getType(resultAddress) == FLOAT_) { // TODO : asegurar float transformations en nuevas operaciones
                setValue(resultAddress, float(rightOperand));
            }
            setValue(resultAddress, rightOperand);
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            setValue(resultAddress, float(rightOperand));
        } else if (rightType == STRING_) {
            string rightOperand = getValueString(rightOperandAddress);
            setValue(resultAddress, rightOperand);
        }
    }

    void executeParam(VFunctionMemory *functionMemory) {
        if (leftType == INT_) {
            int leftOperand = getValueInt(leftOperandAddress);
            if (getType(resultAddress, functionMemory) == FLOAT_) {
                setValue(resultAddress, float(leftOperand), functionMemory);
            }
            setValue(resultAddress, leftOperand, functionMemory);
        } else if (leftType == FLOAT_) {
            float leftOperand = getValueFloat(leftOperandAddress);
            setValue(resultAddress, leftOperand, functionMemory);
        } else if (leftType == STRING_) {
            string leftOperand = getValueString(leftOperandAddress);
            setValue(resultAddress, leftOperand, functionMemory);
        }
    }

    void executeAdd() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand + rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand + rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand + rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand + rightOperand));
            }
        }
    }

    void executeSub() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand - rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand - rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand - rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand - rightOperand));
            }
        }
    }

    void executeMulti() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand * rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand * rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand * rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand * rightOperand));
            }
        }
    }

    void executeDiv() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            }
        }
    }

    void executeMod() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand % rightOperand);
            }
        }
    }

    void executeGreater() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            }
        }
    }

    void executeLess() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            }
        }
    }

    void executeEqualTo() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            }
        }
    }

    void executeNotEqual() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            }
        }
    }

    void executeNot() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            setValue(resultAddress, !rightOperand);
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            setValue(resultAddress, !rightOperand);
        } // TODO : else para todos con error
    }

    void executeAnd() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            }
        }
    }

    void executeOr() {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            }
        }
    }

    int executeGotoF(int pid) {
        if (leftType == INT_) {
            int leftOperand = getValueInt(leftOperandAddress);
            return leftOperand ? pid : resultAddress;
        } else if (leftType == FLOAT_) {
            float leftOperand = getValueFloat(leftOperandAddress);
            return leftOperand ? pid : resultAddress;
        }
        return -1;
    }

    void executeReturn(VFunctionMemory *parentMemory) {
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            setValue(resultAddress, rightOperand, parentMemory);
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            setValue(resultAddress, rightOperand, parentMemory);
        } else if (rightType == STRING_) {
            string rightOperand = getValueString(rightOperandAddress);
            setValue(resultAddress, rightOperand, parentMemory);
        }
    }

    void executePrint() {
        if (rightOperandAddress == -1) {
            cout << endl;
            return;
        }
        if (rightType == INT_) {
            int rightOperand = getValueInt(rightOperandAddress);
            cout << rightOperand << " ";
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            cout << rightOperand << " ";
        } else if (rightType == STRING_) {
            string rightOperand = getValueString(rightOperandAddress);
            rightOperand = rightOperand.substr(1, rightOperand.length() - 2);
            cout << rightOperand << " ";
        }
    }

    void executeVerify() {
        int leftOperand = getValueInt(leftOperandAddress);
        if (leftOperand < rightOperandAddress || leftOperand > resultAddress) {
            printValues();
            cout << "Index out of range" << endl;
            exit(-1);
        }
    }

};