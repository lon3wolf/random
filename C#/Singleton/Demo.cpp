#include "Singleton.h"

class SingletonDemo
{
public:
	void show()
	{
		Singleton* s1 = Singleton::getInstance();
		cout << "Initial value: " << s1->get() << endl;
		s1->set(25);
		s1->msg = "I have been dead once";
		s1 = NULL;

		Singleton* s2 = Singleton::getInstance();
		cout << "New value (default for S2): " << s2->get() << endl;
		cout << s2->msg.c_str() << endl;
	}

};

int main()
{
	SingletonDemo demo;
	demo.show();
	getchar();
	return 0;
}