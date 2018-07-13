#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi lista(110);
map<string, int> mapa;
map<int, string> inv;

vector<int> res;//guarda la respuesta.
vector<int> ent;
void topological_sort(vvi &lis, int tam){
    res.clear();
    priority_queue<int> s;
    for(int i = 1; i <= tam; i++){
        if(!ent[i]) s.push(-i);
    }

    int n, m;
    while(s.size()){
        n = -s.top();
        s.pop();
        res.push_back(n);

        for(int i = 0; i < lis[n].size(); i++){
            m = lis[n][i];
            ent[m]--;
            if(!ent[m]) s.push(-m);
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, caso = 1;
    char cad[55], cad2[55];

    while(scanf("%d", &n) != EOF){
        ent.assign(n+1, 0);
        res.clear(); mapa.clear(); inv.clear();

        for(int i = 1; i <= n; i++){
            scanf("%s", &cad);
            mapa[(string) cad] = i;
            lista[i].clear();
            inv[i] = (string) cad;
        }

        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%s %s", &cad, &cad2);
            lista[mapa[cad]].push_back(mapa[cad2]);
            //printf("edge %d %d\n", mapa[cad], mapa[cad2]);
            ent[mapa[cad2]]++;
        }

        topological_sort(lista, n);
        printf("Case #%d: Dilbert should drink beverages in this order:", caso++);
        for(int i = 0; i < res.size(); i++){
            printf(" %s", inv[res[i]].c_str());
        }
        printf(".\n\n");
    }

    return 0;
}


