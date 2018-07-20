#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

map<int, int> mapa;
vector<ii> edge;

int n, m;
vector<vi> lista;
vi dfs_low, dfs_num, s; vector<bool> vis;
int dfsCont;

struct union_find{
	vi padre, rango;

	void iniciar(int n){
	    padre.clear(); rango.clear();
		for (int i = 0; i < n; i++) {
			padre.push_back(i);
			rango.push_back(0);
		}
	}

    int raiz(int x){
        if(x == padre[x] ) return x;
        else return padre[x] = raiz(padre[x]);
    }

	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		if(x == y) return;

		if(rango[x] > rango[y]){
			padre[y] = x;
			return;
		}

		padre[x] = y;
		if(rango[y] == rango[x]) rango[y]++;
	}
};

union_find comp;

void tarjan(int u){
    dfs_low[u] = dfs_num[u] = dfsCont++;
    s.push_back(u);
    vis[u] = true;

    for(int i = 0; i < lista[u].size(); i++){
        int aux = lista[u][i];
        if(dfs_num[aux] == -1) tarjan(aux);
        if(vis[aux])
            dfs_low[u] = min(dfs_low[u], dfs_low[aux]);
    }

    if(dfs_low[u] == dfs_num[u]){
        int q;
        if(s.size()) q = s.back();
        while(true){
            int v = s.back(); s.pop_back();
            comp.unir(q, v);
            vis[v] = false;
            if(v == u) break;
        }
    }
}

void solve(){
    comp.iniciar(n+1);
    //dfs_num.assign(n+1,-1); dfs_low.assign(n+1,0);
    //vis.assign(n+1, false);
    dfsCont = 0;

    dfs_num.clear(); dfs_low.clear(); vis.clear();
    for(int i = 0; i <= n; i++){
        dfs_num.push_back(-1); dfs_low.push_back(0);
        vis.push_back(false);
    }

    for(int i = 1; i <= n; i++)
        if(dfs_num[i] == -1) tarjan(i);

    mapa.clear(); int con = 1, q, w, can = 0;
    vi ent(1);
    for(int i = 0; i < edge.size(); i++){
        q = edge[i].first; w = edge[i].second;
        if(mapa[comp.raiz(q)] == 0)
            mapa[comp.raiz(q)] = con++, ent.push_back(0);
        if(mapa[comp.raiz(w)] == 0)
            mapa[comp.raiz(w)] = con++, ent.push_back(0);

        if(comp.raiz(q) != comp.raiz(w)){
            ent[mapa[comp.raiz(w)]]++;
            if(ent[mapa[comp.raiz(w)]] == 1) can++;
            //printf("componente %d tiene una arista entrante\n", mapa[comp.raiz(w)]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(mapa[comp.raiz(i)] == 0) con++;
    }
    printf("%d\n", (con-1) - can);
}

int main() {
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int x, y, casos;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d %d", &n, &m);
        lista.assign(n+1, vi(0));
        edge.clear();

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            lista[x].push_back(y);
            edge.push_back(ii(x, y));
        }

        solve();
    }

	return 0;
}


