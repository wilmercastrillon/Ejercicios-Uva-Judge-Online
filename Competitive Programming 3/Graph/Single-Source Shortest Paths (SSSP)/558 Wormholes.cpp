#include <stdio.h>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;//(peso, nodo padre, nodo hijo)
typedef vector<int> vi;
#define mpiii(a, b, c) iii(a, ii(b, c))
#define inf 1000000000

vector<iii> grafo; //lista de incidencia

bool BellmanFord(vector<iii> &lista, int inicio, int nodos){
    vi dis(nodos, inf);
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
            return false;//existe ciclo!!!
    }
	return true;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int t, n, m;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);
        int x, y, z;
        grafo.clear();

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            grafo.push_back(mpiii(z, x, y));
        }

        if(!BellmanFord(grafo, 0, n)) printf("possible\n");
        else printf("not possible\n");
    }

	return 0;
}


