#pragma once
#include "Instruction.h"

void ExecuteIfeq(SourceCode& code, registers::CPU& regs);
void ExecuteIfne(SourceCode& code, registers::CPU& regs);
void ExecuteIflt(SourceCode& code, registers::CPU& regs);
void ExecuteIfle(SourceCode& code, registers::CPU& regs);
void ExecuteIfgt(SourceCode& code, registers::CPU& regs);
void ExecuteIfge(SourceCode& code, registers::CPU& regs);