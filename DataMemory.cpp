//
// Created by chitt on 04/04/2020.
//

#include <iostream>
#include "DataMemory.h"

void DataMemory::write(int writeData,int addr,bool writeenable){
    if(writeenable)
        this->mem[addr]=writeData;
}
