#include "DataProcessing.h"
#include "SvarunCommon/types.h"
#include "SvarunCommon/constants.h"

void ExecuteAdd(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  if (operand == constants::OPERAND) {
    Word number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);

    regs.R[rd] = regs.R[rn] + number;
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    regs.R[rd] = regs.R[rn] + regs.R[rm];
  }
}

void ExecuteMov(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];

  if (operand == constants::OPERAND) {
    Word number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);

    regs.R[rd] = number;
  }
  else if (operand == constants::REGISTER) {
    Byte rn = code[regs.R[constants::PC]++];
    regs.R[rd] = regs.R[rn];
  }
}

void ExecuteSub(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  if (operand == constants::OPERAND) {
    Word number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);

    regs.R[rd] = regs.R[rn] - number;
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    regs.R[rd] = regs.R[rn] - regs.R[rm];
  }
}

void ExecuteAnd(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  if (operand == constants::OPERAND) {
    Word number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);

    regs.R[rd] = regs.R[rn] && number;
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    regs.R[rd] = regs.R[rn] && regs.R[rm];
  }
}

void ExecuteEor(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  if (operand == constants::OPERAND) {
    Word number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);

    regs.R[rd] = (bool)(regs.R[rn]) ^ bool(number);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    regs.R[rd] = (bool)(regs.R[rn]) && (bool)(regs.R[rm]);
  }
}

void ExecuteOrr(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rd = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  if (operand == constants::OPERAND) {
    Word number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);

    regs.R[rd] = regs.R[rn] || number;
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    regs.R[rd] = regs.R[rn] || regs.R[rm];
  }
}

void ExecuteCmp(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rn = code[regs.R[constants::PC]++];

  if (operand == constants::OPERAND) {
    Word number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC]  += sizeof(Word);

    regs.CPSR.ZF = regs.R[rn] == number;
    regs.CPSR.GF = regs.R[rn] > number;
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++];
    regs.CPSR.ZF = regs.R[rn] == regs.R[rm];
    regs.CPSR.GF = regs.R[rn] > regs.R[rm];
  }
}