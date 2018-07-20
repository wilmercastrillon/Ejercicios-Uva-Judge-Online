#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, dfsCont, root;
vvi lista;
vi dfs_low, dfs_num, padre;
vector<bool> puntos;

void dfs(int nodo){//dfs modificado
    dfs_low[nodo] = dfs_num[nodo] = dfsCont++;
    int aux;

    for(int i = 0; i < lista[nodo].size(); i++){
        aux = lista[nodo][i];

        if(dfs_num[aux] == -1){
            padre[aux] = nodo;
            if(nodo == 1){//raiz
                root++;
                puntos[nodo] = (root > 1);
            }
            dfs(aux);

            if(dfs_low[aux] >= dfs_num[nodo] && nodo != 1) puntos[nodo] = true;
            dfs_low[nodo] = min(dfs_low[nodo], dfs_low[aux]);
        }else if(padre[aux] != nodo)
            dfs_low[nodo] = min(dfs_low[nodo], dfs_num[aux]);
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    char cad[400];
    int q, w;

    while(scanf("%d", &n), n){
        getchar();
        lista.assign(n+1, vi(0)); dfs_low.assign(n+1, 0);
        padre.assign(n+1, 0); dfs_num.assign(n+1, -1);
        dfsCont = root = 0; puntos.assign(n+1, false);

        while(1){
            gets(cad);
            stringstream ss(cad);
            string x;
            ss >> x;
            if(x[0] == '0') break;
            q = atoi(x.c_str());
            while(ss >> x){
                w = atoi(x.c_str());
                lista[q].push_back(w);
                lista[w].push_back(q);
            }
        }

        dfs(1);
        int con = 0;
        for(int i = 1; i <= n; i++){
            if(puntos[i]) con++;
        }
        printf("%d\n", con);
    }

    return 0;
}


