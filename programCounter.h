//
// Created by chitt on 04/04/2020.
//

#ifndef RSIC_CPU_MODEL_PROGRAMCOUNTER_H
#define RSIC_CPU_MODEL_PROGRAMCOUNTER_H


class programCounter {
private:
    int count=0;
    int programsize;
public:
    programCounter(int programsize);
    void setcount(int newcount);
    int sendCount(){return count;}
};


#endif //RSIC_CPU_MODEL_PROGRAMCOUNTER_H
