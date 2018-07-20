#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include <map>

using namespace std;
typedef vector<int> vi;

map<string, int> mapa;
map<int, string> mapaRev;

int n, m;
vector<vi> lista, comp;
vi dfs_low, dfs_num, s; vector<bool> vis;
int dfsCont;

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
        vi vec;
        while(true){
            int v = s.back(); s.pop_back();
            vec.push_back(v);
            vis[v] = false;
            if(v == u) break;
        }
        comp.push_back(vec);
    }
}

void solve(){
    dfs_num.assign(n+1,-1); dfs_low.assign(n+1,0);
    vis.assign(n+1, false); dfsCont = 0;
    for(int i = 1; i <= n; i++)
        if(dfs_num[i] == -1) tarjan(i);

    for(int i = 0; i < comp.size(); i++){
        printf("%s", mapaRev[comp[i][0]].c_str());
        for(int j = 1; j < comp[i].size(); j++){
            printf(", %s", mapaRev[comp[i][j]].c_str());
        }
        printf("\n");
    }
}

int main() {
    int x, y, caso = 0;
    char cad[50], cad2[50];
    string s1, s2;
    scanf("%d %d", &n, &m);

    while(true){
        caso++;
        lista.assign(n+1, vi(0));
        comp.clear(); mapa.clear(); mapaRev.clear();
        int con = 0;

        for(int i = 0; i < m; i++){
            scanf("%s %s", &cad, &cad2);
            s1 = (string) cad; s2 = (string) cad2;
            if(mapa[s1] == 0){
                mapa[s1] = ++con;
                mapaRev[con] = s1;
            }
            if(mapa[s2] == 0){
                mapa[s2] = ++con;
                mapaRev[con] = s2;
            }

            lista[mapa[s1]].push_back(mapa[s2]);
        }

        printf("Calling circles for data set %d:\n", caso);
        solve();
        scanf("%d %d", &n, &m);
        if(!n) break;
        printf("\n");
    }

	return 0;
}


