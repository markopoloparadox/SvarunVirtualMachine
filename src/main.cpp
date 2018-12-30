#include <map>
#include <functional>

#include "Instruction.h"
#include <fstream>

registers::CPU g_regs;
SourceCode g_code;
Stack g_stack;


void LoadCode();
void DumpStack();


void ReadCode() {
  while (g_regs.R[constants::PC] < g_code.size()) {
    ParseInstruction(g_code, g_regs);
  }
}

int main() {
  g_stack.resize(STACK_BOTTOM);
  g_regs.R[constants::SP] = (Word)(&g_stack[STACK_BOTTOM - 1]) + 1;

  DumpRegisters(g_regs);

  LoadCode();
  ReadCode();

  DumpRegisters(g_regs);
  DumpStack();

  return 0;
}


void DumpStack() {
  std::cout << "Stack: \n";

  int sizeInB = ((int)&g_stack[STACK_BOTTOM - 1]) + 1 - g_regs.R[constants::SP];
  std::cout << "Size: " << sizeInB << "B \n";
  std::cout << "Number of elements: " << sizeInB / sizeof(Word) << "\n";
  std::cout << "Elems: [ ";
  for (int i = 0; i < sizeInB; i += 4) {
    std::cout << *(Word*)&g_stack[STACK_BOTTOM - 4 - i] << " ";
  }

  std::cout << "]\n" << std::endl;
}

void LoadCode() {
  std::ifstream read("output.s_asm", std::ios::binary);
  if (!read) {
    return;
  }
  while (1) {
    int i = read.get();
    if (i == EOF) {
      break;
    }
    g_code.push_back(Byte(i));
  }
}
