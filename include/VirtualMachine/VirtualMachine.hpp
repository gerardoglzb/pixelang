#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "./VMemory.hpp"
#include "../Quadruples/Quadruple.hpp"
#include "./Constant.hpp"
#include "./Function.hpp"

struct VirtualMachine {
    VMemory *globalMemory;
    VMemory *tempMemory;
    VMemory *cteMemory;

    vector<Quadruple> quads;
    vector<Function> functions;
    vector<Constant> constants;

    VirtualMachine() {
        // globalMemory = new VMemory(globalInts, globalFloats, globalStrings, 0, 1, 2);
        // tempMemory = new VMemory(tempInts, tempFloats, tempStrings, 0, 1, 2);
        // cteMemory = new VMemory(cteInts, cteFloats, cteStrings, 0, 1, 2);
    }
};