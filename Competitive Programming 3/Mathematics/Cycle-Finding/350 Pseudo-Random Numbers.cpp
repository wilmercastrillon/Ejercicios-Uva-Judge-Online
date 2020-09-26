#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

int z, i, m, l;
unordered_map<int, bool> mapa;

int main(){//No terminado
    int caso = 1, cont;
    while(scanf("%d %d %d %d", &z, &i, &m, &l) != EOF){
        if(!(z||i||m||l)) break;
        mapa.clear();
        cont = 0;
        l = (z*l + i) % m;
        while(mapa[l] == false){
            mapa[l] = true;
            cont++;
            //printf("#%d -> %d\n", cont, l);
            l = (z*l + i) % m;
        }
        printf("Case %d: %d\n", caso++, cont);
    }
    return 0;
}


