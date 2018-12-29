#pragma once
#include "Instruction.h"

void ExecuteAdd(SourceCode& code, registers::CPU& regs);
void ExecuteMov(SourceCode& code, registers::CPU& regs);
void ExecuteSub(SourceCode& code, registers::CPU& regs);
void ExecuteAnd(SourceCode& code, registers::CPU& regs);
void ExecuteEor(SourceCode& code, registers::CPU& regs);
void ExecuteOrr(SourceCode& code, registers::CPU& regs);
void ExecuteCmp(SourceCode& code, registers::CPU& regs);