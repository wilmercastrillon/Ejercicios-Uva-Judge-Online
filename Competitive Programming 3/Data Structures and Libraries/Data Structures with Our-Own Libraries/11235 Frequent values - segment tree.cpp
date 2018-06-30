#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

struct segment_tree{
    vector<ii> st, A;
    vector<int> st2;
    int n;

    int mov_izq(int index){
        return index << 1;
    }

    int mov_der(int index){
        return (index << 1) + 1;
    }

    void construir(int pos, int izq, int der){
        if(izq == der){
            st[pos].first = A[der].first;
            st[pos].second = A[der].second;
            st2[pos] = A[der].second - A[der].first;
            return;
        }

        construir(mov_izq(pos), izq, (izq + der) >> 1);
        construir(mov_der(pos), ((izq + der) >> 1) + 1, der);
        int aux1 = mov_izq(pos), aux2 = mov_der(pos);

        st[pos].first = st[aux1].first;
        st[pos].second = st[aux2].second;
        st2[pos] = max(st2[aux1], st2[aux2]);
    }

    void iniciar(vector<ii> arr){//metodo a invocar
        A = arr;
        n = A.size();
        st.assign(n*4, ii(0, 0));
        st2.assign(n*4, -1);
        construir(1, 0, n - 1);
    }

    bool existeNodo(int n){
        return (n < st2.size() && st2[n] != -1);
    }

    int rmq(int pos, int i, int j){
        //cout << "llegan " << i << " , " << j << " para el nodo " << st[pos].first << " , " << st[pos].second << endl;
        if(i == j) return 0;
        if(i > st[pos].second || j < st[pos].first || i > j) return -1;
        if(i == st[pos].first && j == st[pos].second) return st2[pos];

        int mi = mov_izq(pos), md = mov_der(pos);

        if(i == st[pos].first){
            //cout << "caso 1" << endl;
            if(!existeNodo(mi)){
                return  min(j, st[pos].second) - i;
            }else{
                return max(rmq(mi, i, min(j, st[mi].second)),
                           (!existeNodo(md))? -1 : rmq(md, max(i, st[md].first), j));
            }
        }else if(j == st[pos].second){
            //cout << "caso 2" << endl;
            if(!existeNodo(mi)){
                return  j - max(i, st[pos].first);
            }else{
                return max(rmq(mi, i, st[mi].second),
                           (!existeNodo(md))? -1 : rmq(md, max(i, st[md].first), st[md].second));
            }
        }

        //cout << "caso 3" << endl;
        if(!existeNodo(mi)) return j - i;
        int aux1 = rmq(mi, max(i, st[mi].first), min(j, st[mi].second));
        int aux2 = rmq(md, max(i, st[md].first), min(j, st[md].second));
        if(aux1 == -1) return aux2;
        if(aux2 == -1) return aux1;
        return max(aux1, aux2);
    }

    int Query(int i, int j){//metodo a invocar
        return rmq(1, i, j) + 1;
    }
};

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int n, q, x, ant, p1, p2, ai, aj;

    while(scanf("%d", &n), n){
        scanf("%d", &q);
        vector<ii> v;
        segment_tree st;

        scanf("%d", &ant);
        p1 = 0;
        for(int i = 1; i < n; i++){
            scanf("%d", &x);
            if(x != ant){
                v.push_back(ii(p1, i - 1));
                p1 = i;
                ant = x;
            }
        }
        v.push_back(ii(p1, n - 1));

        st.iniciar(v);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &ai, &aj);
            printf("%d\n", st.Query(ai-1, aj-1));
        }
    }

    return 0;
}


