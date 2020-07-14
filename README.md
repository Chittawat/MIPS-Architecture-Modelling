# MIPS-Architecture-Modelling
Developed a MIPS Architecture based CPU model which received the instruction from file and process the command based on MIPS ISA. The model was implemented using C++ with Object Orientated Programming methodology.

## Usage
1. Run the program
2. Enter the Binary Encoding as listed in the command list
3. The program print the result of the command according to MIPS Architecture ISA
## Command List
### R-Instruction

| AluOp Binary | Func Binary | Function                             | Operation                       | Assembly Syntax | Binary Input/Encoding                     |
| -------------|-------------|--------------------------------------|---------------------------------|-----------------|------------------------------------------ |
| 000000       |000000       | SLL -- Shift left logical            | $d = $t << h                    | sll $d, $t, h   | 0000 00ss ssst tttt dddd dhhh hh00 0000   |
| 000000       |000011       | SRA -- Shift right arithmetic        | $d = $t << h                    | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |000100       | SLLV -- Shift left logical variable  | $d = $t << $s                   | sllv $d, $t, $s | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |000110       | SRLV -- Shift right logical variable | $d = $t >> $s                   | srlv $d, $t, $s | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |100000       | ADD – Add (with overflow)            | $d = $s + $t                    | add $d, $s, $t  | 0000 00ss ssst tttt dddd d000 0010 0000   |
| 000000       |100001       | ADDU -- Add unsigned (no overflow)   | $d = $s + $t                    | addu $d, $s, $t | 0000 00ss ssst tttt dddd d000 0010 0001   |
| 000000       |100010       | SUB -- Subtract                      | $d = $s - $t                    | sub $d, $s, $t  | 0000 00ss ssst tttt dddd d000 0010 0010   |
| 000000       |100011       | SUBU -- Subtract unsigned            | $d = $s - $t                    | subu $d, $s, $t | 0000 00ss ssst tttt dddd d000 0010 0011   |
| 000000       |100100       | AND -- Bitwise and                   | $d = $s & $t                    | and $d, $s, $t  | 0000 00ss ssst tttt dddd d000 0010 0100   |
| 000000       |100101       | OR -- Bitwise or                     | $d = $s "|" $t                    | or $d, $s, $t   | 0000 00ss ssst tttt dddd d000 0010 0101   |
| 000000       |100110       | XOR -- Bitwise exclusive or          | $d = $s ^ $t                    | xor $d, $s, $t  | 0000 00ss ssst tttt dddd d--- --10 0110   |
| 000000       |101010       | SLT -- Set on less than (signed)     | if $s < $t $d = 1; else $d = 0; | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |101011       | SRA -- Shift right arithmetic | $d = $t << h | slt $d, $s, $t   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
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



