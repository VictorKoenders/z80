#include "CpuState.hpp"
#include <functional>

using Condition = std::function<bool(CpuState&)>;

bool ConditionTrue(CpuState&);
bool ConditionNotZero(CpuState&);
bool ConditionZero(CpuState&);