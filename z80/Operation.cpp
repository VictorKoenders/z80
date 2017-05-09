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
  /* 08 */ std::make_unique<ExchangeOperation<AddressAF, AddressAFShadow>>(),
  /* 09 */ std::make_unique<AddOperation<AddressHL, AddressBC>>(),
  /* 0A */ std::make_unique<LoadOperation<AddressA, AddressLocationBC>>(),
  /* 0B */ std::make_unique<DecrementOperation<AddressBC>>(),
  /* 0C */ std::make_unique<IncrementOperation<AddressC>>(),
  /* 0D */ std::make_unique<DecrementOperation<AddressC>>(),
  /* 0E */ std::make_unique<LoadOperation<AddressC, StaticValue<0>>>(),
  /* 0F */ std::make_unique<ShiftAddressARightOperation>(),

  /* 10 */ std::make_unique<NoOperation>(), // DJNZ &4546
  /* 11 */ std::make_unique<LoadOperation<AddressDE, StaticValue<0>>>(),
  /* 12 */ std::make_unique<LoadOperation<AddressLocationDE, AddressA>>(),
  /* 13 */ std::make_unique<IncrementOperation<AddressDE>>(),
  /* 14 */ std::make_unique<IncrementOperation<AddressD>>(),
  /* 15 */ std::make_unique<DecrementOperation<AddressD>>(),
  /* 16 */ std::make_unique<LoadOperation<AddressD, StaticValue<0>>>(),
  /* 17 */ std::make_unique<ShiftLeftOperation<AddressA>>(),
  /* 18 */ std::make_unique<NoOperation>(), // JR &4546
  /* 19 */ std::make_unique<AddOperation<AddressHL, AddressDE>>(),
  /* 1A */ std::make_unique<LoadOperation<AddressA, AddressLocationDE>>(),
  /* 1B */ std::make_unique<DecrementOperation<AddressDE>>(),
  /* 1C */ std::make_unique<IncrementOperation<AddressE>>(),
  /* 1D */ std::make_unique<DecrementOperation<AddressE>>(),
  /* 1E */ std::make_unique<LoadOperation<AddressC, StaticValue<0>>>(),
  /* 1F */ std::make_unique<ShiftAddressARightOperation>(),

};
