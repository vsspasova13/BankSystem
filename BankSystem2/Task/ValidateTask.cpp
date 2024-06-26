#include "ValidateTask.h"

bool ValidateTask::validate() const
{
    System& s = System::getInstance();
    return s.findBankByName(currBankName).containsClientByAccountNum(acc_Num);
}
