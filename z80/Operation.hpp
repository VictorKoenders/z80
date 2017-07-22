#pragma once

#include <functional>
#include <array>

class CpuState
{

};

using Operation = std::function<void(CpuState&)>;
extern std::array<Operation, 256> Operations;

class Address
{
public:
  virtual ~Address() = default;
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
  bool is_byte() override { return true; }
  bool is_word() override { return false; }

  uint16_t get_word(CpuState& state) override;

  void set_word(CpuState& state, uint16_t value) override;
};

class AddressWord : public Address
{
public:
  bool is_byte() override { return false; }
  bool is_word() override { return true; }

  uint8_t get_byte(CpuState& state) override;

  void set_byte(CpuState& state, uint8_t value) override;
};


template<uint16_t TValue>
class StaticValue : public Address
{
public:
  bool is_byte() override { return true; }
  bool is_word() override { return true; }
  uint8_t get_byte(CpuState& state) override { return TValue; }
  void set_byte(CpuState& state, uint8_t value) override { }
  uint16_t get_word(CpuState& state) override { return TValue; }
  void set_word(CpuState& state, uint16_t value) override { }
  std::string get_name() override;
};

class AddressA : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) override { return 0; }
  void set_byte(CpuState& state, uint8_t value) override { }
  std::string get_name() override
  {
    return std::string("A");
  }
};

class AddressB : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) override { return 0; }
  void set_byte(CpuState& state, uint8_t value) override { }
  std::string get_name() override
  {
    return std::string("B");
  }
};

class AddressC : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) override { return 0; }
  void set_byte(CpuState& state, uint8_t value) override { }
  std::string get_name() override
  {
    return std::string("C");
  }
};

class AddressD : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) override { return 0; }
  void set_byte(CpuState& state, uint8_t value) override { }
  std::string get_name() override
  {
    return std::string("D");
  }
};
class AddressE : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) override { return 0; }
  void set_byte(CpuState& state, uint8_t value) override { }
  std::string get_name() override
  {
    return std::string("E");
  }
};

class AddressAF : public AddressWord
{
public:
  uint16_t get_word(CpuState& state) override { return 0; }
  void set_word(CpuState& state, uint16_t value) override { }
  std::string get_name() override
  {
    return std::string("AF");
  }
};
class AddressBC : public AddressWord
{
public:
  uint16_t get_word(CpuState& state) override { return 0; }
  void set_word(CpuState& state, uint16_t value) override { }
  std::string get_name() override
  {
    return std::string("BC");
  }
};
class AddressDE : public AddressWord
{
public:
  uint16_t get_word(CpuState& state) override { return 0; }
  void set_word(CpuState& state, uint16_t value) override { }
  std::string get_name() override
  {
    return std::string("DE");
  }
};
class AddressHL : public AddressWord
{
public:
  uint16_t get_word(CpuState& state) override { return 0; }
  void set_word(CpuState& state, uint16_t value) override { }
  std::string get_name() override
  {
    return std::string("HL");
  }
};
class AddressAFShadow : public AddressWord
{
public:
  uint16_t get_word(CpuState& state) override { return 0; }
  void set_word(CpuState& state, uint16_t value) override { }
  std::string get_name() override
  {
    return std::string("AF'");
  }
};

class AddressLocationBC : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) override { return 0; }
  void set_byte(CpuState& state, uint8_t value) override { }
  std::string get_name() override
  {
    return std::string("(BC)");
  }
};
class AddressLocationDE : public AddressByte
{
public:
  uint8_t get_byte(CpuState& state) override { return 0; }
  void set_byte(CpuState& state, uint8_t value) override { }
  std::string get_name() override
  {
    return std::string("(DE)");
  }
};

void NoOperation(CpuState& state);

template<class TInto, class TFrom>
void LoadOperation(CpuState& state);

template<class TAddress>
void IncrementOperation(CpuState& state);

template<class TAddress>
void DecrementOperation(CpuState& state);

template<class TAddress>
void ShiftLeftOperation(CpuState& state);

void ShiftAddressALeftOperation(CpuState& state);

void ShiftAddressARightOperation(CpuState& state);

template<class TInto, class TFrom>
void ExchangeOperation(CpuState& state);

template<class TInto, class TFrom>
void AddOperation(CpuState& state);
