#include <bits/stdc++.h>

using namespace std;
typedef queue<int> qi;

int main(){
    int casos, n, s, q, x, y, todos;
    scanf("%d", &casos);

    for(int i = 0; i < casos; i++){
        scanf("%d %d %d", &n, &s, &q);
        vector<qi> v(n + 1);
        todos = 0;

        for(int j = 1; j <= n; j++){
            scanf("%d", &x);
            todos += x;
            for(int k = 0; k < x; k++){
                scanf("%d", &y);
                v[j].push(y);
            }
            //cout << "leyo " << x << endl;
        }
        //cout << "fin\n";

        stack<int> pila;
        int index = 1, con = 0, res = 0;

        while(res < todos){
            int aux;
            while(pila.size()){
                aux = pila.top();
                if(index == aux){
                    res++;
                    pila.pop();
                    con++;
                    continue;
                } else if(v[index].size() < q){
                    v[index].push(aux);
                    pila.pop();
                    con++;
                    continue;
                }
                break;
            }

            while(pila.size() < s && v[index].size()){
                pila.push(v[index].front());
                v[index].pop();
                con++;
            }

            con += 2;
            index++;
            if(index > n) index = 1;
        }

        printf("%d\n", con - 2);
    }

    return 0;
}


