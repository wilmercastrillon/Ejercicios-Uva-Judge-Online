#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, k, peso[110], matriz[501][501], cam[501][501];
bool tab[110][6];
vvii lista;

int dijkstra(vvii &grafo, int nodo, int tam){
    vi dis(tam + 1, 1000000000);
    priority_queue<ii> cola;
    cola.push(ii(-0, nodo));
    int peso, aux;
    ii par, par2;

    while(cola.size()){
        par = cola.top();
        cola.pop();
        peso = -par.first;
        nodo = par.second;

        if(dis[nodo] <= peso) continue;
        dis[nodo] = peso;

        for(int i = 0; i < grafo[nodo].size(); i++){
            par2 = grafo[nodo][i];
            aux = dis[nodo] + par2.first;
            if(dis[par2.second] > aux){
                cola.push(ii(-aux, par2.second));
            }
        }
    }

    int men = 1000000000;
    for(int i = 0; i < 500; i+= 100){
        men = min(men, dis[k+i]);
    }
    return men;
}

int main(){
    //freopen("salida.txt", "w", stdout);

    while(scanf("%d %d", &n, &k) != EOF){
        memset(tab, false, sizeof(tab));
        memset(peso, 5436, sizeof(peso));
        int maxNodo = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &peso[i]);
        }
        lista.assign(501, vii(0));

        string s, aux;
        int aux2;
        getchar();
        for(int i = 0; i < n; i++){
            vector<int> vec;
            getline(cin, s);
            stringstream ss(s);

            while(ss >> aux){
                aux2 = atoi(aux.c_str());
                tab[aux2][i] = true;
                //printf("#%d\n", aux2);
                for(int j = 0; j < vec.size(); j++){
                    lista[aux2+(100*i)].push_back(ii((aux2 - vec[j])*peso[i], vec[j]+(100*i)));
                    lista[vec[j]+(100*i)].push_back(ii((aux2 - vec[j])*peso[i], aux2+(100*i)));
                }
                vec.push_back(aux2);
            }
        }

        for(int i = 0; i < 100; i++){
            for(int j = 0; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(tab[i][j] && tab[i][k]){
                        lista[i+(100*j)].push_back(ii(60, i+(100*k)));
                        lista[i+(100*k)].push_back(ii(60, i+(100*j)));
                    }
                }
            }
        }

        int res = 1000000000;
        for(int i = 0; i < n; i++){
            //printf("iniciando desde %d\n", i*100);
            res = min(res, dijkstra(lista, i*100, 500));
        }

        if(res >= 1000000000) printf("IMPOSSIBLE\n");
        else printf("%d\n", res);
    }

    return 0;
}


