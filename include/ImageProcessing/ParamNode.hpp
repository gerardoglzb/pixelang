#include <iostream>
#include <queue>

/*
Node used by parser to keep track of all the parameters that are being inserted into an image method that is being called.
It's used exclusively for image methods.

It contains a pointer to the next node since it works as part of a linked list.
*/
struct ParamNode {
    int value;
    int type;
    ParamNode *next;

    void getParams(queue<int> *params) {
        params->push(value);
        if (next)
            next->getParams(params);
    }

    ParamNode(int value, int type) {
        this->value = value;
        this->type = type;
        this->next = nullptr;
    };

    ParamNode(int value, int type, ParamNode *next) {
        this->value = value;
        this->type = type;
        this->next = next;
    };
};