#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int n, m, dfsCont, root, dfsRoot;
vvi lista;
vi dfs_low, dfs_num, padre;
vector<int> puntos;

void dfs(int nodo){//dfs modificado
    dfs_low[nodo] = dfs_num[nodo] = dfsCont++;
    int aux;

    for(int i = 0; i < lista[nodo].size(); i++){
        aux = lista[nodo][i];

        if(dfs_num[aux] == -1){
            padre[aux] = nodo;
            if(nodo == dfsRoot){//raiz
                root++;
            }
            dfs(aux);

            if(dfs_low[aux] >= dfs_num[nodo]) puntos[nodo]++;
            dfs_low[nodo] = min(dfs_low[nodo], dfs_low[aux]);
        }else if(padre[aux] != nodo)
            dfs_low[nodo] = min(dfs_low[nodo], dfs_num[aux]);
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int q, w;

    while(scanf("%d %d", &n, &m), n, m){
        lista.assign(n+1, vi(0)); dfs_low.assign(n+1, 0);
        padre.assign(n+1, 0); dfs_num.assign(n+1, -1);
        dfsCont = 0; puntos.assign(n+1, 0);

        while(scanf("%d %d", &q, &w), q != -1){
            lista[q].push_back(w);
            lista[w].push_back(q);
        }

        int con = 0, cc = 0;
        vector<ii> res;
        for(int i = 0; i < n; i++){
            if(dfs_num[i] == -1){
                dfsRoot = i;
                root = 0;
                dfs(dfsRoot);
                cc++;
                puntos[i] = root - 1;
            }
        }

        for(int i = 0; i < n; i++)
            res.push_back(ii(-(cc + puntos[i]), i));

        sort(res.begin(), res.end());
        for(int i = 0; i < m; i++){
            printf("%d %d\n", res[i].second, -res[i].first);
        }
        printf("\n");
    }

    return 0;
}


