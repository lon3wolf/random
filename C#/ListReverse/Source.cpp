#include <iostream>

using namespace std;

class Node
{
public:
	char data;
	Node* next;

	Node(char d, Node* parent = NULL)
	{
		if (parent != NULL)
		{
			parent->next = this;
		}
		this->data = d;
		this->next = NULL;
	}

	Node(){}
};

class List
{
	public:
		static void Traverse(Node* root)
		{
			Node* p = root;
			cout << endl;
			while (p != NULL)
			{
				cout << "->" << p->data;
				p = p->next;
			}
		}

		static Node* CreateSampleList()
		{
			Node* one = new Node('1');
			Node *two = new Node('2', one);
			Node *three = new Node('3', two);

			return one;
		}

		static Node* CreateCyclicList()
		{
			Node* one = new Node('1');
			Node *two = new Node('2', one);
			Node *three = new Node('3', two);
			Node *four = new Node('4', three);
			four->next = two;

			return one;
		}

		static Node* ReverseList(Node* root)
		{
			Node *t, *p, *q;
			p = root;
			q = p->next;
			t = q->next;
			while (p->next != NULL && q != NULL)
			{
				t = q->next;
				q->next = p;
				p = q;
				q = t;
			}
			root->next = NULL;
			return p;
		}
};

int main()
{
	int i = 0;
	Node* simple = List::CreateSampleList();
	List::Traverse(simple);
	
	Node* reversed = List::ReverseList(simple);
	List::Traverse(reversed);

	Node* cyclic = List::CreateCyclicList();
	//List::Traverse(cyclic);
	
	cin >> i;
}

