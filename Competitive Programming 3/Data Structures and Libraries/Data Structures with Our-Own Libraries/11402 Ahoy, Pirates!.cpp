#include <bits/stdc++.h>

using namespace std;

const int MAX = 4 * 1024000;
char A[1025000];
int st[MAX], lazy[MAX];

struct segment_tree{
    int n;
    int mov_izq(int index){ return index << 1; }
    int mov_der(int index){ return (index << 1) + 1; }

    void construir(int pos, int izq, int der){
        lazy[pos] = -1;
        if(izq == der){
            st[pos] = A[der] - '0';
            return;
        }

        construir(mov_izq(pos), izq, (izq + der) >> 1);
        construir(mov_der(pos), ((izq + der) >> 1) + 1, der);
        int aux1 = mov_izq(pos), aux2 = mov_der(pos);
        st[pos] = st[aux1] + st[aux2];
    }

    void iniciar(int tam){//metodo a invocar
        n = tam;
        construir(1, 0, n - 1);
    }

    int query(int pos, int izq, int der, int i, int j){
        if(i > der || j < izq) return 0;
        solve_lazy(pos, izq, der);
        if(i <= izq && j >= der) return st[pos];

        int aux1 = query(mov_izq(pos), izq, (izq + der) >> 1, i, j);
        int aux2 = query(mov_der(pos), ((izq + der) >> 1) + 1, der, i, j);
        return aux1 + aux2;
    }

    int consulta(int i, int j){
        return query(1, 0, n-1, i, j);
    }

    int cambiar_lazy(int newop, int antop){
        if(newop == 0 || newop == 1) return newop;
        if(antop == 0) return 1;
        if(antop == 1) return 0;
        if(antop == 2) return -1;
        return newop;
    }

    void solve_lazy(int pos, int izq, int der){//soluciona el lazy de un nodo, si no es hoja lo envia a sus hijos
        if(lazy[pos] == -1) return;

        if(lazy[pos] == 0){
            st[pos] = 0;
        }else if(lazy[pos] == 1)
            st[pos] = (der - izq) + 1;
        else st[pos] = ((der - izq) + 1) - st[pos];

        if(izq != der){
            int l = mov_izq(pos), r = mov_der(pos);
            lazy[l] = cambiar_lazy(lazy[pos], lazy[l]);
            lazy[r] = cambiar_lazy(lazy[pos], lazy[r]);
        }
        lazy[pos] = -1;
    }

    int lazy_propagation(int pos, int izq, int der, int i, int j, int op){
        solve_lazy(pos, izq, der);
        if(i > der || j < izq) return st[pos];

        if(i <= izq && j >= der){
            lazy[pos] = op;
            solve_lazy(pos, izq, der);
            return st[pos];
        }

        int aux1 = lazy_propagation(mov_izq(pos), izq, (izq + der) >> 1, i, j, op);
        int aux2 = lazy_propagation(mov_der(pos), ((izq + der) >> 1) + 1, der, i, j, op);
        return st[pos] = aux1 + aux2;
    }

    int update(int i, int j, int op){//metodo a invocar
        return lazy_propagation(1, 0, n-1, i, j, op);
    }
};

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int m, casos, t, q, a, b, cont = 0, l, tam;
    char s[100], s2[3];
    scanf("%d", &casos);

    segment_tree st;

    while(casos--){
        scanf("%d", &m);
        tam = 0;
        for(int i = 0; i < m; i++){
            scanf("%d %s", &t, &s);
            l = strlen(s);

            for(int j = 0; j < t; j++)
                for(int k = 0; k < l; k++)
                    A[tam++] = s[k];
        }

        st.iniciar(tam);
        scanf("%d", &q);
        int conQ = 0;

        printf("Case %d:\n", ++cont);
        while(q--){
            scanf("%s %d %d", &s2, &a, &b);

            switch(s2[0]){
                case 'F':
                    st.update(a, b, 1);
                    break;

                case 'E':
                    st.update(a, b, 0);
                    break;

                case 'I':
                    st.update(a, b, 2);
                    break;

                default:
                    printf("Q%d: %d\n", ++conQ, st.consulta(a, b));
                    break;
            }
        }
    }

    return 0;
}


