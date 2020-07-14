# MIPS-Architecture-Modelling
Developed a MIPS Architecture based CPU model which received the instruction from file and process the command based on MIPS ISA. The model was implemented using C++ with Object Orientated Programming methodology.

## Usage
1. Run the program
2. Enter the Binary Encoding as listed in the command list
3. The program print the result of the command according to MIPS Architecture ISA
## Command List
### R-Instruction

| AluOp Binary | Func Binary | Function                            | Operation     | Assembly Syntax | Binary Input/Encoding                     |
| -------------|-------------|-------------------------------------|---------------|-----------------|------------------------------------------ |
| 000000       |000000       | SLL -- Shift left logical            | $d = $t << h  | sll $d, $t, h   | 0000 00ss ssst tttt dddd dhhh hh00 0000   |
| 000000       |000011       | SRA -- Shift right arithmetic        | $d = $t << h  | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |000100       | SLLV -- Shift left logical variable  | $d = $t << $s | sllv $d, $t, $s | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |000110       | SRLV -- Shift right logical variable | $d = $t >> $s | srlv $d, $t, $s | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |100000       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |100001       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |100010       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |100011       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |100100       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |100101       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |100110       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |101010       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |101011       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |110000       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |110001       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |110010       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |110011       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |

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



