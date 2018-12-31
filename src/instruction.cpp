#include "Instruction.h"
#include "DataProcessing.h"
#include "Branch.h"
#include "Memory.h"
#include "SvarunCommon/constants.h"
#include "SvarunCommon/types.h"
#include <iostream>

void ParseInstruction(SourceCode& code, registers::CPU& regs) {
  Byte opCode = code[regs.R[constants::PC]++];

  switch (opCode)
  {
  case constants::NOP:
    break;
  case constants::ADD:
    ExecuteAdd(code, regs);
    std::cout << "ADD\n";
    break;
  case constants::SUB:
    ExecuteSub(code, regs);
    std::cout << "SUB\n";
    break;
  case constants::AND:
    ExecuteAnd(code, regs);
    std::cout << "AND\n";
    break;
  case constants::EOR:
    ExecuteEor(code, regs);
    std::cout << "EOR\n";
    break;
  case constants::ORR:
    ExecuteOrr(code, regs);
    std::cout << "ORR\n";
    break;
  case constants::MOV:
    ExecuteMov(code, regs);
    std::cout << "MOV\n";
    break;
  case constants::CMP:
    ExecuteCmp(code, regs);
    std::cout << "CMP\n";
    break;
  case constants::JMP:
    ExecuteJmp(code, regs);
    std::cout << "JMP\n";
    break;
  case constants::JEQ:
    ExecuteJeq(code, regs);
    std::cout << "JEQ\n";
    break;
  case constants::JNE:
    ExecuteJne(code, regs);
    std::cout << "JNE\n";
    break;
  case constants::JLT:
    ExecuteJlt(code, regs);
    std::cout << "JLT\n";
    break;
  case constants::JLE:
    ExecuteJle(code, regs);
    std::cout << "JLE\n";
    break;
  case constants::JGT:
    ExecuteJgt(code, regs);
    std::cout << "JGT\n";
    break;
  case constants::JGE:
    ExecuteJge(code, regs);
    std::cout << "JGE\n";
    break;
  case constants::PUSH:
    ExecutePush(code, regs);
    std::cout << "PUSH\n";
    break;
  case constants::POP:
    ExecutePop(code, regs);
    std::cout << "POP\n";
    break;
  case constants::LDR:
    ExecuteLdr(code, regs);
    std::cout << "LDR\n";
    break;
  case constants::LDRH:
    ExecuteLdrh(code, regs);
    std::cout << "LDRH\n";
    break;
  case constants::LDRB:
    ExecuteLdrb(code, regs);
    std::cout << "LDRB\n";
    break;
  case constants::STR:
    ExecuteStr(code, regs);
    std::cout << "STR\n";
    break;
  case constants::STRH:
    ExecuteStrh(code, regs);
    std::cout << "STRH\n";
    break;
  case constants::STRB:
    ExecuteStrb(code, regs);
    std::cout << "STRB\n";
    break;
  default:
    break;
  }
}