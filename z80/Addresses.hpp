#pragma once
#include <string>

class CpuState;

class Address
{
public:
  virtual ~Address() = default;
  virtual bool is_byte() = 0;
  virtual bool is_word() = 0;

  virtual uint8_t get_byte(CpuState&) = 0;
  virtual void set_byte(CpuState&, uint8_t) = 0;

  virtual uint16_t get_word(CpuState&) = 0;
  virtual void set_word(CpuState&, uint16_t) = 0;

  virtual std::string get_name() = 0;
};

class AddressByte : public Address
{
public:
  bool is_byte() override { return true; }
  bool is_word() override { return false; }

  uint16_t get_word(CpuState&) override;

  void set_word(CpuState&, uint16_t) override;
};

class AddressWord : public Address
{
public:
  bool is_byte() override { return false; }
  bool is_word() override { return true; }

  uint8_t get_byte(CpuState&) override;

  void set_byte(CpuState&, uint8_t) override;
};

class AddressLocation : public Address {
  public:
  bool is_byte() override { return true; }
  bool is_word() override { return true; }
  
  virtual uint16_t get_address(CpuState&) const = 0;

  uint8_t get_byte(CpuState&) override { return 0; }
  void set_byte(CpuState&, uint8_t) override {};
  uint16_t get_word(CpuState&) override { return 0; }
  void set_word(CpuState&, uint16_t) override {};
};

template<uint16_t TValue>
class StaticValue : public Address
{
public:
  bool is_byte() override { return true; }
  bool is_word() override { return true; }
  uint8_t get_byte(CpuState&) override { return TValue; }
  void set_byte(CpuState&, uint8_t) override { }
  uint16_t get_word(CpuState&) override { return TValue; }
  void set_word(CpuState&, uint16_t) override { }
  std::string get_name() override;
};

class AddressA : public AddressByte
{
public:
  uint8_t get_byte(CpuState&) override { return 0; }
  void set_byte(CpuState&, uint8_t) override { }
  std::string get_name() override
  {
    return std::string("A");
  }
};

class AddressB : public AddressByte
{
public:
  uint8_t get_byte(CpuState&) override { return 0; }
  void set_byte(CpuState&, uint8_t) override { }
  std::string get_name() override
  {
    return std::string("B");
  }
};

class AddressC : public AddressByte
{
public:
  uint8_t get_byte(CpuState&) override { return 0; }
  void set_byte(CpuState&, uint8_t) override { }
  std::string get_name() override
  {
    return std::string("C");
  }
};

class AddressD : public AddressByte
{
public:
  uint8_t get_byte(CpuState&) override { return 0; }
  void set_byte(CpuState&, uint8_t) override { }
  std::string get_name() override
  {
    return std::string("D");
  }
};
class AddressE : public AddressByte
{
public:
  uint8_t get_byte(CpuState&) override { return 0; }
  void set_byte(CpuState&, uint8_t) override { }
  std::string get_name() override
  {
    return std::string("E");
  }
};

class AddressAF : public AddressWord
{
public:
  uint16_t get_word(CpuState&) override { return 0; }
  void set_word(CpuState&, uint16_t) override { }
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
  uint16_t get_word(CpuState&) override { return 0; }
  void set_word(CpuState&, uint16_t) override { }
  std::string get_name() override
  {
    return std::string("DE");
  }
};
class AddressHL : public AddressWord
{
public:
  uint16_t get_word(CpuState&) override { return 0; }
  void set_word(CpuState&, uint16_t) override { }
  std::string get_name() override
  {
    return std::string("HL");
  }
};
class AddressStackPointer : public AddressWord
{
public:
  uint16_t get_word(CpuState&) override { return 0; }
  void set_word(CpuState&, uint16_t) override { }
  std::string get_name() override
  {
    return std::string("Stack pointer");
  }
};
/*
class AddressAFShadow : public AddressWord
{
public:
  uint16_t get_word(CpuState&) override { return 0; }
  void set_word(CpuState&, uint16_t) override { }
  std::string get_name() override
  {
    return std::string("AF'");
  }
};
*/

class AddressLocationBC : public AddressLocation
{
public:
  std::string get_name() override
  {
    return std::string("(BC)");
  }
  uint16_t get_address(CpuState&) const { return 0; }
};
class AddressLocationDE : public AddressLocation
{
public:
  std::string get_name() override
  {
    return std::string("(DE)");
  }
  uint16_t get_address(CpuState&) const { return 0; }
};

class AddressNextByte : public AddressByte {
  public:
  uint8_t get_byte(CpuState&) override { return 0; }
  void set_byte(CpuState&, uint8_t) override {};
  std::string get_name() override {
    return std::string("d8");
  }
};

class AddressNextWord : public AddressWord {
  public:
  uint16_t get_word(CpuState&) override { return 0; }
  void set_word(CpuState&, uint16_t) override {};
  std::string get_name() override {
    return std::string("d16");
  }
};

class AddressLocationNextByte : public AddressLocation {
  public:
  
  std::string get_name() override {
    return std::string("(d8)");
  }
  uint16_t get_address(CpuState&) const { return 0; }
};

class AddressLocationNextWord : public AddressLocation {
  public:
  std::string get_name() override {
    return std::string("(d16)");
  }
  uint16_t get_address(CpuState&) const { return 0; }
};
