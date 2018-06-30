#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

const int MAX = 4 * 100010;

struct segment_tree{
    int st[MAX];
    vi A;
    int n, tamst;

    int mov_izq(int index){ return index << 1; }
    int mov_der(int index){ return (index << 1) + 1; }

    void construir(int pos, int izq, int der){
        if(izq == der){
            st[pos] = A[der];
            return;
        }

        construir(mov_izq(pos), izq, (izq + der) >> 1);
        construir(mov_der(pos), ((izq + der) >> 1) + 1, der);
        int aux1 = mov_izq(pos), aux2 = mov_der(pos);
        st[pos] = st[aux1] * st[aux2];
    }

    void iniciar(vi arr){//metodo a invocar
        A = arr;
        n = A.size();
        tamst = n << 2;
        construir(1, 0, n - 1);
    }

    int query(int pos, int izq, int der, int i, int j){
        if(i > der || j < izq) return -2;
        if(i <= izq && j >= der) return st[pos];

        int aux1 = query(mov_izq(pos), izq, (izq + der) >> 1, i, j);
        int aux2 = query(mov_der(pos), ((izq + der) >> 1) + 1, der, i, j);
        if(aux1 == -2) return aux2;
        if(aux2 == -2) return aux1;

        return aux1 * aux2;
    }

    int RPQ(int i, int j){//metodo a invocar
        return query(1, 0, n-1, i, j);
    }

    int cambiar(int pos, int izq, int der, int index, int nuevo){
        if(index > der || index < izq) return st[pos];
        if(der == index && izq == index){
            A[index] =  nuevo;
            return st[pos] = nuevo;
        }

        int aux1 = cambiar(mov_izq(pos), izq, (izq + der) >> 1, index, nuevo);
        int aux2 = cambiar(mov_der(pos), ((izq + der) >> 1) + 1, der, index, nuevo);
        return st[pos] = aux1 * aux2;
    }

    int update(int index, int num){//metodo a invocar
        return cambiar(1, 0, n-1, index, num);
    }
};

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, k, x, a, b, r;
    char cad[3];

    while(scanf("%d %d", &n, &k) != EOF){
        segment_tree tree;
        vi v;
        string res = "";
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v.push_back((x)? (x < 0)? -1: 1 : 0);
        }
        tree.iniciar(v);

        for(int i = 0; i < k; i++){
            scanf("%s %d %d", &cad, &a, &b);
            if(cad[0] == 'C')
                tree.update(a - 1, (b)? (b < 0)? -1: 1 : 0);
            else{
                r = tree.RPQ(a - 1, b - 1);
                //cout << r << endl;
                if(r == 0) res.push_back('0');
                else if(r > 0) res.push_back('+');
                else res.push_back('-');
            }
        }

        printf("%s\n", res.c_str());
    }

    return 0;
}


