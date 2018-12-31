#include "Branch.h"

void ExecuteJmp(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC] += sizeof(Word);

  regs.R[constants::PC] = location;
}


void ExecuteJeq(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (regs.CPSR.ZF) {
    regs.R[constants::PC]  = location;
  }
}


void ExecuteJne(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (!regs.CPSR.ZF) {
    regs.R[constants::PC]  = location;
  }
}


void ExecuteJlt(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (!regs.CPSR.ZF && !regs.CPSR.GF) {
    regs.R[constants::PC]  = location;
  }
}


void ExecuteJle(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (!regs.CPSR.GF) {
    regs.R[constants::PC]  = location;
  }
}


void ExecuteJgt(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (regs.CPSR.GF) {
    regs.R[constants::PC]  = location;
  }
}


void ExecuteJge(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (regs.CPSR.GF || regs.CPSR.ZF) {
    regs.R[constants::PC]  = location;
  }
}