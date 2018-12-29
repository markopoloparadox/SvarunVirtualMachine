#pragma once
#include <vector>
#include <cstdint>
#include <iostream>
#include <corecrt.h>
#include "SvarunCommon/constants.h"
#include "SvarunCommon/types.h"

using Stack = std::vector<uint8_t>;

constexpr Word STACK_BOTTOM = 1000;
constexpr Word STACK_TOP = 0;

namespace registers {
  struct Cpsr {
    uint8_t ZF : 1;   // Zero flag
    uint8_t GF : 1;   // Greater than flag
  };

  static_assert(sizeof(Cpsr) == sizeof(uint8_t), "Cspr size");

  struct CPU {
    CPU() {
      R.resize(12, 0);
      R[constants::SP] = 0;
      R[constants::PC] = 0;
    }
    std::vector<Word> R;      // General Registers
    Cpsr CPSR;                // Current Program Status Register        
  };

  inline void DumpRegisters(CPU& regs) {
    std::cout << "General Registers: \n";
    for (int i = 0; i < regs.R.size() - 2; i += 1) {
      std::cout << "R[" << i << "] = " << (int)regs.R[i] << "\n";
    }

    std::cout << "PC = " << (int)regs.R[constants::PC] << "\n";
    std::cout << "SP = " << (int)regs.R[constants::SP] << "\n";
    std::cout << "CPSR Z = " << (int)regs.CPSR.ZF << "\n";
    std::cout << "CPSR H = " << (int)regs.CPSR.GF << "\n" << std::endl;
  }
}


inline void InsertWord(SourceCode& code, Word word) {
  auto ptr = (uint8_t*)&word;
  code.push_back(*ptr);
  ptr += 1;
  code.push_back(*ptr);
  ptr += 1;
  code.push_back(*ptr);
  ptr += 1;
  code.push_back(*ptr);
}

inline void InsertHalfWord(SourceCode& code, HalfWord halfword) {
  auto ptr = (uint8_t*)&halfword;
  code.push_back(*ptr);
  ptr += 1;
  code.push_back(*ptr);
}

