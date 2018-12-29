#include "Branch.h"

void ExecuteIfeq(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (regs.CPSR.ZF) {
    regs.R[constants::PC]  = location;
  }
}

void ExecuteIfne(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (!regs.CPSR.ZF) {
    regs.R[constants::PC]  = location;
  }
}

void ExecuteIflt(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (!regs.CPSR.ZF && !regs.CPSR.GF) {
    regs.R[constants::PC]  = location;
  }
}

void ExecuteIfle(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (!regs.CPSR.GF) {
    regs.R[constants::PC]  = location;
  }
}

void ExecuteIfgt(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (regs.CPSR.GF) {
    regs.R[constants::PC]  = location;
  }
}

void ExecuteIfge(SourceCode& code, registers::CPU& regs) {
  Word location = *(Word*)&code[regs.R[constants::PC]];
  regs.R[constants::PC]  += sizeof(Word);

  if (regs.CPSR.GF || regs.CPSR.ZF) {
    regs.R[constants::PC]  = location;
  }
}