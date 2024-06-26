#include "ValidateCmd.h"

ValidateCmd::ValidateCmd(int id) :id(id)
{
}

void ValidateCmd::execute()
{
	e.validate(id);
}
