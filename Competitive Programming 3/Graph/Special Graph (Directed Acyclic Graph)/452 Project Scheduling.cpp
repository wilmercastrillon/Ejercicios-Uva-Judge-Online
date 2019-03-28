#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <sstream>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vi dijkstra(vvii &grafo, int nodo, int tam){
    vi dis(tam + 1, inf);
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

    return dis;
}

vvii grafo;
int costo[30], arcos[30];
bool used[30];

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

        for(int i = 0; i < 28; i++){
            for(int j = 0; j < grafo[i].size(); j++){
                grafo[i][j].first = -costo[i];
                //printf("desde %c a %c peso %d\n", i+'A', j+'A', costo[i]);
            }
        }

        vi res;
        int ans = -1;
        for(int i = 0; i < 27; i++){
            if(arcos[i] || !used[i]) continue;
            //printf("inicio desde %d - %c\n", i, i+'A');
            res = dijkstra(grafo, i, 27);

            for(int j = 0; j < res.size(); j++){
                if(ans < -res[j] + costo[j]){
                    ans = -res[j] + costo[j];
                    //printf("   Hacia %c tiene %d\n", j+'A', ans);
                }
            }
        }

        printf("%d\n", ans);
        if(t) printf("\n");
    }

    return 0;
}


