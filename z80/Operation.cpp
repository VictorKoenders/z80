#include "Operation.hpp"
#include "Addresses.hpp"
#include "CpuState.hpp"
#include "Conditions.hpp"

#include <sstream>
#include <iostream>

std::array<Operation, 256> Operations = {
  /* 00 */ &NoOperation,
  /* 01 */ &LoadOperation<AddressBC, AddressNextWord>,
  /* 02 */ &LoadOperation<AddressLocationBC, AddressA>,
  /* 03 */ &IncrementOperation<AddressBC>,
  /* 04 */ &IncrementOperation<AddressB>,
  /* 05 */ &DecrementOperation<AddressB>,
  /* 06 */ &LoadOperation<AddressB, AddressNextByte>,
  /* 07 */ &ShiftAddressALeftOperation,
  /* 08 */ &LoadOperation<AddressLocationNextWord, AddressStackPointer>,
  /* 09 */ &AddOperation<AddressHL, AddressBC>,
  /* 0A */ &LoadOperation<AddressA, AddressLocationBC>,
  /* 0B */ &DecrementOperation<AddressBC>,
  /* 0C */ &IncrementOperation<AddressC>,
  /* 0D */ &DecrementOperation<AddressC>,
  /* 0E */ &LoadOperation<AddressC, AddressNextByte>,
  /* 0F */ &ShiftAddressARightOperation,

  /* 10 */ &StopOperation,
  /* 11 */ &LoadOperation<AddressDE, AddressNextWord>,
  /* 12 */ &LoadOperation<AddressLocationDE, AddressA>,
  /* 13 */ &IncrementOperation<AddressDE>,
  /* 14 */ &IncrementOperation<AddressD>,
  /* 15 */ &DecrementOperation<AddressD>,
  /* 16 */ &LoadOperation<AddressD, AddressNextByte>,
  /* 17 */ &ShiftLeftOperation<AddressA>,
  /* 18 */ &RelativeJumpOperation<ConditionTrue, AddressNextByte>,
  /* 19 */ &AddOperation<AddressHL, AddressDE>,
  /* 1A */ &LoadOperation<AddressA, AddressLocationDE>,
  /* 1B */ &DecrementOperation<AddressDE>,
  /* 1C */ &IncrementOperation<AddressE>,
  /* 1D */ &DecrementOperation<AddressE>,
  /* 1E */ &LoadOperation<AddressC, AddressNextByte>,
  /* 1F */ &ShiftAddressARightOperation,

  /* 20 */ &RelativeJumpOperation<ConditionNotZero, AddressNextByte>

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

void StopOperation(CpuState&){
  std::cout << "Stopping" << std::endl;
}

template <class TCondition, class TOffset>
void RelativeJumpOperation(CpuState&){
  TCondition condition;
  TOffset offset;
  std::cout << "Jumping relatively to " << offset.get_name() << " if condition is true" << std::endl;
}
