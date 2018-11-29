#include <stdio.h>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;//(peso, nodo padre, nodo hijo)
typedef vector<int> vi;
#define mpiii(a, b, c) iii(a, ii(b, c))
#define inf 1000000000

vector<iii> grafo; //lista de incidencia

bool BellmanFord(vector<iii> &lista, int inicio, int nodos, vi &dis){
    dis.assign(nodos+1, inf);
	dis[inicio] = 0;
	int aux;

	for (int i = 0; i < nodos; i++)
    for (int j = 0; j < lista.size(); j++) {
        aux = dis[lista[j].second.first] + lista[j].first;
        if (dis[lista[j].second.second] > aux){
            dis[lista[j].second.second] = aux;
        }
    }

    for(int j = 0; j < lista.size(); j++){
			aux = dis[lista[j].second.first] + lista[j].first;
			if(dis[lista[j].second.second] > aux)
                return true;//existe ciclo!!!
		}
	return false;
}

int main(){//NO TERMINADO
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int n, m, q, w, caso = 1;

    while(scanf("%d", &n) != EOF){
        vi v(n+1);
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i+1]);
        }

        int x, y, z;
        grafo.clear();
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            z = v[y] - v[x];
            grafo.push_back(mpiii(z, x, y));
            //printf("%d a %d con peso %d\n", x, y, z);
        }

        int acum;
        vi dist;
        bool cicloNeg = BellmanFord(grafo, 1, n, dist);
        /*for(int j = 1; j <= n; j++){
            printf("hasta %d -> %d\n", j, dist[j]);
        }*/

        scanf("%d", &q);
        printf("Set #%d\n", caso++);
        for(int i = 0; i < q; i++){
            scanf("%d", &w);
            acum = dist[w];
            if(acum < 3 || cicloNeg) printf("?\n");
            else printf("%d\n", acum);
        }
    }

	return 0;
}



