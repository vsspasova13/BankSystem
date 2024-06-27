#include "ViewCmd.h"

ViewCmd::ViewCmd(Employee* e,int id) :e(e),id(id)
{
}

void ViewCmd::execute()
{
	e->view(id);
}
