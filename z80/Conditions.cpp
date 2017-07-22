#include "Conditions.hpp"


bool ConditionTrue(CpuState&){
    return true;
}
bool ConditionNotZero(CpuState&){
    return true;
}
bool ConditionZero(CpuState&){
    return false;
}