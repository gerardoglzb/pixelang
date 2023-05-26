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

    int getType(int address) {
        return memory->getType(address);
    }

    int getType(int address, VFunctionMemory *functionMemory) {
        return functionMemory->getType(address);
    }

    VMemory *getVMemory(int address) {
        return this->memory->getVMemory(address);
    }

    VMemory *getVMemory(int address, VFunctionMemory *functionMemory) {
        return functionMemory->getVMemory(address);
    }

    template<typename T>
    void setValue(int address, T value) {
        this->memory->setValue(address, value);
    }

    template<typename T>
    void setValue(int address, T value, VFunctionMemory *functionMemory) {
        functionMemory->setValue(address, value);
    }

    void executeEquals() {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            if (getType(resultAddress) == FLOAT_) { // TODO : asegurar float transformations en nuevas operaciones
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

    void executeParam(VFunctionMemory *functionMemory) {
        if (leftType == INT_) {
            int leftOperand = getVMemory(leftOperandAddress)->getValueInt(leftOperandAddress);
            if (getType(resultAddress, functionMemory) == FLOAT_) {
                setValue(resultAddress, float(leftOperand), functionMemory);
            }
            setValue(resultAddress, leftOperand, functionMemory);
        } else if (leftType == FLOAT_) {
            float leftOperand = getVMemory(leftOperandAddress)->getValueFloat(leftOperandAddress);
            setValue(resultAddress, leftOperand, functionMemory);
        } else if (leftType == STRING_) {
            string leftOperand = getVMemory(leftOperandAddress)->getValueString(leftOperandAddress);
            setValue(resultAddress, leftOperand, functionMemory);
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

    void executeReturn(VFunctionMemory *parentMemory) {
        if (rightType == INT_) {
            int rightOperand = getVMemory(rightOperandAddress)->getValueInt(rightOperandAddress);
            setValue(resultAddress, rightOperand, parentMemory);
        } else if (rightType == FLOAT_) {
            float rightOperand = getVMemory(rightOperandAddress)->getValueFloat(rightOperandAddress);
            setValue(resultAddress, rightOperand, parentMemory);
        } else if (rightType == STRING_) {
            string rightOperand = getVMemory(rightOperandAddress)->getValueString(rightOperandAddress);
            setValue(resultAddress, rightOperand, parentMemory);
        }
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