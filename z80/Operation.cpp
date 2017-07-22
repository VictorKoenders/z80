#include "Operation.hpp"
#include <sstream>
#include <iomanip>
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

uint16_t AddressByte::get_word(CpuState& state)
{
  throw "Called get_word on a byte";
}

void AddressByte::set_word(CpuState& state, uint16_t value)
{
  throw "Called set_word on a byte";
}

uint8_t AddressWord::get_byte(CpuState& state)
{
  throw "Called set_byte on a word";
}

void AddressWord::set_byte(CpuState& state, uint8_t value)
{
  throw "Called set_byte on a word";
}

void NoOperation(CpuState& state)
{
  std::cout << "NOP" << std::endl;
}

void ShiftAddressALeftOperation(CpuState& state)
{
  std::cout << "Quickly rotate A left" << std::endl;
}

void ShiftAddressARightOperation(CpuState& state)
{
  std::cout << "Quickly rotate A right" << std::endl;
}

template <uint16_t TValue>
std::string StaticValue<TValue>::get_name()
{
  std::ostringstream stringStream;
  stringStream << "0x" << std::setw(4) << std::setfill('0') << std::hex << TValue;
  return stringStream.str();
}

template <class TInto, class TFrom>
void LoadOperation(CpuState& state)
{
  TFrom from;
  TInto into;
  std::cout << "Loading " << from.get_name() << " into " << into.get_name() << std::endl;
}

template <class TAddress>
void IncrementOperation(CpuState& state)
{
  TAddress address;
  std::cout << "Incrementing " << address.get_name() << std::endl;
}

template <class TAddress>
void DecrementOperation(CpuState& state)
{
  TAddress address;
  std::cout << "Decrementing " << address.get_name() << std::endl;
}

template <class TAddress>
void ShiftLeftOperation(CpuState& state)
{
  TAddress address;
  std::cout << "Shifting " << address.get_name() << " left" << std::endl;
}

template <class TInto, class TFrom>
void ExchangeOperation(CpuState& state)
{
  TFrom from;
  TInto into;
  std::cout << "Exchanging " << from.get_name() << " and " << into.get_name() << std::endl;
}

template <class TInto, class TFrom>
void AddOperation(CpuState& state)
{
  TFrom from;
  TInto into;
  std::cout << "Adding " << from.get_name() << " and " << into.get_name() << std::endl;
}

