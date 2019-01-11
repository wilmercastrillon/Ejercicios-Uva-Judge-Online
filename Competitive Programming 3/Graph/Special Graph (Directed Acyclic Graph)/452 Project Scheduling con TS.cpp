#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <sstream>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vvii grafo;
int costo[30], arcos[30];
bool used[30];

vi res;
bool vis[110];

void dfs(vvii &lista, int nodo){
    vis[nodo] = 1;
    ii par;
    for(int i = 0; i < lista[nodo].size(); i++){
        par = lista[nodo][i];
        if(!vis[par.second]){
            dfs(lista, par.second);
        }
    }
    res.push_back(nodo);
}

void topological_sort(vvii &lis, int tam){
    for(int i = 0; i < tam; i++){
        if(!vis[i]) dfs(lis, i);
    }
    reverse(res.begin(), res.end());
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t;
    char input[70], c;
    scanf("%d", &t);
    string str;
    getchar();
    gets(input);

    while(t--){
        grafo.assign(30, vii(0));
        memset(costo, 0, sizeof(costo));
        memset(arcos, 0, sizeof(arcos));
        memset(used, 0, sizeof(used));
        vi inicio;

        while(gets(input)){
            if(input[0] == '\0') break;
            stringstream ss(input);
            ss >> str;  c = str[0];
            ss >> str;  costo[c-'A'] = atoi(str.c_str());
            used[c-'A'] = true;
            while(ss >> str){
                //printf("otros : %s\n", str.c_str());
                for(int i = 0; i < str.size(); i++){
                    grafo[str[i]-'A'].push_back(ii(0, c-'A'));
                    arcos[c-'A']++;
                }
            }
        }

        vi dist(27, inf);
        for(int i = 0; i < 28; i++){
            for(int j = 0; j < grafo[i].size(); j++){
                grafo[i][j].first = -costo[i];
                //printf("desde %c a %c peso %d\n", i+'A', j+'A', costo[i]);
            }
            if(arcos[i] == 0 && used[i]) dist[i] = 0;
        }

        topological_sort(grafo, 27);
        ii par;
        int aux;

        for(int i = 0; i < 27; i++){
            for(int j = 0; j < grafo[i].size(); j++){
                par = grafo[i][j];
                aux = dist[i] + par.first;
                if(dist[par.second] > aux){
                    dist[par.second] = aux;
                }
            }
        }

        int may = 0;
        for(int i = 0; i < dist.size(); i++){
            if(dist[i] == inf) continue;
            may = max(may, -dist[i] + costo[i]);
            //printf("[%d] = %d\n", i, -dist[i] + costo[i]);
        }

        printf("%d\n", may);
        if(t) printf("\n");
    }

    return 0;
}


