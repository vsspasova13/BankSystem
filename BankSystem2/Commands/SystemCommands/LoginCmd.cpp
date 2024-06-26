#include "LoginCmd.h"

void LoginCmd::execute()
{
	s.login(name, pass);
}
