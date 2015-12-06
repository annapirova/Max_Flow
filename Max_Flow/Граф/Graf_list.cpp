#include "Graf_list.h"

Graf_list::Graf_list(int xlen, int len): Size_xAdj(xlen), Size_Adj(len)
{
	if (xlen < 0) throw xlen;
	if (len < 0) throw len;
	//--------------------------------------------------//
	xAdj = new int[Size_xAdj];

	for (int i = 0; i < Size_xAdj; i++)
		xAdj[i] = i * Size_xAdj;
	//--------------------------------------------------//
	Adj = new int[Size_Adj];

	for (int i = 0; i < Size_Adj; i++)
		Adj[i] = 0;
	//--------------------------------------------------//

}
Graf_list::Graf_list(const Graf_list & G)
{
	//--------------------------------------------------//
	Size_xAdj = G.Size_xAdj;
	
	xAdj = new int[Size_xAdj];

	for (int i = 0; i < Size_xAdj; i++)
		xAdj[i] = G.xAdj[i];	
	//--------------------------------------------------//
	Size_Adj = G.Size_Adj;

	Adj = new int[Size_Adj];

	for (int i = 0; i < Size_Adj; i++)
		Adj[i] = G.Adj[i];
	//--------------------------------------------------//

}
Graf_list::Graf_list(const Graf_matrix & G)
{
	//--------------------------------------------------//
	Size_xAdj = G.Get_Size_M();

	xAdj = new int[Size_xAdj];

	int tmp_Size_Adj = 0;
	for (int i = 0; i < Size_xAdj; i++)
		for (int j = 0; j < Size_xAdj; j++)
			if (G[i][j] == 1) tmp_Size_Adj++;
	//--------------------------------------------------//
	Size_Adj = tmp_Size_Adj;

	Adj = new int[Size_Adj];

	int m =  0, k = 0;
	for (int i = 0; i < Size_xAdj; i++)
	{
		xAdj[i] = k;
		for (int j = 0; j < Size_xAdj; j++)
			if (G[i][j] == 1)
			{
				Adj[m] = j;
				m++;
				k++;
			}
	}
	//--------------------------------------------------//

}
Graf_list::operator Graf_matrix()
{
	Graf_matrix tmp(Size_xAdj);

	int j = 0, k = 1;
	for (int i = 0; i < Size_Adj; i++)
	{
		tmp[j][Adj[i]] = 1;
		if (i == xAdj[k]) 
		{
			j++; k++;
		}
	}
	return tmp;
}
int Graf_list::Graf_Size_Adj() const
{
	return Size_Adj;
}
int Graf_list::Graf_Size_xAdj() const
{
	return Size_xAdj;
}
int Graf_list::Graf_Get_Index(int i) const
{
	if (i < 0) throw i;
	return xAdj[i];
}
//----------------------------------------------------//
int Graf_list::operator[](int i) const
{
	return Adj[i];
}
Graf_list & Graf_list::operator=(const Graf_list & G)
{
	if (this == &G) return (*this);
	//--------------------------------------------------//
	if (Size_Adj != G.Size_Adj)
	{
		Size_Adj = G.Size_Adj;
		delete[]Adj;
		Adj = new int[Size_Adj];
	}
	for (int i = 0; i < Size_Adj; i++)
		Adj[i] = G.Adj[i];
	//--------------------------------------------------//
	if (Size_xAdj != G.Size_xAdj)
	{
		Size_xAdj = G.Size_xAdj;
		delete[]xAdj;
		xAdj = new int[Size_xAdj];
	}
	for (int i = 0; i < Size_xAdj; i++)
		xAdj[i] = G.xAdj[i];
	//--------------------------------------------------//
	return (*this);
}
//----------------------------------------------------//
ostream& operator<<(ostream& os, const Graf_list& G)
{
	int k = 0;
	for (int i = 0; i < G.Size_Adj; i++)
	{
		if (i == G.xAdj[k])
		{
			os << endl << k << " : ";
			k++;
		}
		os << G.Adj[i] << ", ";
	}
	return os;
}
istream& operator>>(istream& is, Graf_list& G)
{
	return is;
}
//----------------------------------------------------//
Graf_list::~Graf_list()
{
	delete[]Adj;
	delete[]xAdj;
}
