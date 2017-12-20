#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;
typedef vector<int> vi;

struct segment_tree{
    vi st, A;
    int n;

    int mov_izq(int index){
        return index << 1;
    }

    int mov_der(int index){
        return (index << 1) + 1;
    }

    void construir(int pos, int izq, int der){
        //cout << "llamado para pos " << pos << " en rango " << izq << " , " << der << endl;
        if(izq == der){
            st[pos] = A[der];
            //cout << "st en pos " << pos <<  " = " << st[pos] << endl << endl;;
            return;
        }
        construir(mov_izq(pos), izq, (izq + der) >> 1);
        construir(mov_der(pos), ((izq + der) >> 1) + 1, der);
        int aux1 = mov_izq(pos), aux2 = mov_der(pos);

        //cout << "st[" << aux1 << "]: " << st[aux1] << " , st[" << aux2 << "]: " << st[aux2] << endl;
        //cout << "or de " << st[aux1] << " con " << st[aux2] << " es: " << (st[aux1] | st[aux2]) << endl;
        st[pos] = st[aux1] | st[aux2];
        //cout << "en pos " << pos << " en rango " << izq << " , " << der << " se guarda " << st[pos] << endl << endl;;
    }

    void iniciar(vi arr){
        A = arr;
        n = A.size() - 1;
        st.assign(n*4, 0);
        construir(1, 0, n - 1);
    }

    int query(int pos, int izq, int der, int i, int j){
        if(i > der || j < izq) return -1;
        if(i <= izq && j >= der) return st[pos];

        int aux1 = query(mov_izq(pos), izq, (izq + der) >> 1, i, j);
        int aux2 = query(mov_der(pos), ((izq + der) >> 1) + 1, der, i, j);
        if(aux1 == -1) return aux2;
        if(aux2 == -1) return aux1;

        //cout << "st[" << aux1 << "]: " << st[aux1] << " , st[" << aux2 << "]: " << st[aux2] << endl;
        return aux1 | aux2;
    }

    int Query(int i, int j){
        return query(1, 0, n-1, i - 1, j - 1);
    }
};

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, q, x, y;
    vi vec;

    while(scanf("%d", &n) != EOF){
        vec.clear();
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            vec.push_back(1 << x);
        }
        vec.push_back(0);

        segment_tree tree;
        tree.iniciar(vec);

        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &x, &y);
            printf("%d\n", __builtin_popcount(tree.Query(x, y)));
        }
    }

    return 0;
}
