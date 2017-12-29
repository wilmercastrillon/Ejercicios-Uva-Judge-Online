#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<bool> nodos;

void dfs(int n, vector<bool> &vis, vector<vi> &grafo){
    vis[n] = true;

    for(int i = 0; i < grafo[n].size(); i++)
        if(!vis[grafo[n][i]]) dfs(grafo[n][i], vis, grafo);
}

int main(){
    int casos;
    char cad[100];
    scanf("%d", &casos);

    while(casos--){
        nodos.assign(26, false);
        vector<vi> grafo(26);

        while(scanf("%s", &cad), cad[0] != '*'){
            grafo[cad[1] - 'A'].push_back(cad[3] - 'A');
            grafo[cad[3] - 'A'].push_back(cad[1] - 'A');
        }

        scanf("%s", &cad);
        int l = strlen(cad);
        for(int i = 0; i < l; i += 2) nodos[cad[i] - 'A'] = true;

        int con_tree = 0, con_punto = 0, aux = 0;
        vector<bool> vis(26, false);
        for(int i = 0; i < 26; i++){
            if(!nodos[i] || vis[i]) continue;
            dfs(i, vis, grafo);
            if(grafo[i].size()) con_tree++;
            else con_punto++;
        }

        printf("There are %d tree(s) and %d acorn(s).\n", con_tree, con_punto);
    }

    return 0;
}


