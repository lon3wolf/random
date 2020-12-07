#pragma once
namespace UtilitiesNS
{
	class Utilities
	{
	public:
		Utilities();
		~Utilities();
		static int* ToBinary(unsigned int, unsigned int*);
		static void ShowBinary(unsigned int*, int);
	};

}