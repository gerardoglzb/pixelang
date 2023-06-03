#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
This struct is designed purely to help execute all the quads in the VM.
It contains the operator, left operand address, right operand address and result address, with which it obtains the types for
the operands and the values as well if needed.
Of course, it can also get and set any value by address.
*/
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

    Image *getValueImage(int address) {
        if (address < -1) {
            return getVMemory(address)->getValueImage(memory->getVMemory(-address)->getValueInt(-address));
        }
        return getVMemory(address)->getValueImage(address);
    }

    string getValueString(int address) {
        if (address < -1) {
            return getVMemory(address)->getValueString(memory->getVMemory(-address)->getValueInt(-address));
        }
        return getVMemory(address)->getValueString(address);
    }

    bool getValueBool(int address) {
        if (address < -1) {
            return getVMemory(address)->getValueBool(memory->getVMemory(-address)->getValueInt(-address));
        }
        return getVMemory(address)->getValueBool(address);
    }

    int getValueIntOrBool(int address, int type) {
        if (type == INT_)
            return getValueInt(address);
        return getValueBool(address);
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
        } else if (rightType == BOOL_) {
            bool rightOperand = getValueBool(rightOperandAddress);
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
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand + rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand + rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, float(leftOperand + rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand + rightOperand));
            }
        }
    }

    void executeSub() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand - rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand - rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, float(leftOperand - rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand - rightOperand));
            }
        }
    }

    void executeMulti() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand * rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand * rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, float(leftOperand * rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand * rightOperand));
            }
        }
    }

    void executeDiv() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, float(leftOperand / rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, float(leftOperand / rightOperand));
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, float(leftOperand / rightOperand));
            }
        }
    }

    void executeMod() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand % rightOperand);
            }
        }
    }

    void executeGreater() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand > rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand > rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand > rightOperand);
            }
        }
    }

    void executeLess() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand < rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand < rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand < rightOperand);
            }
        }
    }

    void executeGreaterEq() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand >= rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand >= rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand >= rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand >= rightOperand);
            }
        }
    }

    void executeLessEq() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand <= rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand <= rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand <= rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand <= rightOperand);
            }
        }
    }

    void executeEqualTo() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || rightType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, rightType);
                setValue(resultAddress, leftOperand == rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || rightType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, rightType);
                setValue(resultAddress, leftOperand == rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand == rightOperand);
            }
        }
    }

    void executeNotEqual() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand != rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand != rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand != rightOperand);
            }
        }
    }

    void executeNot() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            setValue(resultAddress, !rightOperand);
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            setValue(resultAddress, !rightOperand);
        } // TODO : else para todos con error
    }

    void executeAnd() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand && rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand && rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand && rightOperand);
            }
        }
    }

    void executeOr() {
        if (rightType == INT_ || rightType == BOOL_) {
            int rightOperand = getValueIntOrBool(rightOperandAddress, rightType);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
                setValue(resultAddress, leftOperand || rightOperand);
            } else if (leftType == FLOAT_) {
                float leftOperand = getValueFloat(leftOperandAddress);
                setValue(resultAddress, leftOperand || rightOperand);
            }
        } else if (rightType == FLOAT_) {
            float rightOperand = getValueFloat(rightOperandAddress);
            if (leftType == INT_ || leftType == BOOL_) {
                int leftOperand = getValueIntOrBool(leftOperandAddress, leftType);
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
        } else if (rightType == BOOL_) {
            bool rightOperand = getValueBool(rightOperandAddress);
            cout << (rightOperand ? "true" : "false") << " ";
        }
    }

    void executeVerify() {
        int leftOperand = getValueInt(leftOperandAddress);
        if (leftOperand < rightOperandAddress || leftOperand > resultAddress) {
            cout << "Index out of range" << endl;
            exit(-1);
        }
    }

    void executeIParam(queue<int> *iparams) {
        iparams->push(resultAddress);
    }

    void executeOpen(queue<int> *iparams) {
        int filenameAddress = iparams->front(); iparams->pop();
        if (getType(filenameAddress) == STRING_) {
            string filename = getValueString(filenameAddress);
            filename = filename.substr(1, filename.length() - 2);
            Image *image = new Image(filename);
            setValue(resultAddress, image);
        }
    }

    void executeSave(queue<int> *iparams) {
        int filenameAddress = iparams->front(); iparams->pop();
        if (getType(filenameAddress) == STRING_) {
            string filename = getValueString(filenameAddress);
            filename = filename.substr(1, filename.length() - 2);
            Image *image = getValueImage(resultAddress);
            image->write(filename);
        }
    }

    void executeGrayscale() {
        Image *image = getValueImage(resultAddress);
        image->grayscale();
    }

    void executeBlackAndWhite() {
        Image *image = getValueImage(resultAddress);
        image->blackAndWhite();
    }

    void executeChangeColor(queue<int> *iparams) {
        int firstAddress = iparams->front(); iparams->pop();
        if (iparams->empty()) {
            executeChangeColorHex(firstAddress);
        } else {
            executeChangeColorRGB(firstAddress, iparams);
        }
    }

    void executeChangeColorHex(int firstAddress) {
        if (getType(firstAddress) == STRING_) {
            Image *image = getValueImage(resultAddress);
            string hex = getValueString(firstAddress);
            hex = hex.substr(1, hex.length() - 2);
            image->changeColor(hex);
        }
    }

    void executeChangeColorRGB(int firstAddress, queue<int> *iparams) {
        int addresses[3];
        addresses[0] = firstAddress;
        for (int i = 1; i < 3; i++) {
            addresses[i] = iparams->front(); iparams->pop();
        }
        float r, g, b;
        if (getType(addresses[0]) == FLOAT_) {
            r = getValueFloat(addresses[0]);
        } else if (getType(addresses[0]) == INT_) {
            r = getValueInt(addresses[0]);
        }
        if (getType(addresses[1]) == FLOAT_) {
            g = getValueFloat(addresses[1]);
        } else if (getType(addresses[1]) == INT_) {
            g = getValueInt(addresses[1]);
        }
        if (getType(addresses[2]) == FLOAT_) {
            b = getValueFloat(addresses[2]);
        } else if (getType(addresses[2]) == INT_) {
            b = getValueInt(addresses[2]);
        }
        Image *image = getValueImage(resultAddress);
        image->changeColor(r, g, b);
    }

    void executeHFlip() {
        Image *image = getValueImage(resultAddress);
        image->hFlip();
    }

    void executeVFlip() {
        Image *image = getValueImage(resultAddress);
        image->vFlip();
    }

    void executeCrop(queue<int> *iparams) {
        int addresses[4];
        for (int i = 0; i < 4; i++) {
            addresses[i] = iparams->front(); iparams->pop();
        }
        float left, bottom, width, height;
        if (getType(addresses[0]) == INT_) {
            left = getValueInt(addresses[0]);
        }
        if (getType(addresses[1]) == INT_) {
            bottom = getValueInt(addresses[1]);
        }
        if (getType(addresses[2]) == INT_) {
            width = getValueInt(addresses[2]);
        }
        if (getType(addresses[2]) == INT_) {
            height = getValueInt(addresses[2]);
        }
        Image *image = getValueImage(resultAddress);
        image->crop(left, bottom, width, height);
    }
};