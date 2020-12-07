// Tree Traversal - InOrder, PreOrder, Post Order
// Tree Traversal - BST / DST and  alternate BST(S- Tree Traversal)
#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;
struct node
{
	int data;
	struct node* right = NULL;
	struct node* left = NULL;
};

struct node* root = NULL;


int TreeHeight(node *root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return 0;
	}
	else
	{

		int lTree = 0;
		if (root->left != NULL)
		{
			lTree = TreeHeight(root->left);
		}

		int rTree = 0;

		if (root->right != NULL)
		{
			rTree = TreeHeight(root->right);
		}

		int height = 1 + (lTree > rTree ? lTree : rTree);
		return height;
	}
}

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

int GetTreeWidth(node* tree)
{
	if (tree == NULL) return 0;

	node* l = tree;
	node* r = tree;

	int width = 0;
	while (l != NULL)
	{
		l = l->left;
		if (left != NULL)
		{
			width++;
		}
	}
	while (r != NULL)
	{
		r = r->right;
		if (r != NULL)
		{
			width++;
		}
	}
	return width;
}

void BFS(node* tree, queue<node*>* ret)
{
	if (tree == NULL) return;
	queue<node*> q;

	q.push(tree);
	while (!q.empty())
	{
		node* next = q.front();
		q.pop();

		if (next->left != nullptr)
			q.push(next->left);
		if (next->right != nullptr)
			q.push(next->right);
		ret->push(next);
	}
}

///
/// Provides BFS traversal output
///

void BFS(node* tree)
{
	if (tree == NULL) return;
	queue<node*> q;

	q.push(tree);
	while (!q.empty())
	{
		node* next = q.front();
		q.pop();

		if (next->left != nullptr)
			q.push(next->left);
		if (next->right != nullptr)
			q.push(next->right);
		cout << next->data << " ";
	}
	cout << endl;
}

void SBFS(node* tree)
{
	if (tree == NULL) return;
	stack<node*> s1;
	stack<node*> s2;

	bool flag = true;
	s1.push(tree);
	while (!s1.empty() || !s2.empty())
	{
		node* next = NULL;
		if (flag)
		{
			next = s1.top();
			s1.pop();
			if (s1.empty())
			{
				flag = false; // Use S2 stack for next loop
			}
			// reading child nodes from left to right
			if (next->left != nullptr)
				s2.push(next->left);
			if (next->right != nullptr)
				s2.push(next->right);
		}
		else if (!flag)
		{
			next = s2.top();
			s2.pop();
			if (s2.empty())
			{
				flag = true; // Use S1 stack for next loop
			}
			// reading child nodes from right to left
			if (next->right != nullptr)
				s1.push(next->right);
			if (next->left != nullptr)
				s1.push(next->left);
		}
		
		cout << next->data << " ";
	}
	cout << endl; // new line
}


void PrintTree(node* tree)
{
	int w = GetTreeWidth(tree);
	w = w / 2;
	queue<node*>* bfsq = new queue<node*>();
	BFS(tree, bfsq);
	node* parent = tree;
	int i = 0;
	while (i < w)
	{
		cout << "\t";
		i++;
	}
	while (!bfsq->empty())
	{
		node* cur = bfsq->front();
		if (parent->left == cur)
		{
			cout << endl;
			parent = cur;
			w = w / 2;
			
			int i = 0;
			while (i < w)
			{
				cout << "\t";
				i++;
			}
		}
		cout << cur->data << "\t";
		bfsq->pop();
	}
	cout << endl;
}

node* GetClosestLeaf(node* root)
{
	if (root == NULL) return NULL;
	queue<node*> q;

	q.push(root);

	while (!q.empty())
	{
		node* next = q.front();
		q.pop();
		if (next->left == nullptr && next->right == nullptr)
		{
			return next;
		}
		else
		{
			if (next->left != nullptr)
				q.push(next->left);
			if (next->right != nullptr)
				q.push(next->right);
		}
	}
	return NULL;
}

int main()
{
	node *left = MakeTree(1, 2, 3);
	left->left->left = MakeNode(0);
	node *right = MakeTree(5, 6, 7);
	right->right->right = MakeNode(8);
	node *tree = MakeNode(4);
	tree->left = left;
	tree->right = right;

	int width = GetTreeWidth(tree);
	//cout << "Tree width: " << width << endl;
	//BFS(tree);
	cout << "S-BFS output: " << endl;
	SBFS(tree);

	cout << endl << "The MotherFUCKER Tree!!::" << endl;
	PrintTree(tree);
	cout << endl;

	cout << "Height: " << TreeHeight(tree) << endl;
	
	node* closestLeaf = GetClosestLeaf(tree);


	cout << "Closest Leaf:" << closestLeaf->data <<endl;
	return 0;
}

