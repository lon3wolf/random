// Given values of two values n1 and n2 in a 
// Binary Search Tree, find the Lowest Common Ancestor (LCA). You may assume that both the values exist in the tree. 
// https://www.geeksforgeeks.org/?p=1029
// 
// Complexity : 
// compile command => cl source.cpp /o test.exe /EHsc
// cl /Fo ..\Common\common.obj /o test.exe Source.cpp  /EHsc
#include <iostream>
#include "../common/common.h"

using namespace std;

int main()
{
    Tree* ptree = new Tree(2);
    ptree->root->printNode();
    
    std::cout << "This is a fucking test." << std::endl;

	return 0;
}
