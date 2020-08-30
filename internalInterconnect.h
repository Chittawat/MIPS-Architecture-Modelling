//
// Created by chitt on 30/08/2020.
//

#ifndef RSIC_CPU_MODEL_INTERNALINTERCONNECT_H
#define RSIC_CPU_MODEL_INTERNALINTERCONNECT_H

#include <iostream>

using namespace std;
//Wire init========================================================================================
//Control Signal
bool ALUSrc;
int ALUOp;
bool MemToReg=0;
bool branch;
bool zero;
bool regDST;
bool Exmuxmode;
bool ramwrite;
//Fetch
int PCToRomAddressandFTAdder;
int resultFTAddertoExAdderandFTmux;
int resultExAddertoFTmux;
int FTmuxoutToPCIn;
string RomOutput;
//Decode
int regReadReg1;
int regReadReg2;
int regWriteRegR;
int regWriteReg;
int func;
int lowerInstruction;
int opt;
int shift;
//Execute
int readData1ToALU;
int RegisterreadData2ToExmuxAndramWriteData=55;
int instructiontoCommand;
int instructionToShiftLeft;
int ExmuxToALU;
int FTAddertoExAdder;
int shiftLeft2ToExAdder;
//Memory Access
int ALUResultToRamAddressAndWBmux=0;
//WriteBack
int ramReadDataToWBmux;
int WBmuxToRegisterWriteData;

#endif //RSIC_CPU_MODEL_INTERNALINTERCONNECT_H
