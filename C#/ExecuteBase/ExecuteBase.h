#pragma once
class ExecuteBase
{
public:
	ExecuteBase();
	~ExecuteBase();

	virtual void TakeInput();
	virtual void Execute();
	virtual void CleanUp();

	void Run();
};

