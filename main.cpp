#include <iostream>
#include <fstream>
#include "ProgramMemory.h"
#include "DataMemory.h"
#include "Register.h"
#include "multiplexer.h"
#include "Adder.h"
#include "programCounter.h"
#include "shiftleft.h"
#include "ALU.h"
#include "AdditionalMethod.h"
#include "internalInterconnect.h"
#include "assembler.h"
#define assembly true

using namespace std;

int main() {
    //Component Init ===================================================================================
    DataMemory ram;
    ProgramMemory rom;
    programCounter Pc(32);
    shiftLeft shiftLeft;
    Register reg;
    Adder IFadder,Exadder;
    ALU ALU;
    multiplexer WBmux,Exmux,IDmux;
//initial
    string text;
    int loadcount=0;
    ifstream MyReadFile("sample.txt");
    while (getline (MyReadFile, text)) {
        if(assembly){
            string instruction=assembler(text.c_str());
            cout<<instruction.c_str()<<endl;
            rom.setdata(instruction.c_str(),loadcount);
        }else{
            rom.setdata(text.c_str(),loadcount);
        }
        loadcount++;
    }

    //CPU Process===================================================================================
    int count=0;
    while(1){
    //Fetch Stage
    PCToRomAddressandFTAdder=Pc.sendCount();
    RomOutput=rom.fetch(PCToRomAddressandFTAdder);
    if(RomOutput=="00000000000000000000000000000000")
        break;
    //ID Stage
    regReadReg1=seperateBit(21,25,RomOutput);
    regReadReg2=seperateBit(16,20,RomOutput);
    regWriteRegR=seperateBit(11,15,RomOutput);
    func=seperateBit(0,5,RomOutput);
    shift=seperateBit(6,10,RomOutput);
    lowerInstruction=seperateBit(0,15,RomOutput);
    opt=seperateBit(26,30,RomOutput);
    //Ex stage Preset Control Signal
    ALUOp=opt;
    ALUSrc=(opt>=8)&&(opt<40);
    regDST=(opt==0);
    branch=(opt<8)&&(opt>0);
    MemToReg=(opt>=32)&&(opt<40);
    ramwrite=(opt>=40);
    //Ex Stage
    readData1ToALU=reg.readData1(regReadReg1);
    RegisterreadData2ToExmuxAndramWriteData=reg.readData2(regReadReg2);
    instructionToShiftLeft=lowerInstruction;
    ExmuxToALU=Exmux.mux(RegisterreadData2ToExmuxAndramWriteData,instructionToShiftLeft,ALUSrc);
    ALUResultToRamAddressAndWBmux=ALU.process(readData1ToALU,ExmuxToALU,func,ALUOp,shift);
    zero=ALUResultToRamAddressAndWBmux==0;
    //MEM Stage
    ram.write(RegisterreadData2ToExmuxAndramWriteData,ALUResultToRamAddressAndWBmux,ramwrite);

    //WB Stage
    ramReadDataToWBmux=ram.read(ALUResultToRamAddressAndWBmux);
    WBmuxToRegisterWriteData=WBmux.mux(ALUResultToRamAddressAndWBmux,ramReadDataToWBmux,MemToReg);
    regWriteReg=IDmux.mux(regReadReg2,regWriteRegR,regDST);
    reg.write(regWriteReg,WBmuxToRegisterWriteData);
    //Other Step
    Exmuxmode=branch&zero;
    resultFTAddertoExAdderandFTmux=IFadder.add(PCToRomAddressandFTAdder,1);
    shiftLeft2ToExAdder=shiftLeft.shift(lowerInstruction);
    resultExAddertoFTmux=Exadder.add(FTAddertoExAdder,shiftLeft2ToExAdder);
    FTmuxoutToPCIn=Exmux.mux(resultFTAddertoExAdderandFTmux,resultExAddertoFTmux,Exmuxmode);
    Pc.setcount(FTmuxoutToPCIn);
    //test
    cout<<WBmuxToRegisterWriteData<<endl;
    count++;
    }

    return 0;
}
