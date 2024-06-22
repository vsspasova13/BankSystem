#include "DissaproveCmd.h"

DisapproveCmd::DisapproveCmd(int id, const MyString& mes) :id(id), message(mes)
{
}

void DisapproveCmd::execute()
{
	e.disapprove(id, message);
}