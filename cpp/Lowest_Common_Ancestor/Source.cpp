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

// may be move it to common or some common place
// Makes a simple BST (Binary search tree)
// Image of the tree
// https://www.geeksforgeeks.org/wp-content/uploads/2009/08/BST_LCA.gif
SimpleTree MakeProblemTree()
{
    SimpleTree tree(7, 20);
    tree.MakeLeft(20, 8);
    tree.MakeLeft(8, 4);
    tree.MakeRight(20, 22);
    tree.MakeRight(8, 12);
    tree.MakeRight(12, 14);
    tree.MakeLeft(12, 10);

    return tree;
}

int FindLCA(SimpleTree tree, int d1, int d2)
{
    int current = 0; 
    
    // we assume d2 > d1, if not then correct it
    if(d1 > d2)
    {
        // swap d1 and d2 to make d2 > d1
        d1 = d1 - d2;
        d2 = d2 + d1;
        d1 = d2 - d1;
        
        /*
            d1:5 d2;3
            d1 = 5-3 = 2
            d2 = 3 + 2 = 5
            d1 = 5 - 2 = 3
        */
    }
    
    current = tree.GetRoot();

    while(!(d1 < current && current < d2))
    {
        if(current > d1 && current > d2)
        {
            current  = tree.LeftNode(current);
        }
        else
        {
            current = tree.RightNode(current);
        }
        if( d1 == current || d2 == current)
            break;
    }

    return current;
}

int main()
{
    auto tree = MakeProblemTree();

    // LCA of 10 & 14
    std::cout << "LCA of 10 & 14: " << FindLCA(tree, 14, 10) << std::endl;

    // LCA of 8 and 14
    std::cout << "LCA of 8 and 14: " << FindLCA(tree, 8, 14) << std::endl;
    
    // LCA of 10 and 22
    std::cout << "LCA of 10 and 22:     " << FindLCA(tree, 10, 22) << std::endl;

    return 0;
}

