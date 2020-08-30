//
// Created by chitt on 30/08/2020.
//

#ifndef RSIC_CPU_MODEL_ASSEMBLER_H
#define RSIC_CPU_MODEL_ASSEMBLER_H

#include <sstream>
#include <string>
#include <iostream>
#include<cmath>

using namespace std;
string addressConversion(string sample){
    int assignValue;
    char store = sample[0];
    string result="";
    if(store=='#'){
        sample.replace(0,1,"");
        stringstream ssIn(sample);
        ssIn>>assignValue;
        for(int i=15;i>=0;i--){
            int x=pow(2,i);
            if(assignValue>=x){
                result.push_back('1');
                assignValue =assignValue-x;
            }else{
                result.push_back('0');
            }
        }
    } else if(store=='R') {
        sample.replace(0,1,"");
        stringstream ssIn(sample);
        ssIn>>assignValue;
        for (int i = 4; i >= 0; i--) {
            int x = pow(2, i);
            if (assignValue >= x) {
                result.push_back('1');
                assignValue = assignValue - x;
            } else {
                result.push_back('0');
            }
        }
    }else {
        stringstream ssIn(sample);
        ssIn>>assignValue;
        for (int i = 4; i >= 0; i--) {
            int x = pow(2, i);
            if (assignValue >= x) {
                result.push_back('1');
                assignValue = assignValue - x;
            } else {
                result.push_back('0');
            }
        }
    }
    return result;
}

string assembler(string code){
    stringstream ssIn(code),ssOut;
    string opt,r1,r2,r3;
    ssIn>>opt>>r1>>r2>>r3;
    r1=addressConversion(r1);
    r2=addressConversion(r2);
    r3=addressConversion(r3);
    if     (opt=="SYSOUT")  {ssOut<<"00000000000000000000000000000000";}
        //R-Instruction
    else if(opt=="SLL"   )  {ssOut<<"000000"<<"00000"<<r2<<r1<<r3<<"000000";}
    else if(opt=="SRL"   )  {ssOut<<"000000"<<"00000"<<r2<<r1<<r3<<"000001";}
    else if(opt=="SLA"   )  {ssOut<<"000000"<<"00000"<<r2<<r1<<r3<<"000010";}
    else if(opt=="SRA"   )  {ssOut<<"000000"<<"00000"<<r2<<r1<<r3<<"000011";}
    else if(opt=="SLLV"  )  {ssOut<<"000000"<<r3<<r2<<r1<<"00000"<<"000100";}
    else if(opt=="SRLV"  )  {ssOut<<"000000"<<r3<<r2<<r1<<"00000"<<"000101";}//fault
    else if(opt=="ADD"   )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"100000";}
    else if(opt=="ADDU"  )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"100001";}
    else if(opt=="SUB"   )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"100010";}
    else if(opt=="SUBU"  )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"100011";}
    else if(opt=="AND"   )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"100100";}
    else if(opt=="ORR"   )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"100101";}
    else if(opt=="EOR"   )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"100110";}
    else if(opt=="SLT"   )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"101010";}
    else if(opt=="SLTU"  )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"101011";}
    else if(opt=="MUL"   )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"110000";}
    else if(opt=="MULU"  )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"110001";}
    else if(opt=="DIV"   )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"110010";}
    else if(opt=="DIVU"  )  {ssOut<<"000000"<<r2<<r3<<r1<<"00000"<<"110011";}
        //I-Instruction
    else if(opt=="ADDI"  )  {ssOut<<"001000"<<r2<<r1<<r3;}
    else if(opt=="ADDIU" )  {ssOut<<"001001"<<r2<<r1<<r3;}
    else if(opt=="SLTI"  )  {ssOut<<"001010"<<r2<<r1<<r3;}
    else if(opt=="SLTIU" )  {ssOut<<"001011"<<r2<<r1<<r3;}
    else if(opt=="ANDI"  )  {ssOut<<"001100"<<r2<<r1<<r3;}
    else if(opt=="ORRI"  )  {ssOut<<"001101"<<r2<<r1<<r3;}
    else if(opt=="EORI"  )  {ssOut<<"001110"<<r2<<r1<<r3;}
    else if(opt=="LUI"   )  {ssOut<<"001111"<<"00000"<<r1<<r2;}
    else if(opt=="MOV"   )  {ssOut<<"010000"<<r1<<"00000"<<r2;}//fault
    else if(opt=="MOVS"  )  {ssOut<<"010001"<<"00000"<<r1<<r2;}
    else if(opt=="LB"    )  {ssOut<<"100000"<<r2<<r1<<r3;}//fault
    else if(opt=="LW"    )  {ssOut<<"100010"<<r2<<r1<<r3;}
    else if(opt=="SB"    )  {ssOut<<"101000"<<r2<<r1<<r3;}//fault
    else if(opt=="SW"    )  {ssOut<<"101011"<<r2<<r1<<r3;}
        //J-instruction
    else if(opt=="ZERO"  )  {ssOut<<"000010"<<"00000"<<"00000"<<"00000"<<"00000"<<"000000";}
    else if(opt=="BEQ"   )  {ssOut<<"000100"<<r1<<r2<<r3;}
    else if(opt=="BNE"   )  {ssOut<<"000101"<<r1<<r2<<r3;}
    else if(opt=="BLE"   )  {ssOut<<"000110"<<r1<<r2<<r3;}
    else if(opt=="BGT"   )  {ssOut<<"000111"<<r1<<r2<<r3;}
    else                    {ssOut<<"00000000000000000000000000000000";}
    string result=ssOut.str();
    return result;
}

#endif //RSIC_CPU_MODEL_ASSEMBLER_H
