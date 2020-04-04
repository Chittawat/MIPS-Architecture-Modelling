//
// Created by chitt on 04/04/2020.
//

#ifndef RSIC_CPU_MODEL_PROGRAMMEMORY_H
#define RSIC_CPU_MODEL_PROGRAMMEMORY_H
#include <iostream>
#include <cstring>
#include <string>
class ProgramMemory {
private:
    char mem[1028][33];
public:
    std::string fetch(int addr){return mem[addr];}
    void setdata(const char *data, int addr);
};


#endif //RSIC_CPU_MODEL_PROGRAMMEMORY_H
