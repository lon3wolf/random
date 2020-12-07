#include <iostream>
#include <stack>
#include <string>

using namespace std;
struct node
{
	int data;
	struct node* right = NULL;
	struct node* left = NULL;

};
struct node* root = NULL;

struct node* MakeNode(int n)
{
	struct node* nod = new struct node();
	nod->data = n;
	return nod;
}

struct node* MakeTree(int l, int d, int r)
{
	root = new struct node();
	root->data = d;
	root->left = MakeNode(l);
	root->right = MakeNode(r);
	return root;
}

void InOrder(struct node* root)
{
	if (root->left != NULL)
	{
		InOrder(root->left);
	}
	cout << root->data << endl;
	if (root->right != NULL)
	{
		InOrder(root->right);
	}
}
void PreOrder(struct node* root)
{
	cout << root->data << endl;
	if (root->left != NULL)
	{
		InOrder(root->left);
	}
	
	if (root->right != NULL)
	{
		InOrder(root->right);
	}
}
void PostOrder(struct node* root)
{
	
	if (root->left != NULL)
	{
		InOrder(root->left);
	}

	if (root->right != NULL)
	{
		InOrder(root->right);
	}
	cout << root->data << endl;
}

int searchString(string a, string b){
	int i = 0, j = 0;
	char s = a[i];
	char c = b[j];
	int index = 0;
	for (i = 0; i < a.length; i++)
	{
		for (j = 0; j< a.length; )
		{
			s = a[i];
			c = b[j];

			if (s == c)
			{
				index = i;
				i++;
				j++;
				if (i >= a.length)
				{

				}
			}
		}
	}
}

int main()
{


	/*stack<int> a = stack<int>();
	a.push(2);
	a.push(3);
	a.push(4);*/
	/*while (!a.empty())
	{
		cout << a.top() << " - ";
		a.pop();
	}*/
	//cout << endl; 

	root = MakeTree(1, 2, 3);
	InOrder(root);
	PreOrder(root);
	PostOrder(root);
	std::getchar();
	return 0;
}
