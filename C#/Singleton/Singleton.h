#include <iostream>
using namespace std;

class Singleton
{
private:
	static Singleton* instance;
	int data;
	
	Singleton()
	{
		data = 0;
		instance = this;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	~Singleton()
	{
		
	}
public:
	string msg;
	static Singleton* getInstance()
	{
		if (instance == NULL)
		{
			// initialize object
			instance = new Singleton();
		}
		return instance;
	}

	int get(){ return data; }
	void set(int value){ data = value; }
};

//Singleton* Singleton::getInstance()
//{
//	if (instance == NULL)
//	{
//		// initialize object
//		instance = new Singleton();
//	}
//	return instance;
//}

