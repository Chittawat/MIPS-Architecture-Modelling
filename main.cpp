#include <iostream>
#include<cmath>
#include <fstream>
#include "ProgramMemory.h"
#include "DataMemory.h"
#include "Register.h"
#include "multiplexer.h"
#include "Adder.h"
#include "programCounter.h"
#include "shiftleft.h"

using namespace std;

class ALU{
public:
    int process(int input1,int input2,int func,int ALUOp,int shift){
        if(ALUOp==0){
            switch(func){
                //R-instruction
                case 0: return input2<<shift; //SLL command
                case 3: return input2>>shift; //SRA command
                case 4: return input1<<input2; // SLLV command (shiftleft variable)
                case 6: return input1>>input2; //SRLV command (shiftright variable)
                case 32: return input1+input2; //ADD command
                case 33: return abs(input1+input2); //ADDU command (unsigned Add)
                case 34: return (input1-input2);//SUB command
                case 35: return abs(input1-input2); //SUBU command
                case 36: return input1&input2; //AND command
                case 37: return input1|input2; //OR command
                case 38: return input1^input2; //XOR command
                case 42: return (input1<input2); //SLT command(less than)
                case 43: return abs((input1<input2)); //SLTU command(less than Unsigned)
                case 48: return input1*input2; //MUL command
                case 49: return abs(input1*input2); //MULU command
                case 50: return input1/input2; //DIV command
                case 51: return abs(input1/input2); //DIVU command
                default: return 0;
            }
        }
        else if((ALUOp>0)&&(ALUOp<8)){
            //branch (J-instruction)
            switch(ALUOp){
                case 1:{if(input2==0)      return (input1<0)?0:-1;
                        else if(input2==1) return (input1>=0)?0:-1;};
                case 2:return 0;
                case 4:return(input1==input2)?0:-1; //BEQ command
                case 5:return(input1!=input2)?0:-1; //BNE command
                case 6:return(input1<=input2)?0:-1; //BLE command
                case 7:return(input1>input2)?0:-1; //BGT command
            }
            return -1;
        }
        else if((ALUOp>=8)&&(ALUOp<32)){
            //I-instruction
            switch(ALUOp){
                case 8: return input1+input2; //ADDI command
                case 9: return abs(input1+input2); //ADDIU command
                case 10: return (input1<input2);//SLTI command(less than)
                case 11: return abs((input1<input2)); //SLTIU command
                case 12: return input1&input2; //ANDI command
                case 13: return input1|input2; //ORI command
                case 14: return  input1^input2; //XORI command
                case 15: return  input2<<16; //LUI command
                case 16: return  input1; //MOV command
                case 17: return  input2; //MOVS command
            }
        }
        else if(ALUOp>=32){
            //I-instruction
            switch(ALUOp){
                case 32: return input1; //LB command
                case 34: return input1; //LW command
                case 40: return input1; //SB command
                case 43: return input1; //SW command
            }
        }
        else{
            return input1;
        }
    }
};

//Extra function
void init(){

}
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
        cout << text<<endl;
        rom.setdata(text.c_str(),loadcount);
        loadcount++;
    }
    // Close the file
    reg.write(0,0);
    reg.write(1,0);
    reg.write(2,10);
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

    //CPU Process===================================================================================
    int count=0;
    while(count<=1){
    //Fetch Stage
    PCToRomAddressandFTAdder=Pc.sendCount();
    RomOutput=rom.fetch(PCToRomAddressandFTAdder);
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
