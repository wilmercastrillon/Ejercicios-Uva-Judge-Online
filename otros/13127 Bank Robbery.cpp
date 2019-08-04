#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define forab(i, a, b) for(int i = a; i < b; i++)

using namespace std;

typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
#define inf 1000000000

vi dijkstra(vvii &grafo, int nodo, int tam){
    priority_queue<ii> cola;
    cola.push(ii(-0, nodo));
    vi dis(tam + 1, inf);  dis[nodo] = 0;
    int peso, aux;
    ii par, par2;

    while(cola.size()){
        par = cola.top();//peso, nodo
        cola.pop();
        peso = -par.first;
        nodo = par.second;

        for(int i = 0; i < grafo[nodo].size(); i++){
            par2 = grafo[nodo][i];
            aux = dis[nodo] + par2.first;
            if(dis[par2.second] > aux){
                dis[par2.second] = aux;
                cola.push(ii(-aux, par2.second));
            }
        }
    }

    return dis;
}

vi bancos, policias;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y, z, b, p;

    while(cin >> n >> m >> b >> p){

        vvii grafo(n + 1);
        bancos.clear();
        policias.clear();

        for(int i = 0; i < m; i++){
            cin >> x >> y >> z;
            grafo[x].push_back(ii(z, y));
            grafo[y].push_back(ii(z, x));
        }

        for(int i = 0; i < b; i++){
            scanf("%d", &x);
            bancos.push_back(x);
        }
        for(int i = 0; i < p; i++){
            scanf("%d", &x);
            policias.push_back(x);
            grafo[n].push_back(ii(1, x));
        }

        vi res;
        int tiempo = 0;
        vi dis = dijkstra(grafo,n,n+1);
        for(int i = 0; i < bancos.size(); i++){
            if(dis[bancos[i]] > tiempo){
                res.clear();
                tiempo = dis[bancos[i]];
                res.push_back(bancos[i]);
            }else if(dis[bancos[i]] == tiempo){
                res.push_back(bancos[i]);
            }
        }
        sort(res.begin(), res.end());

        if(tiempo == inf) printf("%d *\n", res.size());
        else printf("%d %d\n", res.size(), tiempo - 1);
        if(res.size()) printf("%d", res[0]);
        forab(i, 1, res.size()){
            printf(" %d", res[i]);
        }
        printf("\n");
    }

    return 0;
}


