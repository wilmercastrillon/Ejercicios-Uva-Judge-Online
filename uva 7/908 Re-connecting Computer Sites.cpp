#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, pair<int, int>> piii;

#define mpii(a, b) pair<int, int>(a, b)
#define mpiii(a, b, c) piii(a, mpii(b, c))

struct union_find{
	int padre[1000010];
	int tam = 0;
	
	void iniciar(int x){
		for (int i = 0; i < x; i++) padre[i] = i;
		tam = x;
	}
	
	int raiz(int x){
		if(padre[x] == x){
			return x;
		}else{
			return padre[x] = raiz(padre[x]);
		}
	}
	
	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		
		padre[x] = y;
	}
	
	bool MismoGrupo(int x, int y){
		return raiz(x) == raiz(y);
	}
};

vector<piii> grafo1, grafo2;
int n, k, m, x, y, z;
union_find arbol;

int kruskal(vector<piii> lista, int nodos, union_find &uf){
	sort(lista.begin(), lista.end());
	uf.iniciar(nodos);
	int acum = 0, ejes = 0, n = nodos - 1;
	
	for (int i = 0; i < lista.size(); i++)
	{
		if (!uf.MismoGrupo(lista[i].second.first, lista[i].second.second))
		{
			ejes++;
			uf.unir(lista[i].second.first, lista[i].second.second);
			acum += lista[i].first;
			if(ejes == n) return acum;
		}
		
	}
	
	return acum;
}

int	main(){
	//freopen("entrada.txt", "r", stdin);
	//freopen("salida.txt", "w", stdout);
	
	scanf("%d", &n);
	do
	{
		grafo1.clear();
		grafo2.clear();
		
		for (int i = 1; i < n; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			piii par = mpiii(z, x - 1, y - 1);
			grafo2.push_back(par);
		}
		
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			piii par = mpiii(z, x - 1, y - 1);
			grafo2.push_back(par);
		}
		
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			piii par = mpiii(z, x - 1, y - 1);
			grafo1.push_back(par);
		}
		
		printf("%d\n", kruskal(grafo1, n, arbol));
		printf("%d\n", kruskal(grafo2, n, arbol));
		
		if(scanf("%d", &n) != EOF)
			printf("\n");
		else
			break;
	}while(1);
	
	
	return 0;
}
