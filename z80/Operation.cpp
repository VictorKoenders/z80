#include "Operation.hpp"
#include "Addresses.hpp"
#include "CpuState.hpp"

#include <sstream>
#include <iostream>

extern std::array<Operation, 256> Operations = {
  /* 00 */ &NoOperation,
  /* 01 */ &LoadOperation<AddressBC, StaticValue<0>>,
  /* 02 */ &LoadOperation<AddressLocationBC, AddressA>,
  /* 03 */ &IncrementOperation<AddressBC>,
  /* 04 */ &IncrementOperation<AddressB>,
  /* 05 */ &DecrementOperation<AddressB>,
  /* 06 */ &LoadOperation<AddressB, StaticValue<0>>,
  /* 07 */ &ShiftAddressALeftOperation,
  /* 08 */ &ExchangeOperation<AddressAF, AddressAFShadow>,
  /* 09 */ &AddOperation<AddressHL, AddressBC>,
  /* 0A */ &LoadOperation<AddressA, AddressLocationBC>,
  /* 0B */ &DecrementOperation<AddressBC>,
  /* 0C */ &IncrementOperation<AddressC>,
  /* 0D */ &DecrementOperation<AddressC>,
  /* 0E */ &LoadOperation<AddressC, StaticValue<0>>,
  /* 0F */ &ShiftAddressARightOperation,

  /* 10 */ &NoOperation, // DJNZ &4546
  /* 11 */ &LoadOperation<AddressDE, StaticValue<0>>,
  /* 12 */ &LoadOperation<AddressLocationDE, AddressA>,
  /* 13 */ &IncrementOperation<AddressDE>,
  /* 14 */ &IncrementOperation<AddressD>,
  /* 15 */ &DecrementOperation<AddressD>,
  /* 16 */ &LoadOperation<AddressD, StaticValue<0>>,
  /* 17 */ &ShiftLeftOperation<AddressA>,
  /* 18 */ &NoOperation, // JR &4546
  /* 19 */ &AddOperation<AddressHL, AddressDE>,
  /* 1A */ &LoadOperation<AddressA, AddressLocationDE>,
  /* 1B */ &DecrementOperation<AddressDE>,
  /* 1C */ &IncrementOperation<AddressE>,
  /* 1D */ &DecrementOperation<AddressE>,
  /* 1E */ &LoadOperation<AddressC, StaticValue<0>>,
  /* 1F */ &ShiftAddressARightOperation,

};

void NoOperation(CpuState&)
{
  std::cout << "NOP" << std::endl;
}

void ShiftAddressALeftOperation(CpuState&)
{
  std::cout << "Quickly rotate A left" << std::endl;
}

void ShiftAddressARightOperation(CpuState&)
{
  std::cout << "Quickly rotate A right" << std::endl;
}

template <class TInto, class TFrom>
void LoadOperation(CpuState&)
{
  TFrom from;
  TInto into;
  std::cout << "Loading " << from.get_name() << " into " << into.get_name() << std::endl;
}

template <class TAddress>
void IncrementOperation(CpuState&)
{
  TAddress address;
  std::cout << "Incrementing " << address.get_name() << std::endl;
}

template <class TAddress>
void DecrementOperation(CpuState&)
{
  TAddress address;
  std::cout << "Decrementing " << address.get_name() << std::endl;
}

template <class TAddress>
void ShiftLeftOperation(CpuState&)
{
  TAddress address;
  std::cout << "Shifting " << address.get_name() << " left" << std::endl;
}

template <class TInto, class TFrom>
void ExchangeOperation(CpuState&)
{
  TFrom from;
  TInto into;
  std::cout << "Exchanging " << from.get_name() << " and " << into.get_name() << std::endl;
}

template <class TInto, class TFrom>
void AddOperation(CpuState&)
{
  TFrom from;
  TInto into;
  std::cout << "Adding " << from.get_name() << " and " << into.get_name() << std::endl;
}

