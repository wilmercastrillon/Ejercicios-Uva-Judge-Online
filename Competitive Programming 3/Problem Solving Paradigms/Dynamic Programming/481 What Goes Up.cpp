#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<int> A;
int aux[1000000], lis[1000000], indexAnt[1000000], n;

void mostrar(int pos){
    stack<int> pila;
    while(pos != -1)
        pila.push(pos), pos = lis[pos];

    while(pila.size()){
        printf("%d\n", A[pila.top()]);
        pila.pop();
    }
}

void LIS(){//incremental
    int tam = 0, pos, res = 0;
    for(int i = 0; i < n; i++){
        pos = lower_bound(aux, aux + tam, A[i]) - aux;
        aux[pos] = A[i];
        indexAnt[pos] = i;
        lis[i] = pos;

        lis[i] = pos? indexAnt[pos-1]: -1;
        if(pos + 1 > tam){
            tam = pos + 1;
            res = i;
        }else if(pos + 1 == tam){
            res = i;
        }
    }

    printf("%d\n-\n", tam);
    mostrar(res);
}

int main(){
    int x;
    while(scanf("%d", &x) != EOF){
        A.push_back(x);
    }
    n = A.size();
    LIS();

    return 0;
}


