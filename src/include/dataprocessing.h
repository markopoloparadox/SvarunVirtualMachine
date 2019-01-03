#pragma once
#include "Instruction.h"

void ExecuteAdd(SourceCode& code, registers::CPU& cpu);
void ExecuteMov(SourceCode& code, registers::CPU& cpu);
void ExecuteSub(SourceCode& code, registers::CPU& cpu);
void ExecuteAnd(SourceCode& code, registers::CPU& cpu);
void ExecuteEor(SourceCode& code, registers::CPU& cpu);
void ExecuteOrr(SourceCode& code, registers::CPU& cpu);
void ExecuteCmp(SourceCode& code, registers::CPU& cpu);
void ExecuteMul(SourceCode& code, registers::CPU& cpu);
void ExecuteLsl(SourceCode& code, registers::CPU& cpu);
void ExecuteLsr(SourceCode& code, registers::CPU& cpu);
// LDR instructions load a register with a value from memory.
void ExecuteLdr(SourceCode& code, registers::CPU& cpu);
void ExecuteLdrh(SourceCode& code, registers::CPU& cpu);
void ExecuteLdrb(SourceCode& code, registers::CPU& cpu);
// STR instructions store a register value into memory.
void ExecuteStr(SourceCode& code, registers::CPU& cpu);
void ExecuteStrh(SourceCode& code, registers::CPU& cpu);
void ExecuteStrb(SourceCode& code, registers::CPU& cpu);