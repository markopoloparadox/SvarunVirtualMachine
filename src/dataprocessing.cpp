#include "DataProcessing.h"
#include "SvarunCommon/types.h"
#include "SvarunCommon/constants.h"

void ExecuteAdd(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    number = regs.R[rm];
  }

  regs.R[rd] = regs.R[rn] + number;
}


void ExecuteMov(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rn = code[regs.R[constants::PC]++];
    number = regs.R[rn];
  }

  regs.R[rd] = number;
}


void ExecuteSub(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    number = regs.R[rm];
  }

  regs.R[rd] = regs.R[rn] - number;
}


void ExecuteAnd(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    number = regs.R[rm];
  }

  regs.R[rd] = regs.R[rn] & number;
}


void ExecuteEor(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    number = regs.R[rm];
  }

  regs.R[rd] = regs.R[rn] ^ number;
}


void ExecuteOrr(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    number = regs.R[rm];
  }

  regs.R[rd] = regs.R[rn] | number;
}


void ExecuteCmp(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    number = regs.R[rm];
  }

  regs.CPSR.ZF = regs.R[rn] == number;
  regs.CPSR.GF = regs.R[rn] > number;
}