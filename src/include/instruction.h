#pragma once
#include <cstdint>
#include "Registers.h"

void ParseInstruction(SourceCode& code, registers::CPU& regs);
