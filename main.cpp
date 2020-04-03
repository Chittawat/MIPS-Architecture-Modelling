#include <iostream>
#include <string>
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
    char mem[1028][32];
public:
    string fetch(int addr){
        return mem[addr];
    }
};

class Register{
private:
    int reg[32];
public:
    int readdata1(int readReg1){
        return reg[readReg1];
    }
    int readdata2(int readReg2){
        return reg[readReg2];
    }
    void write(int writeReg,int writeData){
        this->reg[writeReg]=writeData;
    }
};

class ALU{
public:
    int process(int input1,int input2,int func){
        switch(func){
            case 32: return input1+input2; //ADD command
            default: return 0;
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
    multiplexer WBmux,Exmux,IFmux;
//initial
    //Wire init========================================================================================
    //Control Signal
    bool ALUSrc;
    bool MemToReg=0;
    bool branch;
    bool zero;
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
    regWriteReg=seperateBit(11,15,RomOutput);
    func=seperateBit(0,5,RomOutput);
    lowerInstruction=seperateBit(0,15,RomOutput);
    opt=seperateBit(26,31,RomOutput);
    //Ex Stage
    readData1ToALU=reg.readdata1(regReadReg1);
    RegisterreadData2ToExmuxAndramWriteData=reg.readdata2(regReadReg2);
    instructionToShiftLeft=lowerInstruction;
    ExmuxToALU=Exmux.mux(RegisterreadData2ToExmuxAndramWriteData,instructionToShiftLeft,ALUSrc);
    func=32;
    ALUResultToRamAddressAndWBmux=ALU.process(readData1ToALU,ExmuxToALU,func);
    zero=ALUResultToRamAddressAndWBmux==0;
    //MEM Stage
    ram.write(RegisterreadData2ToExmuxAndramWriteData,ALUResultToRamAddressAndWBmux);

    //WB Stage
    ramReadDataToWBmux=ram.read(ALUResultToRamAddressAndWBmux);
    WBmuxToRegisterWriteData=WBmux.mux(ALUResultToRamAddressAndWBmux,ramReadDataToWBmux,MemToReg);
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
