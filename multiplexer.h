//
// Created by chitt on 04/04/2020.
//

#ifndef RSIC_CPU_MODEL_MULTIPLEXER_H
#define RSIC_CPU_MODEL_MULTIPLEXER_H

class multiplexer{
public:
    int mux(int a,int b,bool m){
        return m?b:a;
    }
};

#endif //RSIC_CPU_MODEL_MULTIPLEXER_H
