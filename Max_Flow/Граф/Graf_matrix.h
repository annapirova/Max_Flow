#ifndef _Graf_matrix_h_
#define _Graf_matrix_h_

#include "lib.h"
class Graf_matrix
{
	int size_m;
	int **graf_m;
public:
	Graf_matrix(int len = 3);
	Graf_matrix(const Graf_matrix &G);
	void Graf_Rand(int index);
	void Graf_Clear();
	int Get_Size_M() const;
//----------------------------------------------------//
	int* operator[](int i) const;
	Graf_matrix& operator=(const Graf_matrix& G);
//----------------------------------------------------//
	friend ostream& operator<<(ostream& os, const Graf_matrix& G);
	friend istream& operator>>(istream& is, Graf_matrix& G);
//----------------------------------------------------//
	~Graf_matrix();
};

#endif
