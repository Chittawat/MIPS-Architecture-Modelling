cmake_minimum_required(VERSION 3.15)
project(RSIC_CPU_Model)

set(CMAKE_CXX_STANDARD 14)

add_executable(RSIC_CPU_Model main.cpp ProgramMemory.cpp ProgramMemory.h DataMemory.cpp DataMemory.h Register.cpp Register.h multiplexer.h Adder.h programCounter.cpp programCounter.h shiftleft.h ALU.cpp ALU.h AdditionalMethod.h AdditionalMethod.cpp internalInterconnect.h assembler.h)