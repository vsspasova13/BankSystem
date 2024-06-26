#pragma once
#include "EmployeeCommands/ApproveCmd.h"
#include "ClientCommands/ChangeCmd.h"
#include "ClientCommands/CheckAvlCmd.h"
#include "ClientCommands/CloseCmd.h"
#include "SystemCommands/CreateBankCmd.h"
#include "EmployeeCommands/DissaproveCmd.h"
#include "UserCommands/ExitCmd.h"
#include "UserCommands/HelpCmd.h"
#include "ClientCommands/ListCmd.h"
#include "SystemCommands/LoginCmd.h"
#include "ClientCommands/MessagesCmd.h"
#include "ClientCommands/OpenCmd.h"
#include "ClientCommands/RedeemCmd.h"
#include "ThirdPartyEmployeeCommands/SednCheckCmd.h"
#include "SystemCommands/SignUpCmd.h"
#include "EmployeeCommands/TasksCmd.h"
#include "EmployeeCommands/ValidateCmd.h"
#include "EmployeeCommands/ViewCmd.h"
#include "UserCommands/WhoAmICmd.h"
#include "../Utils/MyString.h"

class CommandFactory
{
	MyString text;
	MyString details;
public:
	CommandFactory()=default;
	CommandFactory(const MyString& text, const MyString& det) :text(text), details(det) {};
	Command* createCmd(const MyString& text)const;
};

