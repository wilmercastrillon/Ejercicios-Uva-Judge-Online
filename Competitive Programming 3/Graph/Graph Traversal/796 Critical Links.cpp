#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int n, dfsCont, con;
vvi lista;
vi dfs_low, dfs_num, padre;
vector<ii> puentes;

void dfs(int nodo){
    dfs_low[nodo] = dfs_num[nodo] = dfsCont++;
    int aux;

    for(int i = 0; i < lista[nodo].size(); i++){
        aux = lista[nodo][i];

        if(dfs_num[aux] == -1){
            padre[aux] = nodo;
            dfs(aux);

            if(dfs_low[aux] > dfs_num[nodo])
                puentes.push_back(ii(min(aux, nodo), max(aux, nodo)));
            dfs_low[nodo] = min(dfs_low[nodo], dfs_low[aux]);
        }else if(padre[nodo] != aux)
            dfs_low[nodo] = min(dfs_low[nodo], dfs_num[aux]);
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int q, m, w;

    while(scanf("%d", &n) != EOF){
        lista.assign(n+1, vi(0)); dfs_low.assign(n+1, 0);
        padre.assign(n+1, 0); dfs_num.assign(n+1, -1);
        dfsCont = 0;

        for(int i = 0; i < n; i++){
            scanf("%d (%d)", &q, &m);
            for(int j = 0; j < m; j++){
                scanf("%d", &w);
                lista[q].push_back(w);
                lista[w].push_back(q);
                //printf("conexion de %d a %d\n", q, w);
            }
        }

        puentes.clear();
        for(int i = 0; i < n; i++)
            if(dfs_num[i] == -1) dfs(i);

        sort(puentes.begin(), puentes.end());
        printf("%d critical links\n", puentes.size());
        for(int i = 0; i < puentes.size(); i++)
            printf("%d - %d\n", puentes[i].first, puentes[i].second);
        printf("\n");
    }

    return 0;
}


