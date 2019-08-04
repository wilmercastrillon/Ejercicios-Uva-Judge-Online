#include <iostream>
#include <vector>
#include <map>
#define inf 2000000000
#define forr(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
map<string, int> mapa;

int n, b;
vvii tab;
ii memo[1010][1010];

ii dp(int tipo, int pos){
    if(tipo == tab.size()-1){
        printf("################################################################# sale\n");
        return ii(0,inf);
    }
    if(memo[tipo][pos].first!=-1){
        printf("memo[%d][%d] = (%d, %d)\n", tipo, pos, memo[tipo][pos].first, memo[tipo][pos].second);
        return memo[tipo][pos];
    }

    ii ans = ii(inf,0);
    forr(i, tab[tipo+1].size()){
        printf("intentar %d %d\n", tipo+1,i);
        ii aux = dp(tipo+1, i);
        aux.first += tab[tipo+1][i].first;
        aux.second = min(aux.second, tab[tipo+1][i].second);
        printf("-----termina con first %d , second %d\n",aux.first,aux.second);

        if(aux.first > b){
            printf("mayor a la capacidad\n");
            continue;
        }
        if(aux.second > ans.second){
            printf("aumenta la calidad general\n");
            ans = aux;
        }else if(aux.second==ans.second && aux.first<ans.first){
            printf("igual calidad y mejora precio\n");
            ans = aux;
        }
    }

    printf("### ans = (%d, %d)\n", ans.first, ans.second);
    //return ans;
    return memo[tipo][pos] = ans;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int t, pos;
    cin >> t;

    while(t--){
        cin >> n >> b;
        string tipo, nombre;
        int precio, calidad;
        tab.clear();
        mapa.clear();
        memo[0][0] = ii(-1,-1);
        tab.push_back(vii(0));

        forr(i, n){
            cin >> tipo >> nombre >> precio >> calidad;
            pos = mapa[tipo];
            if(pos == 0){
                mapa[tipo] = tab.size();
                pos = tab.size();
                memo[tab.size()][0] = ii(-1, -1);
                tab.push_back(vii(0));
                tab[tab.size()-1].push_back(ii(precio, calidad));
            }else{
                memo[pos][tab[pos].size()] = ii(-1, -1);
                tab[pos].push_back(ii(precio, calidad));
            }
        }

        /*forr(i, tab.size()){
            forr(j, tab[i].size()){
                printf("[%4d%3d] ", tab[i][j].first, tab[i][j].second);
            }
            printf("\n");
        }*/

        ii res = dp(0, 0);
        printf("%d\n", res.second);
    }

    return 0;
}


