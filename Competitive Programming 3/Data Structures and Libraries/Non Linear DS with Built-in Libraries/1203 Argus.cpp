#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int main(){
    //freopen("salida.txt", "w", stdout);
    int q, t, k, con = 0;
    char cad[12];
    priority_queue<ii> cola;//tiempo, id
    map<int, int> mapa;//id, frecuencia

    while(scanf("%s", &cad), cad[0] != '#'){
        scanf("%d %d", &q, &t);
        cola.push(ii(-t, -q));
        mapa[q] = -t;
    }

    scanf("%d", &k);
    int f;
    ii par;
    for(int i = 0; i < k; i++){
        par = cola.top();
        printf("%d\n", -par.second);
        cola.pop();
        cola.push(ii(par.first + mapa[-par.second], par.second));
    }

    return 0;
}


