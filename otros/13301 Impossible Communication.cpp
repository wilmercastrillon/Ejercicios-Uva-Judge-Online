#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi grafo;
int n, m;
vi dfs_low, dfs_num, s;
vector<bool> vis;
int dfsCont, con;

void dfs(int u){
    dfs_low[u] = dfs_num[u] = dfsCont++;
    s.push_back(u);  vis[u] = true;

    for(int i = 0; i < grafo[u].size(); i++){
        int aux = grafo[u][i];
        if(dfs_num[aux] == -1) dfs(aux);
        if(vis[aux])
            dfs_low[u] = min(dfs_low[u], dfs_low[aux]);
    }

    if(dfs_low[u] == dfs_num[u]){
        //printf("comp:\n");
        con++;
        while(true){
            int v = s.back(); s.pop_back();
            //printf(" %d\n", v);
            vis[v] = false;
            if(v == u) break;
        }
        //printf("\n");
    }
}

void tarjan(){
    dfs_num.assign(n+1,-1);
    dfs_low.assign(n+1,0);
    vis.assign(n+1, false);  dfsCont = 0;
    for(int i = 1; i <= n; i++)
        if(dfs_num[i] == -1) dfs(i);
}

int main(){
    int c, x, y;

    while(scanf("%d %d", &n, &m) != EOF){
        grafo.assign(n+1,vi(0));

        forr(i, m){
            scanf("%d", &c);
            if(c == 1){
                scanf("%d %d", &x, &y);
                grafo[x].push_back(y);
            }else{
                scanf("%d", &x);
                forab(j, 1, c){
                    scanf("%d", &y);
                    grafo[x].push_back(y);
                    grafo[y].push_back(x);
                }
            }
        }

        con = 0;
        tarjan();
        if(con == 1) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}


