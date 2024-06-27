#include "DissaproveCmd.h"

DisapproveCmd::DisapproveCmd(Employee* e,int id, const MyString& mes) :e(e),id(id), message(mes)
{
}

void DisapproveCmd::execute()
{
	e->disapprove(id, message);
}