#include <bits/stdc++.h>
#define inf 1000000000
#define forr(a, n) for(int a = 0; a < n; ++a)

using namespace std;
typedef pair<int, int> ii;//estado, mask de positivos
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

map<int, int> mapa;
bool signo[10];//1-positivo, 0-negativo
int pot[10], ar[40330];
bool prime[16] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0};

void pre(){
    pot[0] = 1;
    for(int i = 1; i < 10; i++){
        pot[i] = pot[i-1]*10;
    }

    string str = "12345678";
    int pos = 0, n;
    do{
        n = atoi(str.c_str());
        ar[pos++] = n;
    }while(next_permutation(str.begin(), str.end()));
}

void limpiar(){
    forr(i, 40330){
        mapa[ar[i]] = inf;
    }
}

int adelante(int num, int i, int j){
    //if(i > j) swap(i, j);
    int c = num, nuevo = 0, ex = 0;
    while(c){
        //printf("c = %d | nuevo = %d ", c, nuevo);
        if(c%10 != i){
            if(c%10==j){
                nuevo += j*pot[ex++];
                nuevo += i*pot[ex++];
        //        printf("se agrega doble ");
            }else  nuevo += (c%10)*pot[ex++];
        }
        //printf("\n");
        c /= 10;
    }
    //printf("c = %d | nuevo = %d\n", c, nuevo);
    return nuevo;
}
int atras(int num, int i, int j){
    //if(j > i) swap(j, i);
    int c = num, nuevo = 0, ex = 0;
    while(c){
        if(c%10 != i){
            if(c%10==j){
                nuevo += i*pot[ex++];
                nuevo += j*pot[ex++];
            }else  nuevo += (c%10)*pot[ex++];
        }
        c /= 10;
    }
    return nuevo;
}

int bfs(int est){
    //vi dist(mapa.size() + 5, inf);
    queue<int> cola;
    cola.push(est);
    //dist[mapa[est]] = 0;
    mapa[est] = 0;
    int aux1, aux2, next;

    while(cola.size()){
        est = cola.front();
        cola.pop();
        aux1 = est;
        if(est == 12345678) return mapa[est];
        //printf("llegamos a %d\n", est);

        for(int i = 8; i >= 1; i--){
            if(aux1%10 == i){
                aux1 /= 10;
                continue;
            }

            aux1 = aux2 + 0;
            for(int j = 8; j>=1; j--){
                if(aux2%10 == j || i==j) continue;
                if((signo[i] != signo[j]) && prime[i+j]){
                    //printf("\tpuede haber cambio entre los digitos %d %d\n", i, j);
                    next = adelante(est, i, j);
                    if(mapa[next] > mapa[est]+1){
                        //printf("\t\t 1-puede ir a %d con peso %d\n", next, mapa[est]+1);
                        mapa[next] = mapa[est]+1;
                        cola.push(next);
                    }//else printf("\t\tempeora de %d a %d\n", next, est);

                    next = adelante(est, j, i);
                    if(mapa[next] > mapa[est]+1){
                        //printf("\t\t 2-puede ir a %d con peso %d\n", next, mapa[est]+1);
                        mapa[next] = mapa[est]+1;
                        cola.push(next);
                    }//else printf("\t\tempeora de %d a %d\n", next, est);

                    next = atras(est, i, j);
                    if(mapa[next] > mapa[est]+1){
                        //printf("\t\t 3-puede ir a %d con peso %d\n", next, mapa[est]+1);
                        mapa[next] = mapa[est]+1;
                        cola.push(next);
                    }//else printf("\t\tempeora de %d a %d\n", next, est);

                    next = atras(est, j, i);
                    if(mapa[next] > mapa[est]+1){
                        //printf("\t\t 4-puede ir a %d con peso %d\n", next, mapa[est]+1);
                        mapa[next] = mapa[est]+1;
                        cola.push(next);
                    }//else printf("\t\tempeora de %d a %d\n", next, est);
                }
                aux2 /= 10;
            }
            aux1 /= 10;
        }
    }

    return -1;
}

int main(){
    int n, caso = 0;
    pre();

    while(scanf("%d", &n), n){
        limpiar();
        int q = abs(n);
        signo[abs(n)] = n > 0;

        for(int i = 1; i < 8; i++){
            scanf("%d", &n);
            q *= 10;
            q += abs(n);
            signo[abs(n)] = n > 0;
        }

        printf("Case %d: %d\n", ++caso, bfs(q));

    }

    return 0;
}



