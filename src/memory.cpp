#include "Branch.h"
#include "SvarunCommon/types.h"
#include "SvarunCommon/constants.h"

void ExecutePush(SourceCode& code, registers::CPU& cpu) {
  Byte operand = code[cpu.R[constants::PC]++];
  cpu.R[constants::SP] -= 4;

  Word number = 0;
  if (operand == constants::OPERAND) {
    number = *(Word*)&code[cpu.R[constants::PC]];
    cpu.R[constants::PC] += sizeof(Word);
  }
  else if (operand == constants::REGISTER) {
    Byte rn = code[cpu.R[constants::PC]++];
    number = cpu.R[rn];
  }

  auto ptr = (Word*)cpu.R[constants::SP];
  *ptr = number;
}

void ExecutePop(SourceCode& code, registers::CPU& cpu) {
  Byte rd = code[cpu.R[constants::PC]++];
  cpu.R[rd] = *(Word*)cpu.R[constants::SP];
  cpu.R[constants::SP] += 4;
}