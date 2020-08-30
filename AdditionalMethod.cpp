//
// Created by chitt on 30/08/2020.
//

#include "ALU.h"

int seperateBit(int lowestBit ,int highestBit,string BitData){
    int multiplier=1;
    int sum=0;
    for(int i=BitData.length()-lowestBit-1;i>=BitData.length()-highestBit-1;i--){
        if(BitData[i]=='1'){
            sum+=1*multiplier;
        }
        multiplier*=2;
        if(i==1){
            if(BitData[0]=='1'){
                sum+=1*multiplier;
            }
        }
    }
    return sum;
}