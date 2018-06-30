#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
typedef vector<int> vi;

int nodos;
vector<vi> grafo(201);
int vis[201];

bool Bipartito(){
	
	memset(vis, 0, sizeof(vis));
	queue<int> cola;
	cola.push(0);
	vis[0] = 1;
	int aux;
	
	while(cola.size())
	{
		aux = cola.front();
		cola.pop();
		
		for (int i = 0; i < grafo[aux].size(); i++)
		{
			if(vis[grafo[aux][i]] == vis[aux]) return false;
			
			if (!vis[grafo[aux][i]])
			{
				cola.push(grafo[aux][i]);
				if(vis[aux] == 2)
					vis[grafo[aux][i]] = 1;
				else 
					vis[grafo[aux][i]] = 2;
			}
			
		}
		
	}
	return true;
}

int main(){
	
	int n, x, y;
	
	while (scanf("%d", &nodos), nodos)
	{
		for (int i = 0; i < nodos; i++)
		{
			grafo[i].clear();
		}
		
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}
		
		if (Bipartito())
		{
			printf("BICOLORABLE.\n");
		}else
		{
			printf("NOT BICOLORABLE.\n");
		}
	}
	
	return 0;
}
