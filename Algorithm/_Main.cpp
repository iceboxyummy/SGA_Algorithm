#include "stdafx.h"
#include <iostream>
#include "Kruskal.h"

using namespace std;

int main()
{
	Kruskal k(4);

	k.AddEdge(Kruskal::Edge(0, 1, 3));
	k.AddEdge(Kruskal::Edge(0, 3, 2));
	k.AddEdge(Kruskal::Edge(1, 2, 2));
	k.AddEdge(Kruskal::Edge(1, 3, 5));
	k.AddEdge(Kruskal::Edge(2, 3, 4));

	cout << k.MakeMST(4);
}