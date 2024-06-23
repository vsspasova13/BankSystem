#pragma once
#include "ApproveCmd.h"
#include "ChangeCmd.h"
#include "CheckAvlCmd.h"
#include "CloseCmd.h"
#include "CreateBankCmd.h"
#include "DissaproveCmd.h"
#include "ExitCmd.h"
#include "HelpCmd.h"
#include "ListCmd.h"
#include "LoginCmd.h"
#include "MessagesCmd.h"
#include "OpenCmd.h"
#include "RedeemCmd.h"
#include "SednCheckCmd.h"
#include "SignUpCmd.h"
#include "TasksCmd.h"
#include "ValidateCmd.h"
#include "ViewCmd.h"
#include "WhoAmICmd.h"
#include "MyString.h"

class CommandFactory
{
	MyString text;
	MyString details;
public:
	CommandFactory()=default;
	CommandFactory(const MyString& text, const MyString& det) :text(text), details(det) {};
	Command* createCmd(const MyString& text)const;
};

