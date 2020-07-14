# MIPS-Architecture-Modelling
Developed a MIPS Architecture based CPU model which received the instruction from file and process the command based on MIPS ISA. The model was implemented using C++ with Object Orientated Programming methodology.

## Usage
1. Run the program
2. Enter the Binary Encoding as listed in the command list
3. The program print the result of the command according to MIPS Architecture ISA
## Command List
### R-Instruction

| AluOp Binary | Func Binary | Function                      | Operation    | Assembly Syntax | Binary Input/Encoding                     |
| -------------|-------------|------------------------------ |--------------|-----------------|------------------------------------------ |
| 000000       |000000       | SLL - Shift left logical      | $d = $t << h | sll $d, $t, h   | 0000_00ss_ssst_tttt_dddd_dhhh_hh00_0000   |
| 000000       |000011       | SRA -- Shift right arithmetic | $d = $t << h | sra $d, $t, h   | 0000_00--_---t_tttt_dddd_dhhh_hh00_0011   |

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



