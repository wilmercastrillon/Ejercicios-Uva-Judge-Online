#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

struct union_find{
	int padre[110];

	void iniciar(int n){
		for (int i = 0; i < n; i++) padre[i] = i;
	}

	int raiz(int x){
		if(padre[x] == x) return x;
		return raiz(padre[x]);
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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;//peso, origen y destino
#define mpiii(a, b, c) iii(a, ii(b, c))
typedef vector<ii> vii;

vector<vii> grafo;//lista de adyacencia
vector<iii> lista;//lista de incidencia
union_find uf;

int kruskal(vector<iii> lista, int nodos){
	sort(lista.begin(), lista.end());
	uf.iniciar(nodos + 1);
	int acum = 0, ejes = 0, n = nodos - 1;

	for (int i = 0; i < lista.size(); i++) {
		if (!uf.MismoGrupo(lista[i].second.first,
                      lista[i].second.second)) {
			ejes++;
			uf.unir(lista[i].second.first, lista[i].second.second);
			acum += lista[i].first;
			//printf("conexion de %d a %d comn valor %d\n", lista[i].second.first, lista[i].second.second, lista[i].first);
			grafo[lista[i].second.first].push_back(ii(lista[i].second.second, lista[i].first));
			grafo[lista[i].second.second].push_back(ii(lista[i].second.first, lista[i].first));
			if(ejes == n) return acum;
		}
	}
	return -1;
}

int n, m, q, dest, res;
bool vis[110], sig;

void dfs(int nodo, int may){
    //printf("visitamos %d  con mayor de %d\n", nodo, may);
    vis[nodo] = true;

    for(int i = 0; i < grafo[nodo].size() && sig; i++){
        if(!vis[grafo[nodo][i].first]){
            if(dest != grafo[nodo][i].first)
                dfs(grafo[nodo][i].first, max(may, grafo[nodo][i].second));
            else{
                //printf("llegamos\n");
                res = max(may, grafo[nodo][i].second);
                sig = false;
                return;
            }
        }
    }
}


int main(){
    int x, y, z, caso = 1;
    scanf("%d %d %d", &n, &m, &q);

    while(1){
        grafo.assign(n+1, vii(0));
        lista.clear();
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            lista.push_back(mpiii(z, x, y));
        }
        kruskal(lista, n);

        printf("Case #%d\n", caso++);
        for(int i = 0; i < q; i++){
            memset(vis, false, sizeof(vis));
            scanf("%d %d", &x, &dest);
            res = -1; sig = true; dfs(x, 0);
            if(res != -1) printf("%d\n", res);
            else printf("no path\n");
        }

        scanf("%d %d %d", &n, &m, &q);
        if(!n && !m && !q) break;
        printf("\n");
    }

	return 0;
}


