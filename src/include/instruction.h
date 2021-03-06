#pragma once
#include <cstdint>
#include "Registers.h"
#include "SvarunCommon/strongtypes.h"
#include <variant>

void ParseInstruction(SourceCode& code, registers::CPU& regs);

struct Instruction1R1O {
  types::Register reg1;
  Byte operand;
  std::variant<Word, Byte*> value;

  Instruction1R1O(SourceCode& code, registers::CPU& cpu);
};

struct Instruction2R1O {
  types::Register reg1;
  types::Register reg2;
  Byte operand;
  std::variant<Word, Byte*> value;

  Instruction2R1O(SourceCode& code, registers::CPU& cpu);
};

struct Instruction2R2O {
  types::Register reg1;
  types::Register reg2;
  Byte operand1;
  std::variant<Word, Byte*> value1;
  Byte operand2;
  std::variant<Word, Byte*> value2;

  Instruction2R2O(SourceCode& code, registers::CPU& cpu);
};
