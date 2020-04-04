//
// Created by chitt on 04/04/2020.
//

#include "ProgramMemory.h"
#include <iostream>
#include <cstring>
using namespace std;

void ProgramMemory::setdata(const char *data, int addr) {
    strcpy(this->mem[addr],data);
}