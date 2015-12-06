#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "����\lib.h"
#include "����\Graf_list.h"
#include "TQueue.h"

class Network
{
	Graf_list net;
	double *c;
	double **f;
	TQueue<int> list;
	double *h;
	double *e;

public:
	Network(int size = 5);
	~Network();
};

#endif

