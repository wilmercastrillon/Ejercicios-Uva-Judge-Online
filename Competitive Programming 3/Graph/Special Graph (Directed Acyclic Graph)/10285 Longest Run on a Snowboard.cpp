#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vvii grafo;
vi res;
bool vis[10010];
int tab[110][110];
int mf[] = {-1, 0, 1, 0}, mc[] = {0, 1, 0, -1};

void dfs(vvii &lista, int nodo){
    vis[nodo] = 1;
    for(int i = 0; i < lista[nodo].size(); i++){
        if(!vis[lista[nodo][i].second]){
            dfs(lista, lista[nodo][i].second);
        }
    }
    res.push_back(nodo);
}

void topological_sort(vvii &lis, int tam){
    memset(vis, false, sizeof(vis));
    res.clear();
    for(int i = 0; i < tam; i++){
        if(!vis[i]) dfs(lis, i);
    }
    reverse(res.begin(), res.end());
}

vi rutaMinimaDAG(vvii &lista, int pos, int tam){
    ii par;
    vi dist(tam, inf);
    dist[res[pos]] = 0;
    for(int i = pos; i < tam; i++){
        //printf("para nodo %d: \n", i);
        for(int j = 0; j < grafo[res[i]].size(); j++){
            par = grafo[res[i]][j];
            dist[par.second] = min(dist[par.second], dist[res[i]]+par.first);
            //printf("   mejoramos ir a %d con peso %d\n", par.second, dist[par.second]);
        }
    }
    return dist;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, f, c;
    int x, y, z;
    char cad[100];
    scanf("%d", &t);

    while(t--){
        //printf("lectura\n");
        scanf("%s %d %d", &cad, &f, &c);
        grafo.assign(f*c + 5, vii(0));

        for(int i = 0; i < f; i++){
            for(int j = 0; j < c; j++){
                scanf("%d", &tab[i][j]);
            }
        }
        //printf("fin lectura\n");

        int auxf, auxc;
        for(int i = 0; i < f; i++){
            for(int j = 0; j < c; j++){
                for(int k = 0; k < 4; k++){
                    auxf = i + mf[k];
                    auxc = j + mc[k];
                    if(auxf<0 || auxf>=f || auxc<0 || auxc>=c){
                        //printf("no sirvio\n");
                        continue;
                    }

                    //printf("# i %d, j %d, auxf %d, auxc %d\n", i, j, auxf, auxc);
                    if(tab[i][j] > tab[auxf][auxc]){
                        grafo[i*c + j].push_back(ii(1, auxf*c + auxc));
                        //printf("conexion de %d a %d con peso %d\n", i*c+j, auxf*c+auxc, 1);
                    }
                }
            }
        }
        //printf("fin armar grafo\n");
        topological_sort(grafo, f*c);

        int l = f*c, may = 0;
        vi dist(l, 0);

        for(int i : res){
            may = max(may, dist[i]+1);
            for(ii par : grafo[i]){
                dist[par.second] = max(dist[par.second], dist[i]+par.first);
            }
        }
        printf("%s: %d\n", cad, may);
    }

    return 0;
}



