//
// Created by chitt on 04/04/2020.
//

#include "Register.h"

void Register::write(int writeReg,int writeData){
    this->reg[writeReg]=writeData;
}
