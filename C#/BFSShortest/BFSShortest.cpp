// BFSShortest.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

class Vertex
{
public:
	int num;
	vector<int> neighbors; // stores the index of the adjacent vertices
};


unordered_map<int, int> spath; // shortest path distances // hash table implementation
unordered_map<int, int> visitedmp; // shortest path distances // hash table implementation
vector<Vertex> graph;
int v, e;
int ci = -1; // current insertion point

int FindVertex(int num){
	for (int i = 0; i < graph.size(); i++){
		if (graph[i].num == num)
		{
			return i;
		}
	}

	return -1;
}

int AddNode(int num)
{
	Vertex vertex;
	vertex.num = num;
	ci++;
	//graph.reserve(ci + 1); // add the offset to get the capacity - zero based array
	//graph[ci] = vertex;
	graph.push_back(vertex);

	//Add it to spath
	spath[num] = -1; // initialize with -1
	visitedmp[num] = 0;
	return ci;
}

void AddChild(int p, int c){
	int idx = FindVertex(p);
	if (idx == -1){
		idx = AddNode(p);
	}

	int c_idx = FindVertex(c);
	if (c_idx == -1)
	{
		c_idx = AddNode(c);
	}

	Vertex v = graph[idx];
	v.neighbors.push_back(c_idx);
	graph[idx] = v;

	v = graph[c_idx];
	v.neighbors.push_back(idx);
	graph[c_idx] = v;
}

void reset()
{
	ci = -1;
	spath.clear();
	visitedmp.clear();
	graph.resize(0);
}

void BFSSTraverse(int v)  // v is the index of the starting vertex
{
	int stop = -1;
	int d = 0;
	int visited = 0;
	Vertex marker;
	marker.num = -1;

	queue<Vertex> q;
	Vertex node = graph[v];
	stop = node.num;

	q.push(node);
	q.push(marker);

	while (!q.empty())
	{
		Vertex node = (Vertex)q.front();
		q.pop();
		if (stop == node.num)
		{
			if (visited == 1)
			{
				continue;
			}
			if (visited == 0)
			{
				visited = 1;
			}
		}
		int num = node.num;
		if (num != -1) // not a marker
		{
			int cd = spath[num];
			if (cd == -1 || d < cd)
			{
				spath[num] = d;
				if (d != 0)
				{
					cout << d << " ";
				}
			}
			if (visitedmp[num] == 1 && spath[num] != -1 && spath[num] < d)
			{
				continue; // don't push in the queue
			}
			vector<int> nbor = node.neighbors;
			for (unsigned int i = 0; i < (nbor.size()); i++)
			{
				Vertex nb = graph[nbor[i]];
				q.push(nb);
			}
			visitedmp[num] = 1;
		}
		else
		{
			if (!q.empty())
			{
				d += 6;
				q.push(marker);
			}
		}
	}
}

int main()
{
	int tc = 0;// number of test cases
	cin >> tc;
	
	for (int t = 0; t < tc; t++)
	{
		cin >> v >> e;
		reset();
		int c = 0, p = 0;

		for (int i = 0; i < e; i++)
		{
			cin >> c >> p;
			AddChild(c, p);
		}

		while (graph.size() < v)
		{
			AddNode(10000); // dummy node
		}

		//cout << endl << endl;
		//for (int i = 0; i < graph.size(); i++)
		//{
		//	Vertex node = graph[i];
		//	cout << node.num << " -- ";
		//	for (int j = 0; j < node.neighbors.size(); j++){
		//		Vertex nbor = graph[node.neighbors[j]];
		//		cout << nbor.num << "; ";
		//	}
		//	cout << endl;
		//}

		cin >> p;
		int idx = FindVertex(p);
		BFSSTraverse(idx);
		for (int i = 0; i < graph.size(); i++)
		{
			int num = graph[i].num;
			if (spath[num] == -1)
			{
				cout << -1 << " ";
			}
		}
		cout << endl;
		
	}
	int x;
	cin >> x;
	return 0;
}
