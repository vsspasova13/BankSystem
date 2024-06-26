#include "ApproveCmd.h"

ApproveCmd::ApproveCmd(int id) :id(id)
{

}

void ApproveCmd::execute()
{
	e.approve(id);
}
