#include <iostream>

struct Quadruple {
    int oper;
    int leftOperand;
    int rightOperand;
    int result;

    Quadruple(int oper, int leftOperand, int rightOperand, int result) {
        this->oper = oper;
        this->leftOperand = leftOperand;
        this->rightOperand = rightOperand;
        this->result = result;
    }
};