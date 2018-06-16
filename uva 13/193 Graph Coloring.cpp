#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi sol;
bool vis[110], negro[110];
int n, res;

void backtraking(int pos, vvi lista){
    if(pos == n){
        int con = 0;
        for(int i = 0; i < n; i++)
            if(negro[i]) con++;

        if(con > res){
            res = con;
            sol.clear();
            for(int i = 0; i < n; i++)
                if(negro[i]) sol.push_back(i + 1);
        }
        return;
    }

    bool vecinoN = false;
    for(int i = 0; i < lista[pos].size() && !vecinoN; i++)
        vecinoN = negro[lista[pos][i]];

    if(!vecinoN){
        negro[pos] = vis[pos] = true;
        backtraking(pos + 1, lista);
        vis[pos] = false;
    }
    negro[pos] = false;
    vis[pos] = true;
    backtraking(pos + 1, lista);
    vis[pos] = false;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    //freopen("salida.txt", "w", stdout);
    int casos, k, x, y;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d %d", &n, &k);
        vvi grafo(n);
        res = 0;

        for(int i = 0; i < k; i++){
            scanf("%d %d", &x, &y);
            x--; y--;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }

        memset(negro, false, sizeof(negro));
        memset(vis, false, sizeof(vis));
        backtraking(0, grafo);

        printf("%d\n%d", res, sol[0]);
        for(int i = 1; i < sol.size(); i++) printf(" %d", sol[i]);

        printf("\n");
    }

    return 0;
}


