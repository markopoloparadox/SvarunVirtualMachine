#include "DataProcessing.h"
#include "SvarunCommon/types.h"
#include "SvarunCommon/constants.h"

void ExecuteAdd(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1] = cpu.R[ins.reg2] + ins.value;
}


void ExecuteMov(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  cpu.R[ins.reg1] = ins.value;
}


void ExecuteSub(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1] = cpu.R[ins.reg2] - ins.value;
}


void ExecuteAnd(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1] = cpu.R[ins.reg2] & ins.value;
}


void ExecuteEor(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1] = cpu.R[ins.reg2] ^ ins.value;
}


void ExecuteOrr(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1] = cpu.R[ins.reg2] | ins.value;
}


void ExecuteCmp(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction1R1O(code, cpu);

  cpu.CPSR.ZF = cpu.R[ins.reg1] == ins.value;
  cpu.CPSR.GF = cpu.R[ins.reg1] > ins.value;
}

void ExecuteMul(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1] = cpu.R[ins.reg2] * ins.value;
}

void ExecuteLsl(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1] = cpu.R[ins.reg2] << ins.value;
}


void ExecuteLsr(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  cpu.R[ins.reg1] = cpu.R[ins.reg2] >> ins.value;
}

/*
  Load-Store rules:
    - Rn must not be PC
    - Rm must not be SP and must not be PC
    - Rt can be SP only for word loads and word stores
    - Rt can be PC only for word loads.
  */
void ExecuteLdr(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  Byte* ptr = (Byte*)cpu.R[ins.reg2] + ins.value;
  cpu.R[ins.reg1] = *(Word*)ptr;
}


void ExecuteLdrh(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  Byte* ptr = (Byte*)cpu.R[ins.reg2] + ins.value;
  cpu.R[ins.reg1] = *(HalfWord*)ptr;
}


void ExecuteLdrb(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  Byte* ptr = (Byte*)cpu.R[ins.reg2] + ins.value;
  cpu.R[ins.reg1] = *(Byte*)ptr;
}


void ExecuteStr(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  Byte* ptr = (Byte*)cpu.R[ins.reg2] + ins.value;
  *(Word*)ptr = (Word)cpu.R[ins.reg1];
}


void ExecuteStrh(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  Byte* ptr = (Byte*)cpu.R[ins.reg2] + ins.value;
  *(HalfWord*)ptr = (Word)cpu.R[ins.reg1];
}


void ExecuteStrb(SourceCode& code, registers::CPU& cpu) {
  auto ins = Instruction2R1O(code, cpu);

  Byte* ptr = (Byte*)cpu.R[ins.reg2] + ins.value;
  *(Byte*)ptr = (Word)cpu.R[ins.reg1];
}