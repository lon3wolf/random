#include "stdafx.h"
#include "ExecuteBase.h"
#include <iostream>

using namespace std;

ExecuteBase::ExecuteBase()
{
}


ExecuteBase::~ExecuteBase()
{
}

void ExecuteBase::Run()
{
		TakeInput();
		Execute();
		CleanUp();

		cout << "Enter anything to exit >";
		getchar();
}