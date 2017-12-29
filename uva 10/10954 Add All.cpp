#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x;
    while(scanf("%d", &n), n){
        priority_queue<int> cola;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            cola.push(-x);
        }

        int acum = 0, aux1, aux2, aux3;

        while(cola.size() > 1){
            aux1 = -cola.top();
            cola.pop();
            aux2 = -cola.top();
            cola.pop();
            //cout << "se saca " << aux1 << " " << aux2 << endl;

            aux3 = aux1 + aux2;
            acum += aux3;
            cola.push(-aux3);
            //cout << "se agrega " << aux3 << endl;
        }

        printf("%d\n", acum);
    }

    return 0;
}


