#include "ValidateCmd.h"

ValidateCmd::ValidateCmd(Employee* e,int id) :e(e),id(id)
{
}

void ValidateCmd::execute()
{
	e->validate(id);
}
