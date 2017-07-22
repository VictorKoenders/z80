#pragma once

#include <functional>
#include <array>

class CpuState;

using Operation = std::function<void(CpuState&)>;
extern std::array<Operation, 256> Operations;

void NoOperation(CpuState&);

template<class TInto, class TFrom>
void LoadOperation(CpuState&);

template<class TAddress>
void IncrementOperation(CpuState&);

template<class TAddress>
void DecrementOperation(CpuState&);

template<class TAddress>
void ShiftLeftOperation(CpuState&);

void ShiftAddressALeftOperation(CpuState&);

void ShiftAddressARightOperation(CpuState&);

template<class TInto, class TFrom>
void ExchangeOperation(CpuState&);

template<class TInto, class TFrom>
void AddOperation(CpuState&);
