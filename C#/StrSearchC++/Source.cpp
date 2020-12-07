#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str = "I am working in noon";
	string substr = "noon";

	int loc = str.find(substr);
	cout << "Location: " << loc << endl;
	return 0;
}