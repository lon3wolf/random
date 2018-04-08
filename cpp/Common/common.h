/// CL /c /Fo common.obj common.cpp /EHsc
#include <iostream>

class Node
{
    public:
        Node *left = nullptr;
        Node *right = nullptr;
        int data = 0;
        
        void printNode();
};

class Tree
{
    public:
    Node* root = nullptr;

    Tree();
    Tree(int i);
};

/// Simple binary tree using array
class SimpleTree
{
    private:
        int* arr;

    public:
        SimpleTree(int cap, int root); //cap: capacity

        int MakeLeft(int p, int d);
        
        int MakeRight(int p, int d);

        void PrintTree();
};