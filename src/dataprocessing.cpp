#include "DataProcessing.h"
#include "SvarunCommon/types.h"
#include "SvarunCommon/constants.h"

void ExecuteAdd(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1.get()] = cpu.R[ins.reg2.get()] + std::get<Word>(ins.value);
}


void ExecuteSub(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1.get()] = cpu.R[ins.reg2.get()] - std::get<Word>(ins.value);
}


void ExecuteAnd(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1.get()] = cpu.R[ins.reg2.get()] & std::get<Word>(ins.value);
}


void ExecuteEor(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1.get()] = cpu.R[ins.reg2.get()] ^ std::get<Word>(ins.value);
}


void ExecuteOrr(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1.get()] = cpu.R[ins.reg2.get()] | std::get<Word>(ins.value);
}


void ExecuteMul(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1.get()] = cpu.R[ins.reg2.get()] * std::get<Word>(ins.value);
}


void ExecuteLsl(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1.get()] = cpu.R[ins.reg2.get()] << std::get<Word>(ins.value);
}


void ExecuteLsr(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1.get()] = cpu.R[ins.reg2.get()] >> std::get<Word>(ins.value);
}


void ExecuteMov(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  cpu.R[ins.reg1.get()] = std::get<Word>(ins.value);
}


void ExecuteCmp(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  cpu.CPSR.ZF = cpu.R[ins.reg1.get()] == std::get<Word>(ins.value);
  cpu.CPSR.GF = cpu.R[ins.reg1.get()] > std::get<Word>(ins.value);
}

/*
  Load-Store rules:
    - Rn must not be PC
    - Rm must not be SP and must not be PC
    - Rt can be SP only for word loads and word stores
    - Rt can be PC only for word loads.
  */
void ExecuteLdr(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  Byte* ptr = std::get<Byte*>(ins.value);
  cpu.R[ins.reg1.get()] = *(Word*)ptr;
}


void ExecuteLdrh(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  Byte* ptr = std::get<Byte*>(ins.value);
  cpu.R[ins.reg1.get()] = *(HalfWord*)ptr;
}


void ExecuteLdrb(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  Byte* ptr = std::get<Byte*>(ins.value);
  cpu.R[ins.reg1.get()] = *(Byte*)ptr;
}


void ExecuteStr(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  Byte* ptr = std::get<Byte*>(ins.value);
  *(Word*)ptr = (Word)cpu.R[ins.reg1.get()];
}


void ExecuteStrh(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  Byte* ptr = std::get<Byte*>(ins.value);
  *(HalfWord*)ptr = (Word)cpu.R[ins.reg1.get()];
}


void ExecuteStrb(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  Byte* ptr = std::get<Byte*>(ins.value);
  *(Byte*)ptr = (Word)cpu.R[ins.reg1.get()];
}