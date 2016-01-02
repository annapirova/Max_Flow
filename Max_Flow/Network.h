#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "Граф\lib.h"
#include "Граф\Graf_list.h"
#include "TQueue.h"

class Network
{
	Graf_list net;
	double *c;
	double **f;
	TQueue<int> list;
	double *h;
	double *e;
	int size_net;

public:
	Network(int size = 5);
	Network(const Graf_matrix &gr);
	Network(const Network &nt);
	double Get_flow(int u, int v) { return f[u][v]; };
	void Set_flow(int u, int v, double val) { f[u][v] = val; };
	int Get_New_Active_Vertex() { return list.Pop(); };
	void Add_New_Active_Vertex(int vert) { list.Push(vert); };
	~Network();
};

#endif

