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
    break;
  case constants::SUB:
    ExecuteSub(code, regs);
    break;
  case constants::AND:
    ExecuteAnd(code, regs);
    break;
  case constants::EOR:
    ExecuteEor(code, regs);
    break;
  case constants::ORR:
    ExecuteOrr(code, regs);
    break;
  case constants::MOV:
    ExecuteMov(code, regs);
    break;
  case constants::CMP:
    ExecuteCmp(code, regs);
    break;
  case constants::JMP:
    ExecuteJmp(code, regs);
    break;
  case constants::JEQ:
    ExecuteJeq(code, regs);
    break;
  case constants::JNE:
    ExecuteJne(code, regs);
    break;
  case constants::JLT:
    ExecuteJlt(code, regs);
    break;
  case constants::JLE:
    ExecuteJle(code, regs);
    break;
  case constants::JGT:
    ExecuteJgt(code, regs);
    break;
  case constants::JGE:
    ExecuteJge(code, regs);
    break;
  case constants::PUSH:
    ExecutePush(code, regs);
    break;
  case constants::POP:
    ExecutePop(code, regs);
    break;
  case constants::LDR:
    ExecuteLdr(code, regs);
    break;
  case constants::LDRH:
    ExecuteLdrh(code, regs);
    break;
  case constants::LDRB:
    ExecuteLdrb(code, regs);
    break;
  case constants::STR:
    ExecuteStr(code, regs);
    break;
  case constants::STRH:
    ExecuteStrh(code, regs);
    break;
  case constants::STRB:
    ExecuteStrb(code, regs);
    break;
  case constants::MUL:
    ExecuteMul(code, regs);
    break;
  case constants::LSL:
    ExecuteLsl(code, regs);
    break;
  case constants::LSR:
    ExecuteLsr(code, regs);
    break;
  default:
    break;
  }
}