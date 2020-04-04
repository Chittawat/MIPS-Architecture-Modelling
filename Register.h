//
// Created by chitt on 04/04/2020.
//

#ifndef RSIC_CPU_MODEL_REGISTER_H
#define RSIC_CPU_MODEL_REGISTER_H


class Register {
private:
    int reg[32];
public:
    int readData1(int readReg1){return reg[readReg1];}
    int readData2(int readReg2){return reg[readReg2];}
    void write(int writeReg,int writeData);
};


#endif //RSIC_CPU_MODEL_REGISTER_H
