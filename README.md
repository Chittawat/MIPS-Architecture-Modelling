# MIPS-Architecture-Modelling
Developed a MIPS Architecture based CPU model which received the instruction from file and process the command based on MIPS ISA. The model was implemented using C++ with Object Orientated Programming methodology.

## Usage
1. Enter the Binary Encoding represented in command list into sample.txt
2. Run the program
3. The program print the result of the command according to MIPS Architecture ISA
## Command List
### R-Instruction

| AluOp Binary | Func Binary | Function                             | Operation                       | Assembly Syntax | Binary Input/Encoding                     |
| -------------|-------------|--------------------------------------|---------------------------------|-----------------|------------------------------------------ |
| 000000       |000000       | SLL -- Shift left logical            | $d = $t << h                    | sll $d, $t, h   | 0000 00ss ssst tttt dddd dhhh hh00 0000   |
| 000000       |000011       | SRA -- Shift right arithmetic        | $d = $t << h                    | sra $d, $t, h   | 0000 00-- ---t tttt dddd dhhh hh00 0011   |
| 000000       |000100       | SLLV -- Shift left logical variable  | $d = $t << $s                   | sllv $d, $t, $s | 0000 00ss ssst tttt dddd d--- --00 0100   |
| 000000       |000110       | SRLV -- Shift right logical variable | $d = $t >> $s                   | srlv $d, $t, $s | 0000 00ss ssst tttt dddd d--- --00 0110   |
| 000000       |100000       | ADD – Add (with overflow)            | $d = $s + $t                    | add $d, $s, $t  | 0000 00ss ssst tttt dddd d000 0010 0000   |
| 000000       |100001       | ADDU -- Add unsigned (no overflow)   | $d = $s + $t                    | addu $d, $s, $t | 0000 00ss ssst tttt dddd d000 0010 0001   |
| 000000       |100010       | SUB -- Subtract                      | $d = $s - $t                    | sub $d, $s, $t  | 0000 00ss ssst tttt dddd d000 0010 0010   |
| 000000       |100011       | SUBU -- Subtract unsigned            | $d = $s - $t                    | subu $d, $s, $t | 0000 00ss ssst tttt dddd d000 0010 0011   |
| 000000       |100100       | AND -- Bitwise and                   | $d = $s & $t                    | and $d, $s, $t  | 0000 00ss ssst tttt dddd d000 0010 0100   |
| 000000       |100101       | OR -- Bitwise or                     | $d = $s   $t                    | or $d, $s, $t   | 0000 00ss ssst tttt dddd d000 0010 0101   |
| 000000       |100110       | XOR -- Bitwise exclusive or          | $d = $s ^ $t                    | xor $d, $s, $t  | 0000 00ss ssst tttt dddd d--- --10 0110   |
| 000000       |101010       | SLT -- Set on less than (signed)     | if $s < $t $d = 1; else $d = 0; | sra $d, $t, h   | 0000 00ss ssst tttt dddd d000 0010 1010   |
| 000000       |101011       | SLTU -- Set on less than unsigned    | if $s > $t $d = 1; else $d = 0; | sltu $d, $s, $t |	0000 00ss ssst tttt dddd d000 0010 1011   |
| 000000       |110000       | MUL -- Multiply                      | $d = $s * $t                    | mul $d, $s, $t  | 0000 00ss ssst tttt dddd d000 0011 0000   |
| 000000       |110001       | MULU -- Multiply unsigned            | $d = $s * $t                    | mulu $d, $s, $t | 0000 00ss ssst tttt dddd d000 0011 0001   |
| 000000       |110010       | DIV -- Divide                        | $d = $s / $t                    | div $d, $s, $t  | 0000 00ss ssst tttt dddd d000 0011 0010   |
| 000000       |110011       | DIV -- Divide unsigned               | $d = $s / $t                    | divu $d, $s, $t | 0000 00ss ssst tttt dddd d000 0011 0011   |

### I-Instruction

| AluOp Binary   | Function                                      | Operation                       | Assembly Syntax      | Binary Input/Encoding                     |
| ---------------|-----------------------------------------------|---------------------------------|----------------------|------------------------------------------ |
| 001000         | ADDI -- Add immediate (with overflow)         | $t = $s + imm                   | addi $t, $s, imm     | 0010 00ss ssst tttt iiii iiii iiii iiii   |
| 001001         | ADDIU -- Add immediate unsigned (no overflow) | $t = $s + imm                   | addiu $t, $s, imm    | 0010 01ss ssst tttt iiii iiii iiii iiii   |
| 001010         | SLTI -- Set on less than immediate (signed)   | if $s < imm $t = 1; else $t = 0 | slti $t, $s, imm     | 0010 10ss ssst tttt iiii iiii iiii iiii   |
| 001011         | SLTIU -- Set on less than immediate unsigned  | if $s < imm $t = 1; else $t = 0 | addiu $t, $s, imm    | 0010 11ss ssst tttt iiii iiii iiii iiii   |
| 001100         | ANDI -- Bitwise and immediate                 | $t = $s & imm                   | andi $t, $s, imm     | 0011 00ss ssst tttt iiii iiii iiii iiii   |
| 001101         | ORI -- Bitwise or immediate                   | $t = $s  imm                    | ori $t, $s, imm      | 0011 01ss ssst tttt iiii iiii iiii iiii   |
| 001110         | XORI -- Bitwise exclusive or immediate        | $t = $s ^ imm                   | xori $t, $s, imm     | 0011 10ss ssst tttt iiii iiii iiii iiii   |
| 001111         | LUI -- Load upper immediate                   | $t = (imm << 16)                | lui $t, imm          | 0011 11-- ---t tttt iiii iiii iiii iiii   |
| 010000         | MOV -- Assign value to address                | $s = imm                        | mov $s imm           | 0100 00ss sss- ---- iiii iiii iiii iiii   |
| 010001         | MOVS -- Assign value to address               | $t = imm                        | mov $t imm           | 0100 01-- ---t tttt iiii iiii iiii iiii   |
| 100000         | LB -- Load byte                               | $t = MEM[$s + offset]           | lb $t, offset($s)    | 1000 00ss ssst tttt iiii iiii iiii iiii   |
| 100010         | LW -- Load word                               | $t = MEM[$s + offset]           | lw $t, offset($s)    | 1000 11ss ssst tttt iiii iiii iiii iiii   |
| 101000         | SB -- Store byte                              | MEM[$s + offset] = (0xff & $t)  | sb $t, offset($s)    | 1010 00ss ssst tttt iiii iiii iiii iiii   |
| 101011         | SW -- Store word                              | MEM[$s + offset] = $t           | sw $t, offset($s)    | 1010 11ss ssst tttt iiii iiii iiii iiii   |

### J-Instruction

| AluOp   | Function                     | Operation                                                  | Assembly Syntax      | Binary Input/Encoding                     |
| --------|------------------------------|------------------------------------------------------------|----------------------|------------------------------------------ |
| 000010  | ZERO -- output 0             | $d = 0                                                     | zero                 | 0000 10-- ---- ---- ---- ---- ---- ----   |
| 000100  | BEQ -- Branch on equal       | if $s == $t advance_pc (offset << 2)); else advance_pc (4);| beq $s, $t, offset   | 0001 00ss ssst tttt iiii iiii iiii iiii   |
| 000101  | BNE -- Branch on not equal   | if $s != $t advance_pc (offset << 2)); else advance_pc (4);| bne $s, $t, offset   | 0001 01ss ssst tttt iiii iiii iiii iiii   |
| 000110  | BLE -- Branch on less than   | if $s < $t advance_pc (offset << 2)); else advance_pc (4); | ble $s, $t, offset   | 0001 10ss ssst tttt iiii iiii iiii iiii   |
| 000111  | BGT -- Branch on more than   | if $s > $t advance_pc (offset << 2)); else advance_pc (4); | bgt $s, $t, offset   | 0001 11ss ssst tttt iiii iiii iiii iiii   |

## Future Work
- Use multithreading to make program run as a real pipeline computer
- Allowing Assembly Input
- Assign proper register structure



