# MIPS-Architecture-Modelling
Developed a MIPS Architecture based CPU model which received the instruction from file and process the command based on MIPS ISA. The model was implemented using C++ with Object Orientated Programming methodology.

## Usage

## Command List
### R-Instruction

| AluOp Binary  | Func Binary | Function                     | Operation    | Assembly Syntax      | Binary Input/Encoding                     |
| --------------|-------------|------------------------------|--------------|----------------------|------------------------------------------ |
| 000000        |000000       | SLL - Shift left logical     | $d = $t << h | $d = $t << h         | 0000 00ss ssst tttt dddd dhhh hh00 0000   |

### I-Instruction

| AluOp   | Function                     | Operation    | Assembly Syntax      | Binary Input/Encoding                     |
| --------|------------------------------|--------------|----------------------|------------------------------------------ |
|

### J-Instruction

| AluOp   | Function                     | Operation    | Assembly Syntax      | Binary Input/Encoding                     |
| --------|------------------------------|--------------|----------------------|------------------------------------------ |
|

## Future Work
- Enable Read from file (.txt)
- Use multithreading to make program run as a real pipeline computer
- Allowing Assembly Input



