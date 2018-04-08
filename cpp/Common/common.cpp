// cl /c /Fo common.cpp /EHsc

#include "common.h"

void Node::printNode()
{
    std::cout << "Data: " << data << std::endl;
}

Tree::Tree()
{
    root = new Node();
}

Tree::Tree(int i)
{
    root = new Node();
    root->data = i;
}

SimpleTree::SimpleTree(int cap, int root) //cap: capacity
{
    arr = new int[cap + 1];
    arr[0] = cap;
    arr[1] = root;
}

int SimpleTree::GetIndex(int p)
{
    int i = 0;
    for(i = 1; i < arr[0]; i++)
    {
        if(p == arr[i])
            break;
    }

    return i;
}

int SimpleTree::GetRoot()
{
    return arr[1];
}

int SimpleTree::MakeRight(int p, int d)
{
    int i = GetIndex(p);

    if((2*i + 1) < arr[0])
    {
        arr[2*i+1] = d;
        return 0;
    }   
    else
    {
        return -1;
    }
}

int SimpleTree::MakeLeft(int p, int d)
{
    int i = GetIndex(p);

    if(2*i < arr[0])
    {
        arr[2*i] = d;
        return 0;
    }   
    else
    {
        return -1;
    }
}

int SimpleTree::LeftNode(int p)
{
    int i = GetIndex(p);
    if(2*i < arr[0])
    {
        return arr[2*i];
    }
    else
    {
        return NULL;
    }
}

int SimpleTree::RightNode(int p)
{
    int i = GetIndex(p);
    if(2*i+1 < arr[0])
    {
        return arr[2*i + 1];
    }
    else
    {
        return NULL;
    }
}

void SimpleTree::PrintTree()
{
    // not sure how I want to display it right now,
    // just print out the array as of now

    std::cout << std::endl << "Capacity : " << arr[0] << std::endl;
    for(int i=1; i < arr[0]; i++)
    {
        std::cout << arr[i] << " ";
    } 

    std::cout << std::endl; 
}