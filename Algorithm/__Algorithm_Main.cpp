#include "stdafx.h"

//===============
// [ Macro ]
//===============

#ifdef ALGORITHM_MAIN

//#define KRUSSKAL
#define PRIM

#endif 

//==================
// [ KRUSSKAL ]
//==================

#ifdef KRUSSKAL

#include <iostream>
#include "Kruskal.h"

using namespace std;

int main()
{
	Kruskal k;

	k.AddEdge(Kruskal::Edge(0, 1, 3));
	k.AddEdge(Kruskal::Edge(0, 3, 2));
	k.AddEdge(Kruskal::Edge(1, 2, 2));
	k.AddEdge(Kruskal::Edge(1, 3, 5));
	k.AddEdge(Kruskal::Edge(2, 3, 4));

	cout << k.MakeMST(4);
}

#endif

//==================
// [ PRIM ]
//==================

#ifdef PRIM

#include<iostream>
#include "Prim.h"

using namespace std;

int main()
{
   Prim p(6);

   p.AddEdge(0, 1, 25);
   p.AddEdge(0, 2, 20);
   p.AddEdge(0, 3, 15);
   p.AddEdge(0, 4, 10);
   p.AddEdge(1, 5, 17);
   p.AddEdge(4, 5, 13);
   p.AddEdge(4, 3, 7);
   p.AddEdge(3, 2, 23);

   cout << p.MakeMST();

   return 0;
}

#endif 