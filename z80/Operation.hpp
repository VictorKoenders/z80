#pragma once

#include <memory>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class CpuState
{

};


class Operation
{
public:
  static std::unique_ptr<Operation> Operations[256];

  Operation();
  ~Operation();

  virtual void execute(CpuState& state) = 0;
};



class Address
{
public:
  virtual bool is_byte() = 0;
  virtual bool is_word() = 0;

  virtual uint8_t get_byte(CpuState& state) = 0;
  virtual void set_byte(CpuState& state, uint8_t value) = 0;

  virtual uint16_t get_word(CpuState& state) = 0;
  virtual void set_word(CpuState& state, uint16_t value) = 0;

  virtual std::string get_name() = 0;
};

class AddressByte : public Address
{
public:
  bool is_byte() { return true; }
  bool is_word() { return false; }

  virtual uint16_t get_word(CpuState& state)
  {
    throw "Called get_word on a byte";
  }
  virtual void set_word(CpuState& state, uint16_t value)
  {
    throw "Called set_word on a byte";
  }
};

class AddressWord : public Address
{
public:
  bool is_byte() { return false; }
  bool is_word() { return true; }

  uint8_t get_byte(CpuState& state)
  {
    throw "Called set_byte on a word";
  }
  void set_byte(CpuState& state, uint8_t value)
  {
    throw "Called set_byte on a word";
  }
};


template<uint16_t TValue>
class StaticValue : public Address
{
public:
  bool is_byte() { return true; }
  bool is_word() { return true; }
  uint8_t get_byte(CpuState& state) { return TValue; }
  void set_byte(CpuState& state, uint8_t value) { }
  uint16_t get_word(CpuState& state) { return TValue; }
  void set_word(CpuState& state, uint16_t value) { }
  std::string get_name()
  {
    std::ostringstream stringStream;
    stringStream << "0x" << std::setw(4) << std::setfill('0') << std::hex << TValue;
    return stringStream.str();
  }
};

class AddressA : public AddressByte
{
public:
	uint8_t get_byte(CpuState& state) { return 0; }
	void set_byte(CpuState& state, uint8_t value) { }
	std::string get_name()
	{
		return std::string("A");
	}
};

class AddressB : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) { return 0; }
  void set_byte(CpuState& state, uint8_t value) { }
  std::string get_name()
  {
    return std::string("B");
  }
};

class AddressC : public AddressByte
{
public:
	uint8_t get_byte(CpuState& state) { return 0; }
	void set_byte(CpuState& state, uint8_t value) { }
	std::string get_name()
	{
		return std::string("C");
	}
};

class AddressD : public AddressByte
{
public:
	uint8_t get_byte(CpuState& state) { return 0; }
	void set_byte(CpuState& state, uint8_t value) { }
	std::string get_name()
	{
		return std::string("D");
	}
};
class AddressE : public AddressByte
{
public:
	uint8_t get_byte(CpuState& state) { return 0; }
	void set_byte(CpuState& state, uint8_t value) { }
	std::string get_name()
	{
		return std::string("E");
	}
};

class AddressAF : public AddressWord
{
public:
	uint16_t get_word(CpuState& state) { return 0; }
	void set_word(CpuState& state, uint16_t value) { }
	std::string get_name()
	{
		return std::string("AF");
	}
};
class AddressBC : public AddressWord
{
public:
  uint16_t get_word(CpuState& state) { return 0; }
  void set_word(CpuState& state, uint16_t value) { }
  std::string get_name()
  {
    return std::string("BC");
  }
};
class AddressDE : public AddressWord
{
public:
  uint16_t get_word(CpuState& state) { return 0; }
  void set_word(CpuState& state, uint16_t value) { }
  std::string get_name()
  {
    return std::string("DE");
  }
};
class AddressHL : public AddressWord
{
public:
	uint16_t get_word(CpuState& state) { return 0; }
	void set_word(CpuState& state, uint16_t value) { }
	std::string get_name()
	{
		return std::string("HL");
	}
};
class AddressAFShadow : public AddressWord
{
public:
  uint16_t get_word(CpuState& state) { return 0; }
  void set_word(CpuState& state, uint16_t value) { }
  std::string get_name()
  {
    return std::string("AF'");
  }
};

class AddressLocationBC : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) { return 0; }
  void set_byte(CpuState& state, uint8_t value) { }
  std::string get_name()
  {
    return std::string("(BC)");
  }
};
class AddressLocationDE : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) { return 0; }
  void set_byte(CpuState& state, uint8_t value) { }
  std::string get_name()
  {
    return std::string("(DE)");
  }
};

class NoOperation : public Operation
{
public:
  void execute(CpuState& state);
};

template<class TInto, class TFrom>
class LoadOperation : public Operation
{
public:
  void execute(CpuState& state) 
  {
    TFrom from;
    TInto into;
    std::cout << "Loading " << from.get_name() << " into " << into.get_name() << std::endl;
  }
};

template<class TAddress>
class IncrementOperation : public Operation
{
public:
  void execute(CpuState& state) 
  {
    TAddress address;
    std::cout << "Incrementing " << address.get_name() << std::endl;
  }
};
template<class TAddress>
class DecrementOperation : public Operation
{
public:
  void execute(CpuState& state)
  {
    TAddress address;
    std::cout << "Decrementing " << address.get_name() << std::endl;
  }
};
template<class TAddress>
class ShiftLeftOperation : public Operation
{
public:
  void execute(CpuState& state)
  {
    TAddress address;
    std::cout << "Rotate " << address.get_name() << " left" << std::endl;
  }
};

class ShiftAddressALeftOperation : public Operation
{
public:
  void execute(CpuState& state)
  {
    std::cout << "Quickly rotate A left" << std::endl;
  }
};
class ShiftAddressARightOperation : public Operation
{
public:
  void execute(CpuState& state)
  {
    std::cout << "Quickly rotate A right" << std::endl;
  }
};
template<class TInto, class TFrom>
class ExchangeOperation : public Operation
{
public:
	void execute(CpuState& state)
	{
		TFrom from;
		TInto into;
		std::cout << "Exchanging " << from.get_name() << " and " << into.get_name() << std::endl;
	}
};
template<class TInto, class TFrom>
class AddOperation : public Operation
{
public:
	void execute(CpuState& state)
	{
		TFrom from;
		TInto into;
		std::cout << "Adding " << from.get_name() << " and " << into.get_name() << std::endl;
	}
};
