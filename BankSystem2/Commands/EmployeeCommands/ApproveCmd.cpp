#include "ApproveCmd.h"

ApproveCmd::ApproveCmd(Employee* e,int id) :e(e),id(id)
{

}

void ApproveCmd::execute()
{
	e->approve(id);
}
