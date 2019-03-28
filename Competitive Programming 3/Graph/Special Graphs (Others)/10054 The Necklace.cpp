#include <stdio.h>
#include <string.h>
#include <list>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef list<ii>::iterator liii;

int degree[52];
vector<vector<ib>> lista;//nodo destino, bandera visitado
list<ii> cyc;

void EulerTour(liii i, int u){
    //printf("sigue %d\n", u);
    for(int j = 0; j < lista[u].size(); j++){
        ib v = lista[u][j];
        if(v.second){
            v.second = false;
            lista[u][j].second = false;
            //printf(" quitamos %d a %d\n", u, j);
            for(int k = 0; k < lista[v.first].size(); k++){
                ib uu = lista[v.first][k];
                //printf("#quitamos %d a %d\n", v.first, k);
                if(uu.first==u && uu.second){
                    uu.second = false;
                    lista[v.first][k].second = false;
                    break;
                }
            }
            //printf("inserta par %d a %d\n", u, v.first);
            EulerTour(cyc.insert(i, ii(v.first, u)), v.first);
        }
    }
}

int main(){
    int n, m, x, y, t, caso = 0;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        lista.assign(52, vector<ib>(0));
        memset(degree, 0, sizeof(degree));

        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            lista[x].push_back(ib(y, true));
            lista[y].push_back(ib(x, true));
            degree[x]++;
            degree[y]++;
        }

        bool par = true;
        int inicio = 1;
        for(int i = 0; i < 52 && par; i++){
            if(degree[i]&1) par = false;
            else if(degree[i]){
                inicio = i;
            }
        }

        printf("Case #%d\n", ++caso);
        if(!par){
            printf("some beads may be lost\n");
        }else{
            cyc.clear();
            EulerTour(cyc.begin(), inicio);

            for(liii it = cyc.begin(); it != cyc.end(); it++){
                //vec.push_back(*it);
                printf("%d %d\n", (*it).first, (*it).second);
            }
            //for(int i = vec.size()-1; i >= 0; i--){
            //    printf("%d %d\n", vec[i].first, vec[i].second);
            //}
        }
        if(t > 0) printf("\n");
    }

    return 0;
}




