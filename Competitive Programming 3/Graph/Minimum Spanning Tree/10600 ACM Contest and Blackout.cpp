#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct union_find{
	int padre[1000];

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
typedef pair<int, ii> piii;//peso, origen y destino
#define mpiii(a, b, c) piii(a, ii(b, c))

vector<piii> grafo;//lista de incidencia
union_find uf;
vector<bool> flag;
vector<int> edges;

int kruskal(vector<piii> lista, int nodos, bool add){
	uf.iniciar(nodos + 1);
	int acum = 0, ejes = 0, n = nodos - 1;

	for (int i = 0; i < lista.size(); i++) {
        if(!flag[i]) continue;
		if(!uf.MismoGrupo(lista[i].second.first,
                      lista[i].second.second)) {
            if(add) edges.push_back(i);
			ejes++;
			uf.unir(lista[i].second.first, lista[i].second.second);
			acum += lista[i].first;
			if(ejes == n) return acum;
		}
	}
	return 1000000000;
}

int n, m;

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, x, y, z;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);
        grafo.clear(); edges.clear();
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            grafo.push_back(mpiii(z, x, y));
        }
        sort(grafo.begin(), grafo.end());
        flag.assign(m+1, 1);

        int mst = kruskal(grafo, n, true), aux = 1000000000;
        for(int i = 0; i < edges.size(); i++){
            //printf("----------------------------------------------------\n");
            //printf("quitamos arista: %d %d\n", grafo[edges[i]].second.first,grafo[edges[i]].second.second );
            flag[edges[i]] = false;
            aux = min(aux, kruskal(grafo, n, false));
            //printf("mejos hasta ahora: %d\n", aux);
            flag[edges[i]] = true;
        }

        printf("%d %d\n", mst, aux);
    }

	return 0;
}


