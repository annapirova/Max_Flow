#include "Graf_matrix.h"

Graf_matrix::Graf_matrix(int len): size_m(len)
{
	if (len < 0) throw len;
	//--------------------------------------------------//
	graf_m = new int*[size_m];

	for (int i = 0; i < size_m; i++)
		graf_m[i] = new int[size_m];
	//--------------------------------------------------//
	for (int i = 0; i < size_m; i++)
		for (int j = 0; j < size_m; j++)
			graf_m[i][j] = 0;
	//--------------------------------------------------//
}
Graf_matrix::Graf_matrix(const Graf_matrix & G)
{
	size_m = G.size_m;
	//--------------------------------------------------//
	graf_m = new int*[size_m];
	for (int i = 0; i < size_m; i++)
		graf_m[i] = new int[size_m];
	//--------------------------------------------------//
	for (int i = 0; i < size_m; i++)
		for (int j = 0; j < size_m; j++)
			graf_m[i][j] = G.graf_m[i][j];
	//--------------------------------------------------//
}
void Graf_matrix::Graf_Rand(int index)
{
	if ((index == 0) && (index == 1)) throw index;
	//--------------------------------------------------//
	// Не ориентированный граф //
	//--------------------------------------------------//
	if (index == 0)
		for (int i = 0; i < size_m; i++)
		{
			graf_m[i][i] = 0;
			for (int j = i + 1; j < size_m; j++)
			{
				graf_m[i][j] = rand() % 2;
				graf_m[j][i] = graf_m[i][j];
			}
		}
	//--------------------------------------------------//
	// Ориентированный граф //
	//--------------------------------------------------//
	if (index == 1)
		for (int i = 0; i < size_m; i++)
		{
			graf_m[i][i] = 0;
			for (int j = i + 1; j < size_m; j++)
			{
				graf_m[i][j] = rand() % 2;
				if (graf_m[i][j] == 0) graf_m[j][i] = 1;
				else graf_m[j][i] = 0;
			}
		}
	//--------------------------------------------------//
}
void Graf_matrix::Graf_Clear()
{
	for (int i = 0; i < size_m; i++)
		for (int j = 0; j < size_m; j++)
			graf_m[i][j] = 0;
}
int Graf_matrix::Get_Size_M() const
{
	return size_m;
}
//----------------------------------------------------//
int* Graf_matrix::operator[](int i) const
{
	if (i < 0) throw i;
	return graf_m[i];
}
Graf_matrix & Graf_matrix::operator=(const Graf_matrix & G)
{
	if (this == &G) return (*this);
	//--------------------------------------------------//
	if (size_m != G.size_m)
	{
		size_m = G.size_m;

		for (int i = 0; i < size_m; i++)
			delete[]graf_m[i];
		delete[]graf_m;

		graf_m = new int*[size_m];
		for (int i = 0; i < size_m; i++)
			graf_m[i] = new int[size_m];
	}
	//--------------------------------------------------//
	for (int i = 0; i < size_m; i++)
		for (int j = 0; j < size_m; j++)
			graf_m[i][j] = G.graf_m[i][j];
	return(*this);
	//--------------------------------------------------//
}
//----------------------------------------------------//
ostream& operator<<(ostream& os, const Graf_matrix& G)
{
	os << "    ";
	for (int i = 0; i < G.size_m; i++)
		os << i << ' ';
	os << endl;

	os << "    ";
	for (int i = 0; i < G.size_m - 1; i++)
		os << "--";
	os << '-' << endl;

	for (int i = 0; i < G.size_m; i++)
	{
		os << i << " | ";
		for (int j = 0; j < G.size_m; j++)
			os << G.graf_m[i][j] << ' ';
		os << endl;
	}
	return os;
}
istream& operator>>(istream& is, Graf_matrix& G)
{
	int size;
	is >> size;
	Graf_matrix tmp(size);

	for (int i = 0; i < tmp.size_m; i++)
		for (int j = 0; j < tmp.size_m; j++)
			is >> tmp.graf_m[i][j];
	G = tmp;

	return is;
}
//----------------------------------------------------//
Graf_matrix::~Graf_matrix()
{
	for (int i = 0; i < size_m; i++)
		delete[]graf_m[i];
	delete[]graf_m;
}
