#include "Addresses.hpp"
#include <iomanip>
#include <sstream>

template class StaticValue<0>;

uint16_t AddressByte::get_word(CpuState&)
{
  throw "Called get_word on a byte";
}

void AddressByte::set_word(CpuState&, uint16_t)
{
  throw "Called set_word on a byte";
}

uint8_t AddressWord::get_byte(CpuState&)
{
  throw "Called set_byte on a word";
}

void AddressWord::set_byte(CpuState&, uint8_t)
{
  throw "Called set_byte on a word";
}

template <uint16_t TValue>
std::string StaticValue<TValue>::get_name()
{
  std::ostringstream stringStream;
  stringStream << "0x" << std::setw(4) << std::setfill('0') << std::hex << TValue;
  return stringStream.str();
}
