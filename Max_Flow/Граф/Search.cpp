#include "Search.h"

Graf_matrix BFS(const Graf_list &G)
{
	Graf_matrix dist(G.Graf_Size_xAdj());

	queue<int> Q;
	int *color = new int[G.Graf_Size_xAdj()]; //создание массива пройденных вершин

	for (int i = 0; i < G.Graf_Size_xAdj(); i++)
	{

		Q.push(i); // добавление вершины отсчета

		for (int l = 0; l < G.Graf_Size_xAdj(); l++) color[l] = 0; // все вершины стали новые

		while (!Q.empty())
		{
			int x = Q.front(); Q.pop(); 
			color[x] = 1;
			int k = G.Graf_Get_Index(x);
			while((k < G.Graf_Get_Index(x+1)) || (k < G.Graf_Size_Adj()))
			{
				int y = G[k];
				if (color[y] == 0) 
				{
					Q.push(y);
					color[y] = 1;
					dist[i][y] = dist[i][x] + 1;
				}
				k++;
			}
		}
	}
	delete[]color;
	return dist;
}

void DFS_visit(int u, int *color, int *pi, int &time, int *f, int *d, const Graf_list &G)
{
	color[u] = 1; time++; d[u] = time;
	int k = G.Graf_Get_Index(u);
	while ((k < G.Graf_Get_Index(u + 1)) || (k < G.Graf_Size_Adj()))
	{
		int v = G[k];

		if (color[v] == 0)
		{
			pi[v] = u;
			DFS_visit(v, color, pi, time, f, d, G);
		}
		k++;
	}
	color[u] = 2;
	f[u] = time;
}//*/

void DFS(int *f, int *d, const Graf_list &G)
{
	

	int *color = new int[G.Graf_Size_xAdj()];
	int *pi = new int[G.Graf_Size_xAdj()];

		for (int l = 0; l < G.Graf_Size_xAdj(); l++)
		{
			color[l] = 0; pi[l] = 0;
		}
		int time = 0;
		for (int j = 0; j < G.Graf_Size_xAdj(); j++)
			if (color[j] == 0)
			{
				DFS_visit(j, color, pi, time, f, d, G);
			}
			

	delete[]color;
	delete[]pi;

}//*/

