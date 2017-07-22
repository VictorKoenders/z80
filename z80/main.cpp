#include "Operation.hpp"
#include "CpuState.hpp"

#include <iomanip>
#include <iostream>

int main()
{
  CpuState state;

  for (size_t i = 0; i < Operations.size(); i++) {
    std::cout << "0x" << std::setw(2) << std::setfill('0') << std::hex << i << ": ";
    auto& operation = Operations[i];

    if (operation == nullptr) {
      std::cout << "Not implemented" << std::endl;
    }
    else {
      operation(state);
    }
  }

  //std::cin.get();

  return 0;
}
