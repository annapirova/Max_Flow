#ifndef _Graf_list_h_
#define _Graf_list_h_

#include "lib.h"
#include "Graf_matrix.h"
#define MaxSize_Graf 3

class Graf_list
{
private:
	int *xAdj;
	int *Adj;
	int Size_xAdj;	
	int Size_Adj;
	
public:
	Graf_list(int xlen = MaxSize_Graf, int len = MaxSize_Graf * MaxSize_Graf);
	Graf_list(const Graf_list &G);
	Graf_list(const Graf_matrix &G);
	operator Graf_matrix();
	int Graf_Size_Adj() const;
	int Graf_Size_xAdj() const;
	int Graf_Get_Index(int i) const;
	//----------------------------------------------------//
	int operator[](int i) const;
	Graf_list& operator=(const Graf_list &G);
	//----------------------------------------------------//
	friend ostream& operator<<(ostream& os, const Graf_list& G);
	friend istream& operator>>(istream& is, Graf_list& G);
	//----------------------------------------------------//
	~Graf_list();
};

#endif
