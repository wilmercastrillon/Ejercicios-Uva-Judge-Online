#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int l, u, r, tab[10000];
vector<int> boton;

int bfs(){
    memset(tab, 5436, sizeof(tab));
    queue<int> cola;
    cola.push(l);
    tab[l] = 0;
    int n, m;

    while(cola.size()){
        n = cola.front();
        cola.pop();

        for(int i = 0; i < r; i++){
            m = (n + boton[i]) % 10000;
            if(tab[n] + 1 >= tab[m]) continue;
            tab[m] = tab[n] + 1;
            if(m == u) return tab[m];
            cola.push(m);
        }
    }
    return -1;
}

int main(){
    int x, caso = 1;

    while(scanf("%d %d %d", &l, &u, &r), r){
        boton.clear();
        for(int i = 0; i < r; i++){
            scanf("%d", &x);
            boton.push_back(x);
        }

        int con = bfs();
        if(con == -1) printf("Case %d: Permanently Locked\n", caso++);
        else printf("Case %d: %d\n", caso++, con);
    }

    return 0;
}


