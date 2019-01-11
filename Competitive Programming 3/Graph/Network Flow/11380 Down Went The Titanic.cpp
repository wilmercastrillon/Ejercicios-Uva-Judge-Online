#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#define inf 1000000000
#define forr(a, b) for(int a=0; a<b; a++)

/*
2 3 2
#.*
~*~

3 5 2
*~~~~
@@..#
*~..#
*/

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int start, target, MAX=1900, MAX2, fil, col, mf, f, matriz[1900][1900], peso;
int _mf[] = {-1, 0, 1, 0};
int _mc[] = {0, 1, 0, -1};
char tab[1000][1000];
vi p;
vvi grafo;
map<char, int> mapa;

void augment(int v, int minEdge){
    if(v == start){ f = minEdge; return; }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, matriz[p[v]][v]));
        matriz[p[v]][v] -= f;  matriz[v][p[v]] += f;
    }
}

int EdmondsKarp(){
    mf = 0;
    while(true){
        f = 0;
        vector<bool> vis(MAX, false);  vis[start] = true;
        queue<int> cola;  cola.push(start);
        p.assign(MAX, -1);
        while(cola.size()){
            int u = cola.front();  cola.pop();
            if(u == target) break;

            for(int j = 0; j < grafo[u].size(); j++){
                int v = grafo[u][j];
                if(matriz[u][v] > 0 && !vis[v]){
                    vis[v] = true;
                    cola.push(v);  p[v] = u;
                }
            }
        }
        augment(target, inf);
        if(f == 0) break;
        mf += f;
    }
    return mf;
}

bool val(int f, int c){
    return !(f<0 || f>=fil || c<0 || c>=col || tab[f][c]=='~' || tab[f][c]=='*');
}

void pre(){
    mapa['*'] = 1;  mapa['.'] = 1;  mapa['@'] = 1000;  mapa['#'] = 1000;
}

void buildGrafo(){
    pre();
    int auxf, auxc;
    start = MAX-3; target = MAX-2;

    int nodo1, nodo2;
    forr(i, fil){
        forr(j, col){
            //printf("fil %d , col %d | caracter: %c , pos %d\n", i, j, tab[i][j], (i*col)+j);
            if(tab[i][j] == '~') continue;
            forr(k, 4){
                auxf = i+_mf[k];  auxc = j+_mc[k];
                //printf("probamos ir a %d , %d\n", auxf, auxc);
                if(val(auxf, auxc)){
                    nodo1 = (i*col)+j;
                    nodo2 = (auxf*col)+auxc;
                    //printf("conexion de %c a %c (%d -> %d) con peso %d\n", tab[i][j], tab[auxf][auxc],
                    //       nodo1,nodo2+MAX2, mapa[tab[i][j]]);
                    grafo[nodo1].push_back(nodo2+MAX2);
                    grafo[nodo2+MAX2].push_back(nodo1);
                    matriz[nodo1][nodo2+MAX2] = mapa[tab[i][j]];

                    //printf("conexion de %c a %c (%d -> %d) con peso %d\n", tab[i][j], tab[auxf][auxc],
                    //       nodo2+MAX2, nodo2, mapa[tab[auxf][auxc]]);
                    grafo[nodo2+MAX2].push_back(nodo2);
                    grafo[nodo2].push_back(nodo2+MAX2);
                    matriz[nodo2+MAX2][nodo2] = mapa[tab[auxf][auxc]];
                    //printf("Ya\n");
                }
            }
            if(tab[i][j] == '#'){
                //printf("## conexion de %d a %d con peso %d\n", (i*col)+j, target, peso);
                grafo[(i*col)+j].push_back(target);
                grafo[target].push_back((i*col)+j);
                matriz[(i*col)+j][target] = peso;
            }else if(tab[i][j] == '*'){
                grafo[start].push_back((i*col)+j);
                grafo[(i*col)+j].push_back(start);
                matriz[start][(i*col)+j] = 1;
            }
        }
    }
}

int main(){//### NO PASO EN C++, PERO SI EN JAVA, No se porque :'V
    while(scanf("%d %d %d", &fil, &col, &peso) != EOF){
        memset(matriz, 0, sizeof(matriz));
        MAX = (fil*col + 5)*2;
        MAX2 = (fil*col) + 1;
        grafo.assign(MAX, vi(0));

        for(int i = 0; i < fil; i++){
            scanf("%s", &tab[i]);
        }
        buildGrafo();
        /*printf("grafo hecho\n");
        for(int i = 0; i < MAX; i++){
            if(grafo[i].size()){
                printf("[%d] -> ", i);
                forr(j, grafo[i].size()){
                    printf("%d, ", grafo[i][j]);
                }
                printf("\n");
            }
        }*/

        printf("%d\n", EdmondsKarp());
    }

    return 0;
}


