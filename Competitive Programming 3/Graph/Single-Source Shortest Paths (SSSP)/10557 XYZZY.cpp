#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;//(peso, nodo padre, nodo hijo)
typedef vector<int> vi;
typedef vector<vi> vvi;
#define mpiii(a, b, c) iii(a, ii(b, c))
#define inf 1000000000
int peso[1000000], nodoCiclo;

vector<iii> grafo; //lista de incidencia

bool BellmanFord(vector<iii> &lista, int nodos, int inicio, vector<int> &dis){
    dis.assign(nodos+1, inf);
	dis[inicio] = 0;
	int aux;

	for (int i = 0; i < nodos; i++)
		for (int j = 0; j < lista.size(); j++) {
			aux = dis[lista[j].second.first] + lista[j].first;
			if(aux >= 100) continue;
			if (dis[lista[j].second.second] > aux){
				dis[lista[j].second.second] = aux;
				//printf("mejora ir de %d a %d : %d\n", lista[j].second.first, lista[j].second.second, aux);
			}
		}

    for(int j = 0; j < lista.size(); j++){
        aux = dis[lista[j].second.first] + lista[j].first;
        if(aux >= 100) continue;
        if(dis[lista[j].second.second] > aux){
            nodoCiclo = lista[j].second.second;
            return false;//existe ciclo!!!
        }
    }
	return true;
}

vvi listaAdy;
vector<bool> vis;
void dfs(int n){
    vis[n] = true;
    for(int i = 0; i < listaAdy[n].size(); i++){
        if(!vis[listaAdy[n][i]]) dfs(listaAdy[n][i]);
    }
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int n, m, y, z, aux;

    while(scanf("%d", &n), n != -1){

        grafo.clear();
        listaAdy.assign(n+1, vi(0));
        vis.assign(n+1, false);
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &z, &aux);
            peso[i] = z;

            for(int j = 0; j < aux; j++){
                scanf("%d", &y);
                grafo.push_back(mpiii(0, i, y));
            }
        }
        //peso[1] = peso[n] = 0;
        for(int i = 0; i < grafo.size(); i++){
            grafo[i].first = -peso[grafo[i].second.second];
            listaAdy[grafo[i].second.first].push_back(grafo[i].second.second);
            //printf("vamos de %d a %d con peso %d\n", grafo[i].second.first, grafo[i].second.second, grafo[i].first);
        }

        vi vec;
        bool ciclo = !BellmanFord(grafo, n, 1, vec);
        /*for(int i = 1; i <= n; i++){
            printf("%d -> %d\n", i, vec[i]);
        }*/
        if(ciclo){
            //printf("Existe ciclo positivo\n");
            //printf("ciclo en %d\n", nodoCiclo);
            dfs(nodoCiclo);//destino alcanzable desde el ciclo
            if(vis[n]){
                //printf("Es %d alcanzable desde el nodo %d\n", n, 1);
                printf("winnable\n");
            }else printf("hopeless\n");
        }else{
            if(vec[n] != inf) printf("winnable\n");//accesible normalmente
            else printf("hopeless\n");
        }

    }

	return 0;
}


