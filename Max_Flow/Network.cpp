#include "Network.h"



Network::Network(int size): net(size, size * size), list(size)
{
	size_net = size;

	c = new double[size_net * size_net];
	for (int i = 0; i < size_net * size_net; i++)
		c[i] = 0;

	h = new double[size_net];
	e = new double[size_net];

	f = new double*[size_net];
	for (int i = 0; i < size_net; i++)
	{
		f[i] = new double[size_net];
		for (int j = 0; j < size_net; j++)
			f[i][j] = 0;
		h[i] = 0; e[i] = 0;
	}
}

Network::Network(const Graf_matrix &gr) :
	net(gr), list(gr.Get_Size_M())
{
	size_net = gr.Get_Size_M;

	c = new double[size_net * size_net];

	int m = 0, k = 0;
	for (int i = 0; i < size_net; i++)
		for (int j = 0; j < size_net; j++)
			if (gr[i][j] != 0)
			{
				c[m] = gr[i][j];
				m++;
				k++;
			}

	h = new double[size_net];
	e = new double[size_net];

	f = new double*[size_net];
	for (int i = 0; i < size_net; i++)
	{
		f[i] = new double[size_net];
		for (int j = 0; j < size_net; j++)
			f[i][j] = 0;
		h[i] = 0; e[i] = 0;
	}
}

Network::Network(const Network &nt): 
	size_net(nt.size_net), net(nt.net), list(nt.list)
{
	c = new double[size_net * size_net];
	for (int i = 0; i < size_net * size_net; i++)
		c[i] = nt.c[i];

	h = new double[size_net];
	e = new double[size_net];

	f = new double*[size_net];
	for (int i = 0; i < size_net; i++)
	{
		f[i] = new double[size_net];
		for (int j = 0; j < size_net; j++)
			f[i][j] = nt.f[i][j];
		h[i] = nt.h[i]; e[i] = nt.e[i];
	}
}

Network::~Network()
{
	delete[]c;
	delete[]h;
	delete[]e;
	for (int i = 0; i < size_net; i++)
		delete[]f[i];
	delete[]f;
}