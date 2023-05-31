#include <iostream>
#include <queue>

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