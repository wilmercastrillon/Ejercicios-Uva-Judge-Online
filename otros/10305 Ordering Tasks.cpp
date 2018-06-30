#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> grafo(110);
vi res;
bool vis[110];

void dfs(vector<vi> &lista, int nodo){
    vis[nodo] = 1;
    for(int i = 0; i < lista[nodo].size(); i++){
        if(!vis[lista[nodo][i]]){
            dfs(lista, lista[nodo][i]);
        }
    }
    res.push_back(nodo);
}

int main(){
    int n, m, x, y;

    while(scanf("%d %d", &n, &m), n || m){
        for(int i = 0; i < n; i++) grafo[i].clear();

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            grafo[x].push_back(y);
        }

        memset(vis, false, sizeof(vis));
        res.clear();

        for(int i = 1; i <= n; i++){
            if(!vis[i]) dfs(grafo, i);
        }
        for(int i = res.size() - 1; i > 0; i--) printf("%d ", res[i]);
        printf("%d\n", res[0]);
    }
}
