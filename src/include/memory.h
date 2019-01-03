#pragma once
#include "Instruction.h"

void ExecutePush(SourceCode& code, registers::CPU& cpu);
void ExecutePop(SourceCode& code, registers::CPU& cpu);
