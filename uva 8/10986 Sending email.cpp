#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

#define inf 1000000000
#define mpii(a, b) pair<int, int>(a, b)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

vector<vii> grafo(20010);

vi dijkstra(vector<vii> &lista, int nodo, int tam){
	vector<bool> vis(tam + 1, false);
	vi dis(tam + 1, inf);
	priority_queue<pii> cola;
	
	cola.push(mpii(0, nodo));
	dis[nodo] = 0;
	pii par;
	int aux, peso;
	
	while(cola.size())
	{
		par = cola.top();
		cola.pop();
		nodo = par.second;
		peso = -par.first;
		
		if(peso > dis[nodo]) continue;
		dis[nodo] = peso;
		
		for (int j = 0; j < lista[nodo].size(); j++)
		{
			aux = dis[nodo] + lista[nodo][j].second;
			if(dis[lista[nodo][j].first] > aux){
				cola.push(mpii(-aux, lista[nodo][j].first));
			}
		}
	}
	return dis;
}

int main(){
	//freopen("entrada.txt", "r", stdin);
	//freopen("salida.txt", "w", stdout);
	
	int casos, n, m, s, t, x, y, z;
	scanf("%d", &casos);
	
	for (int i = 1; i <= casos; i++)
	{
		scanf("%d %d %d %d", &n, &m, &s, &t);
		for (int j = 0; j < n; j++) grafo[j].clear();
		
		for (int j = 0; j < m; j++)
		{
			scanf("%d %d %d", &x, &y, &z);
			grafo[x].push_back(mpii(y, z));
			grafo[y].push_back(mpii(x, z));
		}
		
		vi dist = dijkstra(grafo, s, n);
		
		printf("Case #%d: ", i);
		if(dist[t] == inf)
			printf("unreachable\n");
		else
			printf("%d\n", dist[t]);
	}
	
	return 0;
}
