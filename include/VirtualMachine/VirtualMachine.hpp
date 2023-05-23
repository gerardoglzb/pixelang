#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "./VMemory.hpp"
#include "../Quadruples/Quadruple.hpp"
#include "./Constant.hpp"
#include "./Function.hpp"

struct VirtualMachine {
    VMemory *globalMemory;
    VMemory *tempMemory;
    VMemory *cteMemory;

    VirtualMachine() {
        // globalMemory = new VMemory(globalInts, globalFloats, globalStrings, 0, 1, 2);
        // tempMemory = new VMemory(tempInts, tempFloats, tempStrings, 0, 1, 2);
        // cteMemory = new VMemory(cteInts, cteFloats, cteStrings, 0, 1, 2);
    }
};