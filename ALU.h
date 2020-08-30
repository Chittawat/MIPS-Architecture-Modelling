//
// Created by chitt on 04/04/2020.
//

#ifndef RSIC_CPU_MODEL_ALU_H
#define RSIC_CPU_MODEL_ALU_H

#include <iostream>
#include<cmath>

using namespace std;

class ALU{
public:
    int process(int input1,int input2,int func,int ALUOp,int shift);
};


#endif //RSIC_CPU_MODEL_ALU_H
