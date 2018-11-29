#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, char> is;
typedef pair<int, is> iis;//peso, nodo, tipo
typedef vector<iis> viis;
typedef vector<viis> vviis;
typedef vector<int> vi;
#define inf 1000000000
#define mpiis(a, b, c) iis(a, is(b, c))

vi dijkstra(vviis &grafo, int nodo, char tipo){
    vi dis(grafo.size() + 1, inf);
    priority_queue<iis> cola;
    cola.push(mpiis(-0, nodo, tipo));
    int peso, aux;
    iis triple, triple2;

    while(cola.size()){
        triple = cola.top();//peso, (nodo, tipo)
        cola.pop();
        peso = -triple.first;
        nodo = triple.second.first;

        if(dis[nodo] <= peso) continue;
        dis[nodo] = peso;

        for(int i = 0; i < grafo[nodo].size(); i++){
            triple2 = grafo[nodo][i];
            aux = dis[nodo] + triple2.first;
            if(dis[triple2.second.first] > aux && triple2.second.second == tipo){
                cola.push(mpiis(-aux, triple2.second.first, tipo));
            }
        }
    }

    return dis;
}

int main(){
    int n, m, x, y, z;

    while(scanf("%d", &n), n){
        map<char, int> mapa;
        map<int, char> inv;
        vviis grafo(1);
        char tipo[3], dir[3], ini[3], fin[3], me[3], profe[3];
        int con = 1;

        for(int i = 0; i < n; i++){
            scanf("%s %s %s %s %d", &tipo, &dir, &ini, &fin, &z);
            if(!mapa[ini[0]]){
                inv[con] = ini[0];
                mapa[ini[0]] = con++;
                grafo.push_back(viis(0));
            }
            if(!mapa[fin[0]]){
                inv[con] = fin[0];
                mapa[fin[0]] = con++;
                grafo.push_back(viis(0));
            }

            grafo[mapa[ini[0]]].push_back(mpiis(z, mapa[fin[0]], tipo[0]));
            if(dir[0] == 'B'){
                grafo[mapa[fin[0]]].push_back(mpiis(z, mapa[ini[0]], tipo[0]));
            }
        }
        scanf("%s %s", &me, &profe);

        //printf("desde %d\n", mapa[me[0]]);
        vi v1 = dijkstra(grafo, mapa[me[0]], 'Y');
        //for(int i = 0; i < v1.size(); i++){
        //    printf("%d -> %d\n", i, v1[i]);
        //}
        //printf("desde %d\n", mapa[profe[0]]);
        vi v2 = dijkstra(grafo, mapa[profe[0]], 'M');
        //for(int i = 0; i < v2.size(); i++){
        //    printf("%d -> %d\n", i, v2[i]);
        //}

        int men = inf-1, aux;
        vector<char> res;
        for(int i = 1; i < con; i++){
            aux = v1[i] + v2[i];
            if(men > aux){
                men = aux;
                res.clear();
                res.push_back(inv[i]);
            }else if(men == aux){
                res.push_back(inv[i]);
            }
        }

        if(res.size()){
            printf("%d", men);
            for(int i = 0; i < res.size(); i++){
                printf(" %c", res[i]);
            }
            printf("\n");
        }else printf("You will never meet.\n");
    }

    return 0;
}


