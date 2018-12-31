#include "Branch.h"
#include "SvarunCommon/types.h"
#include "SvarunCommon/constants.h"

void ExecutePush(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  regs.R[constants::SP] -= 4;

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rn = code[regs.R[constants::PC]++];
    number = regs.R[rn];
  }

  auto ptr = (Word*)regs.R[constants::SP];
  *ptr = number;
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

  Word offset = 0;
  if (operand == constants::OPERAND) {
    offset = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++]; //Specifies the register containing a value to be used as the offset.
    offset = regs.R[rm];
  }

  auto ptr = (Byte*)regs.R[rn];
  ptr += offset;
  regs.R[rt] = *(Word*)ptr;
}


void ExecuteLdrh(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rt = code[regs.R[constants::PC]++];  // Specifies the register to load
  Byte rn = code[regs.R[constants::PC]++];  // Specifies the register on which the memory address is based.

  Word offset = 0;
  if (operand == constants::OPERAND) {
    offset = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++]; //Specifies the register containing a value to be used as the offset.
    offset = regs.R[rm];
  }

  auto ptr = (Byte*)regs.R[rn];
  ptr += offset;
  regs.R[rt] = *(HalfWord*)ptr;
}


void ExecuteLdrb(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rt = code[regs.R[constants::PC]++];  // Specifies the register to load
  Byte rn = code[regs.R[constants::PC]++];  // Specifies the register on which the memory address is based.

  Word offset = 0;
  if (operand == constants::OPERAND) {
    offset = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++]; //Specifies the register containing a value to be used as the offset.
    offset = regs.R[rm];
  }

  auto ptr = (Byte*)regs.R[rn];
  ptr += offset;
  regs.R[rt] = *(Byte*)ptr;
}


void ExecuteStr(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rt = code[regs.R[constants::PC]++];  // Specifies the register to store.
  Byte rn = code[regs.R[constants::PC]++];  // Specifies the register on which the memory address is based.

  Word offset = 0;
  if (operand == constants::OPERAND) {
    offset = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++]; //Specifies the register containing a value to be used as the offset.
    offset = regs.R[rm];
  }

  auto ptr = (Byte*)regs.R[rn];
  ptr += offset;

  *(Word*)ptr = (Word)regs.R[rt];
}


void ExecuteStrh(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rt = code[regs.R[constants::PC]++];  // Specifies the register to store.
  Byte rn = code[regs.R[constants::PC]++];  // Specifies the register on which the memory address is based.

  Word offset = 0;
  if (operand == constants::OPERAND) {
    offset = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++]; //Specifies the register containing a value to be used as the offset.
    offset = regs.R[rm];
  }

  auto ptr = (Byte*)regs.R[rn];
  ptr += offset;

  *(HalfWord*)ptr = (HalfWord)regs.R[rt];
}


void ExecuteStrb(SourceCode& code, registers::CPU& regs) {
  Byte operand = code[regs.R[constants::PC]++];
  Byte rt = code[regs.R[constants::PC]++];  // Specifies the register to store.
  Byte rn = code[regs.R[constants::PC]++];  // Specifies the register on which the memory address is based.

  Word offset = 0;
  if (operand == constants::OPERAND) {
    offset = *(Word*)&code[regs.R[constants::PC]];
    regs.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rm = code[regs.R[constants::PC]++]; //Specifies the register containing a value to be used as the offset.
    offset = regs.R[rm];
  }

  auto ptr = (Byte*)regs.R[rn];
  ptr += offset;

  *(Byte*)ptr = (Byte)regs.R[rt];
}