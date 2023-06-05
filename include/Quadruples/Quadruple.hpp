#include <iostream>
using namespace std;

/*
This struct represents a quadruple, containing its operator, left and right operand, and result.
It's worth noting the operands are the addresses, not the values.
*/
struct Quadruple {
    int oper; // Operator
    int leftOperand; // Left operand address
    int rightOperand; // Right operand address
    int result; // Result address

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