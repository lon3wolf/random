/// cl /c /Fo common.cpp /EHsc
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
/// only use unique elements, duplicate entries will fail this
class SimpleTree
{
    private:
        int* arr;

        int GetIndex(int p);

    public:
        SimpleTree(int cap, int root); //cap: capacity

        int MakeLeft(int p, int d);
        
        int MakeRight(int p, int d);

        int LeftNode(int p);

        int RightNode(int p);

        int GetRoot();

        void PrintTree();
};