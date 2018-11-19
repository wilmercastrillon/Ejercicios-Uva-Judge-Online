#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int mayor, primero;

void bfs(int n, vvi &grafo){
    mayor = primero = 0;
    vector<int> dia(grafo.size(), -1);
    vector<int> can(grafo.size(), 0);
    queue<int> cola;
    cola.push(n);
    dia[n] = 0;
    can[1] = 0;
    int nodo, next;

    while(cola.size()){
        nodo = cola.front(); cola.pop();
        //printf("bfs = %d\n", nodo);
        next = dia[nodo] + 1;

        for(int i = 0; i < grafo[nodo].size(); i++){
            if(dia[grafo[nodo][i]] == -1){
                dia[grafo[nodo][i]] = next;
                can[next]++;
                cola.push(grafo[nodo][i]);
            }
        }
    }

    for(int i = 0; i < can.size(); i++){
        if(can[i] > mayor){
            mayor = can[i];
            primero = i;
        }
    }
}

int main(){
    int n, t, m, x, c;

    while(scanf("%d", &n) != EOF){
        vvi grafo(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            for(int j = 0; j < m; j++){
                scanf("%d", &x);
                grafo[i].push_back(x);
            }
        }

        scanf("%d", &t);
        for(int i = 0; i < t; i++){
            scanf("%d", &c);
            bfs(c, grafo);
            if(mayor == 0){
                printf("0\n");
            }else{
                printf("%d %d\n", mayor, primero);
            }
        }
    }


    return 0;
}


