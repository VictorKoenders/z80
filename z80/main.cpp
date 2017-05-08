#include "Operation.hpp"

int main(char **args, int argc)
{
  CpuState state;

  for (int i = 0; i < 256; i++) {
    std::cout << "0x" << std::setw(2) << std::setfill('0') << std::hex << i << ": ";
    auto& operation = Operation::Operations[i];

    if (operation == nullptr) {
      std::cout << "Not implemented" << std::endl;
    }
    else {
      operation->execute(state);
    }
  }

  std::cin.get();

  return 0;
}
