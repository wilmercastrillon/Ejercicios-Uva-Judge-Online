#include <bits/stdc++.h>

using namespace std;

bool ar[3];

void insertar(stack<int> &s, queue<int> &c, priority_queue<int> &cp, int x){
    if(ar[0]) s.push(x);
    if(ar[1]) c.push(x);
    if(ar[2]) cp.push(x);
}

void devolver(stack<int> &s, queue<int> &c, priority_queue<int> &cp, int &n1, int &n2, int &n3){
    if(ar[0]){
        if(s.size()){
            n1 = s.top();
            s.pop();
        }else n1 = -1;
    }

    if(ar[1]){
        if(c.size()){
            n2 = c.front();
            c.pop();
        }else n2 = -1;
    }

    if(ar[2]){
        if(cp.size()){
            n3 = cp.top();
            cp.pop();
        }else n3 = -1;
    }
}

int main(){
    int n, m, x;

    while(scanf("%d", &n) != EOF){

        stack<int> pila;
        queue<int> cola;
        priority_queue<int> cola_prioridad;
        ar[0] = ar[1] = ar[2] = true;
        int a, b, c;

        for(int i = 0; i < n; i++){
            scanf("%d %d", &m, &x);
            if(m == 1){
                insertar(pila, cola, cola_prioridad, x);
            }else{
                devolver(pila, cola, cola_prioridad, a, b, c);
                if(ar[0]) if(a != x) ar[0] = false;
                if(ar[1]) if(b != x) ar[1] = false;
                if(ar[2]) if(c != x) ar[2] = false;
            }
        }

        int con = ar[0] + ar[1] + ar[2];
        if(con > 1) printf("not sure\n");
        else if(!con) printf("impossible\n");
        else if(ar[0]) printf("stack\n");
        else if(ar[1]) printf("queue\n");
        else printf("priority queue\n");
    }

    return 0;
}


