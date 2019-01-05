#include "Instruction.h"
#include "DataProcessing.h"
#include "Branch.h"
#include "Memory.h"
#include "SvarunCommon/constants.h"
#include "SvarunCommon/types.h"
#include <iostream>

void ParseInstruction(SourceCode& code, registers::CPU& regs) {
  types::OpCode opCode (code[regs.R[constants::PC]++]);

  switch (opCode.get())
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
  case constants::STP:
    ExecuteStp(code, regs);
    break;
  case constants::LDP:
    ExecuteLdp(code, regs);
    break;
  default:
    break;
  }
}


static void RetrieveOperand(Byte operand, std::variant<Word, Byte*>& value, SourceCode& code, registers::CPU& cpu) {
  if (operand == constants::NUMBER) {
    value = *(Word*)&code[cpu.R[constants::PC]];
    cpu.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    auto reg = types::Register(code[cpu.R[constants::PC]++]);
    value = cpu.R[reg.get()];
  }
  else if (operand == constants::MEMORY) {
    types::Memory mem = *(types::Memory*)&code[cpu.R[constants::PC]];
    cpu.R[constants::PC] += sizeof(types::Memory);
    value = (Byte*)cpu.R[mem.reg.get()] + mem.offset;

    if (mem.flag) {
      cpu.R[mem.reg.get()] += mem.offset;
    }
  }
}


Instruction1R1O::Instruction1R1O(SourceCode& code, registers::CPU& cpu) {
  reg1 = types::Register(code[cpu.R[constants::PC]++]);
  operand = code[cpu.R[constants::PC]++];

  RetrieveOperand(operand, value, code, cpu);
}


Instruction2R1O::Instruction2R1O(SourceCode& code, registers::CPU& cpu) {
  reg1 = types::Register(code[cpu.R[constants::PC]++]);
  reg2 = types::Register(code[cpu.R[constants::PC]++]);
  operand = code[cpu.R[constants::PC]++];

  RetrieveOperand(operand, value, code, cpu);
}


Instruction2R2O::Instruction2R2O(SourceCode& code, registers::CPU& cpu) {
  reg1 = types::Register(code[cpu.R[constants::PC]++]);
  reg2 = types::Register(code[cpu.R[constants::PC]++]);
  operand1 = code[cpu.R[constants::PC]++];
  RetrieveOperand(operand1, value1, code, cpu);

  operand2 = code[cpu.R[constants::PC]++];
  RetrieveOperand(operand2, value2, code, cpu);
}

