#pragma once
#include <cstdint>
#include "Registers.h"

void ParseInstruction(SourceCode& code, registers::CPU& regs);

struct Instruction1R1O {
  Byte operand;
  Byte reg1;
  Word value;

  Instruction1R1O(SourceCode& code, registers::CPU& cpu);
};

struct Instruction2R1O {
  Byte operand;
  Byte reg1;
  Byte reg2;
  Word value;

  Instruction2R1O(SourceCode& code, registers::CPU& cpu);
};
