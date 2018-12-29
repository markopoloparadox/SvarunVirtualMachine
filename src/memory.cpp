#include "Branch.h"
#include "SvarunCommon/types.h"
#include "SvarunCommon/constants.h"

void ExecutePush(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];

  regs.R[constants::SP] -= 4;
  if (operand == constants::OPERAND) {
    Word number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);

    auto ptr = (Word*)regs.R[constants::SP];
    *ptr = number;
  }
  else if (operand == constants::REGISTER) {
    Byte rn = code[regs.R[constants::PC]++];
    auto ptr = (Word*)regs.R[constants::SP];
    *ptr = regs.R[rn];
  }
}

void ExecutePop(SourceCode& code, registers::CPU& regs) {
  Byte rd = code[regs.R[constants::PC]++];
  regs.R[rd] = *(Word*)regs.R[constants::SP];
  regs.R[constants::SP] += 4;
}

/*
  Load-Store rules:
    - Rn must not be PC
    - Rm must not be SP and must not be PC
    - Rt can be SP only for word loads and word stores
    - Rt can be PC only for word loads.
  */

void ExecuteLdr(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rt = code[regs.R[constants::PC]++];  // Specifies the register to load
  Byte rn = code[regs.R[constants::PC]++];  // Specifies the register on which the memory address is based.

  if (operand == constants::OPERAND) {
    Word offset = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);

    auto ptr = (uint8_t*)regs.R[rn];
    ptr += offset;

    regs.R[rt] = *(Word*)ptr;
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++]; //Specifies the register containing a value to be used as the offset.
    Word offset = regs.R[rm];

    auto ptr = (uint8_t*)regs.R[rn];
    ptr += offset;

    regs.R[rt] = *(Word*)ptr;
  }
}

void ExecuteStr(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rt = code[regs.R[constants::PC]++];  // Specifies the register to store.
  Byte rn = code[regs.R[constants::PC]++];  // Specifies the register on which the memory address is based.

  if (operand == constants::OPERAND) {
    Word offset = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);

    auto ptr = (uint8_t*)regs.R[rn];
    ptr += offset;

    *(Word*)ptr = regs.R[rt];
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++]; //Specifies the register containing a value to be used as the offset.
    Word offset = regs.R[rm];

    auto ptr = (uint8_t*)regs.R[rn];
    ptr += offset;

    *(Word*)ptr = regs.R[rt];
  }
}