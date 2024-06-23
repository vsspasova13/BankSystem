#include "ViewCmd.h"

ViewCmd::ViewCmd(int id) :id(id)
{
}

void ViewCmd::execute()
{
	e.view(id);
}
