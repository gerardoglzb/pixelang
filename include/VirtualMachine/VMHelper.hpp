#include <iostream>
#include <string>
using namespace std;

struct VMHelper {
    int oper, leftOperandAddress, rightOperandAddress, resultAddress;
    int leftType, rightType;
    VMemory *globalMemory;
    VMemory *tempMemory;
    VMemory *cteMemory;

    VMHelper(int oper, int leftOperandAddress, int rightOperandAddress, int resultAddress, VMemory *globalMemory, VMemory *tempMemory, VMemory *cteMemory) {
        this->oper = oper;
        this->leftOperandAddress = leftOperandAddress;
        this->rightOperandAddress = rightOperandAddress;
        this->resultAddress = resultAddress;
        this->leftType = getType(leftOperandAddress);
        this->rightType = getType(rightOperandAddress);
        this->globalMemory = globalMemory;
        this->tempMemory = tempMemory;
        this->cteMemory = cteMemory;
    }

    VMemory *getVMemory(int address) {
        if (address < 6000)
            return globalMemory;
        if (address < 17999)
            return tempMemory;
        // if (address < 23999)
        return cteMemory;
    }

    template<typename T>
    void setValue(int address, T value) {
        getVMemory(address)->setValue(address, value);
    }

    int getType(int address) {
        if (address == -1)
            return -1;
        int intType = globalMemory->getType(address);
        intType = (intType == -1) ? tempMemory->getType(address) : intType;
        intType = (intType == -1) ? cteMemory->getType(address) : intType;
        return intType;
    }

    void executeEquals() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (getType(resultAddress) == FLOAT_) {
                setValue(resultAddress, float(rightOperand));
            }
            setValue(resultAddress, rightOperand);
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            setValue(resultAddress, float(rightOperand));
        } else if (rightType == STRING_) {
            string rightOperand = getVMemory(rightOperandAddress)->getValueString(rightOperandAddress);
            setValue(resultAddress, rightOperand);
        }
    }

    void executeAdd() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand + rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand + rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand + rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand + rightOperand));
            }
        }
    }

    void executeSub() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand - rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand - rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand - rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand - rightOperand));
            }
        }
    }

    void executeMulti() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand * rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand * rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand * rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand * rightOperand));
            }
        }
    }

    void executeDiv() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            }
        }
    }

    void executeGreater() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            }
        }
    }

    void executeLess() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            }
        }
    }

    void executeEqualTo() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            }
        }
    }

    void executeNotEqual() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            }
        }
    }

    void executeAnd() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            }
        }
    }

    void executeOr() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            if (leftType == INT_) {
                int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            }
        }
    }

    int executeGotoF(int pid) {
        if (leftType == INT_) {
            int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
            return leftOperand ? pid : resultAddress;
        } else if (leftType == FLOAT_) {
            float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
            return leftOperand ? pid : resultAddress;
        }
        return -1;
    }

    void executePrint() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            cout << rightOperand << endl;
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            cout << rightOperand << endl;
        } else if (rightType == STRING_) {
            string rightOperand = getVMemory(rightOperandAddress)->getValueString(rightOperandAddress);
            cout << rightOperand << endl;
        }
    }
};