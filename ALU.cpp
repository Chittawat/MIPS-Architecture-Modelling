//
// Created by chitt on 04/04/2020.
//

#include "ALU.h"

int ALU::process(int input1,int input2,int func,int ALUOp,int shift){
    if(ALUOp==0){
        switch(func){
            //R-instruction
            case 0: return input2<<shift; //SLL command
            case 1: return input2>>shift; //SRL command
            case 2: return input2<<shift; //SLA command
            case 3: return input2>>shift; //SRA command
            case 4: return input2<<input1; // SLLV command (shiftleft variable)
            case 6: return input2>>input1; //SRLV command (shiftright variable)
            case 32: return input1+input2; //ADD command
            case 33: return abs(input1+input2); //ADDU command (unsigned Add)
            case 34: return (input1-input2);//SUB command
            case 35: return abs(input1-input2); //SUBU command
            case 36: return input1&input2; //AND command
            case 37: return input1|input2; //ORR command
            case 38: return input1^input2; //EOR command
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