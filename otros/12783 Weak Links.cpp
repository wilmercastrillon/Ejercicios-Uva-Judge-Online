#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<ii> puentes;

int dfs(vector<vi> &lista, vi &dis, vector<bool> &vis, int nodo, int ant, int dep){
    dis[nodo] = dep;
    vis[nodo] = true;
    int atras = 1000000000;

    for(int i = 0; i < lista[nodo].size(); i++){
        if(lista[nodo][i] == ant) continue;

        if(!vis[lista[nodo][i]]){
            int q = dfs(lista, dis, vis, lista[nodo][i], nodo, dep + 1);
            atras = min(atras, q);
            if(q > dep){
                //cout << "solucion " << nodo << " a " << lista[nodo][i] << endl;
                puentes.push_back(ii(min(lista[nodo][i], nodo), max(lista[nodo][i], nodo)));
            }
        }else{
            atras = min(atras, dis[lista[nodo][i]]);
        }
    }
    return atras;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y;

    while(scanf("%d %d", &n, &m), n, m){
        vector<vi> grafo (n + 1);
        vi depth(n + 1, 1000000000);
        puentes.clear();

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }

        vector<bool> vis(n + 1, false);
        dfs(grafo, depth, vis, 0, -1, 0);
        sort(puentes.begin(), puentes.end());
        printf("%d", puentes.size());

        for(int i = 0; i < puentes.size(); i++) printf(" %d %d", puentes[i].first, puentes[i].second);
        printf("\n");
    }

	return 0;
}


