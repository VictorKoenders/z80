#include "Operation.hpp"
#include <iostream>

std::unique_ptr<Operation> Operation::Operations[256] = {
  /* 00 */ std::make_unique<NoOperation>(),
  /* 01 */ std::make_unique<LoadOperation<AddressBC, StaticValue<0>>>(),
  /* 02 */ std::make_unique<LoadOperation<AddressLocationBC, AddressA>>(),
  /* 03 */ std::make_unique<IncrementOperation<AddressBC>>(),
  /* 04 */ std::make_unique<IncrementOperation<AddressB>>(),
  /* 05 */ std::make_unique<DecrementOperation<AddressB>>(),
  /* 06 */ std::make_unique<LoadOperation<AddressB, StaticValue<0>>>(),
  /* 07 */ std::make_unique<ShiftAddressALeftOperation>(),
};

Operation::Operation()
{
}


Operation::~Operation()
{
}

void NoOperation::execute(CpuState& state)
{
  std::cout << "NOP" << std::endl;
}
