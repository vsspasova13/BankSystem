#include "SednCheckCmd.h"

SednCheckCmd::SednCheckCmd(long sum, const MyString& code, long egn)
{
	this->code = code;
	this->egn = egn;
	this->sum = sum;
}

void SednCheckCmd::execute()
{
	t.send_check(sum, code, egn);
}
