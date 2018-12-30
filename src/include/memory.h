#pragma once
#include "Instruction.h"

void ExecutePush(SourceCode& code, registers::CPU& regs);
void ExecutePop(SourceCode& code, registers::CPU& regs);
// LDR instructions load a register with a value from memory.
void ExecuteLdr(SourceCode& code, registers::CPU& regs);
void ExecuteLdrh(SourceCode& code, registers::CPU& regs);
void ExecuteLdrb(SourceCode& code, registers::CPU& regs);
// STR instructions store a register value into memory.
void ExecuteStr(SourceCode& code, registers::CPU& regs);
void ExecuteStrh(SourceCode& code, registers::CPU& regs);
void ExecuteStrb(SourceCode& code, registers::CPU& regs);