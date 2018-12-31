#pragma once
#include "Instruction.h"

void ExecuteJmp(SourceCode& code, registers::CPU& regs);
void ExecuteJeq(SourceCode& code, registers::CPU& regs);
void ExecuteJne(SourceCode& code, registers::CPU& regs);
void ExecuteJlt(SourceCode& code, registers::CPU& regs);
void ExecuteJle(SourceCode& code, registers::CPU& regs);
void ExecuteJgt(SourceCode& code, registers::CPU& regs);
void ExecuteJge(SourceCode& code, registers::CPU& regs);
