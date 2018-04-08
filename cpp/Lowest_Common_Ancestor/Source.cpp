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


// Just a verification code
void TestSimpleTree()
{
    std::cout << "Solution is running" << std::endl;
    SimpleTree tree(20, 2);
    tree.MakeRight(2, 3);
    tree.MakeLeft(2, 1);

    std::cout << "Left: " << tree.LeftNode(2) << endl;
    std::cout << "Right: " << tree.RightNode(2) << endl;

    tree.PrintTree();

    std::cout << "Solution completed" << std::endl;
}

int main()
{
    return 0;
}


