//
// Created by chitt on 04/04/2020.
//

#ifndef RSIC_CPU_MODEL_DATAMEMORY_H
#define RSIC_CPU_MODEL_DATAMEMORY_H


class DataMemory {
private:
    int mem[1028];
public:
    int read(int addr){return mem[addr];}
    void write(int writeData,int addr,bool writeenable);
};


#endif //RSIC_CPU_MODEL_DATAMEMORY_H
