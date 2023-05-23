#include <iostream>
using namespace std;

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

    Quadruple(string item[4]) {
        this->oper = stoi(item[0]);
        this->leftOperand = stoi(item[1]);
        this->rightOperand = stoi(item[2]);
        this->result = stoi(item[3]);
    }

    Quadruple() {}
};