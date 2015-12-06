#ifndef _Search_h_
#define _Search_h_

#include "Graf_matrix.h"
#include "Graf_list.h"

Graf_matrix BFS(const Graf_list &G);
void DFS(int *f, int *d, const Graf_list &G);

#endif
