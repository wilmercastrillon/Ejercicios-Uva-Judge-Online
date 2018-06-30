#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

int casos, f, c;
char tab[1000][1000];
bool vis[1000][1000];
vector<ii> res(26, pair<int, int>(0, 0)); //first valor, second letra.
int mf[] = {-1, 0, 1, 0}, mc[] = {0, 1, 0, -1};

void dfs(int posf, int posc){
    vis[posf][posc] = true;
    //printf("para %c en %d %d", tab[posf][posc], posf, posc);

    int auxf, auxc;
    for(int j = 0; j < 4; j++){
        auxf = posf + mf[j];
        auxc = posc + mc[j];
        //printf("verificamos en %d %d para j = %d\n", auxf, auxc, j);
        if(auxc == c || auxc < 0 || auxf == f || auxf < 0) continue;
        if(!vis[auxf][auxc] && tab[auxf][auxc] == tab[posf][posc]) dfs(auxf, auxc);
    }
}

bool cmp(ii a, ii b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(){
    scanf("%d", &casos);
    casos++;

    for(int i = 1; i < casos; i++){
        scanf("%d %d", &f, &c);

        for(int j = 0; j < f; j++){
            scanf("%s", &tab[j]);
        }
        memset(vis, false, sizeof(vis));
        for(int j = 0; j < 26; j++){
            res[j].first = 0;
            res[j].second = 'a' + j;
        }

        for(int j = 0; j < f; j++){
            for(int k = 0; k < c; k++){
                if(!vis[j][k]){
                    res[tab[j][k] - 'a'].first++;
                    dfs(j, k);
                    //printf("dfs para %c en pos %d %d\n", tab[j][k], j, k);
                }
            }
        }

        sort(res.begin(), res.end(), cmp);
        printf("World #%d\n", i);
        for(int j = 0; j < 26; j++) if(res[j].first)
            printf("%c: %d\n", res[j].second, res[j].first);
    }

    return 0;
}
