#include <iostream>
#include <cstring>
#include<cmath>
using namespace std;

class DataMemory{
private:
    int mem[1028];
public:
    int read(int addr){
        return mem[addr];
    }
    void write(int writeData,int addr){
        this->mem[addr]=writeData;
    }
};

class ProgramMemory{
private:
    char mem[1028][33];
public:
    string fetch(int addr){
        return mem[addr];
    }

    void setdata(const char *data, int addr){
        strcpy(this->mem[addr],data);
    }
};

class Register{
private:
    int reg[32];
public:
    int readData1(int readReg1){
        return reg[readReg1];
    }
    int readData2(int readReg2){
        return reg[readReg2];
    }
    void write(int writeReg,int writeData){
        this->reg[writeReg]=writeData;
    }
};

class ALU{
public:
    int process(int input1,int input2,int func,int ALUOp){
        if(ALUOp==0){
            switch(func){
                //R-instruction
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
                default: return 0;
            }
        }
        else if((ALUOp>0)&&(ALUOp<8)){
            //branch (J-instruction)
            return 0;
        }
        else if((ALUOp>=8)&&(ALUOp<16)){
            //I-instruction
            switch(ALUOp){
                case 8: return input1+input2; //ADDI command
                case 9: return abs(input1+input2); //ADDIU command
                case 10: return (input1<input2);//SLTI command(less than)
                case 11: return abs((input1<input2)); //SLTIU command
                case 12: return input1&input2; //ANDI command
                case 13: return  input1^input2; //XORI command
            }
        }else{
            return input1;
        }
    }
};

class shiftLeft{
public:
    int shift(int a){
        return a<<2;
    }
};

class programCounter{
private:
    int count=0;
    int programsize;
public:
    programCounter(int programsize){
        this->programsize=programsize;
    }
    void setcount(int newcount){
        this->count=newcount;
    }

    int sendCount(){
        return count;
    }
};

class Adder{
public:
    int add(int a,int b){
        return a+b;
    }
};

class multiplexer{
public:
    int mux(int a,int b,bool m){
        return m?b:a;
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
    rom.setdata("00100000000000010000000000001000",0);
    reg.write(0,10);
    reg.write(1,6);
    //Wire init========================================================================================
    //Control Signal
    bool ALUSrc;
    int ALUOp;
    bool MemToReg=0;
    bool branch;
    bool zero;
    bool regDST;
    bool Exmuxmode=branch&zero;
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
    //Fetch Stage
    PCToRomAddressandFTAdder=Pc.sendCount();
    RomOutput=rom.fetch(PCToRomAddressandFTAdder);
    //ID Stage
    regReadReg1=seperateBit(21,25,RomOutput);
    regReadReg2=seperateBit(16,20,RomOutput);
    regWriteRegR=seperateBit(11,15,RomOutput);
    func=seperateBit(0,5,RomOutput);
    lowerInstruction=seperateBit(0,15,RomOutput);
    opt=seperateBit(26,30,RomOutput);
    //Ex stage Preset Control Signal
    ALUOp=opt;
    ALUSrc=(opt>=8);
    regDST=(opt==0);
    branch=(opt<8)&&(opt>0);
    //Ex Stage
    readData1ToALU=reg.readData1(regReadReg1);
    RegisterreadData2ToExmuxAndramWriteData=reg.readData2(regReadReg2);
    instructionToShiftLeft=lowerInstruction;
    ExmuxToALU=Exmux.mux(RegisterreadData2ToExmuxAndramWriteData,instructionToShiftLeft,ALUSrc);
    ALUResultToRamAddressAndWBmux=ALU.process(readData1ToALU,ExmuxToALU,func,ALUOp);
    zero=ALUResultToRamAddressAndWBmux==0;
    //MEM Stage
    ram.write(RegisterreadData2ToExmuxAndramWriteData,ALUResultToRamAddressAndWBmux);

    //WB Stage
    ramReadDataToWBmux=ram.read(ALUResultToRamAddressAndWBmux);
    WBmuxToRegisterWriteData=WBmux.mux(ALUResultToRamAddressAndWBmux,ramReadDataToWBmux,MemToReg);
    regWriteReg=IDmux.mux(regReadReg2,regWriteRegR,regDST);
    reg.write(regWriteReg,WBmuxToRegisterWriteData);
    //Other Step
    resultFTAddertoExAdderandFTmux=IFadder.add(PCToRomAddressandFTAdder,1);
    shiftLeft2ToExAdder=shiftLeft.shift(lowerInstruction);
    resultExAddertoFTmux=Exadder.add(FTAddertoExAdder,shiftLeft2ToExAdder);
    FTmuxoutToPCIn=Exmux.mux(resultFTAddertoExAdderandFTmux,resultExAddertoFTmux,Exmuxmode);
    Pc.setcount(FTmuxoutToPCIn);
    //test
    cout<<WBmuxToRegisterWriteData<<endl;
    return 0;
}
