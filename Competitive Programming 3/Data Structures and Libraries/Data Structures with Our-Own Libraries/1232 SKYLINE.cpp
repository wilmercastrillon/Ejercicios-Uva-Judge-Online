#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int MAX = 1700000, MAXarray = 100010;//16;
int st[MAX], lazy[MAX];
//vi A;

struct segment_tree{
    int n, tamst;

    int mov_izq(int index){ return index << 1; }
    int mov_der(int index){ return (index << 1) + 1; }

    void iniciar(){//metodo a invocar
        n = MAXarray; //A.size();
        tamst = n << 2;
        memset(st,0,sizeof(st));
        memset(lazy,-1,sizeof(lazy));
    }

    void solve_lazy(int pos, int izq, int der){//resolver lazy
        //printf("\t solve lazy en pos %d\n", pos);
        if(lazy[pos] == -1) return;

        st[pos] = lazy[pos];
        //printf("st[%d] = %d\n", st[pos], lazy[pos]);
        if(izq != der){
            lazy[mov_izq(pos)] = lazy[mov_der(pos)] = lazy[pos];
        }
        lazy[pos] = -1;
    }

    int lazy_propagation(int pos, int izq, int der, int i, int j, int nuevo){
        //printf("llego a pos %d rango(%d , %d)\n",pos,izq,der);

        solve_lazy(pos, izq, der);
        if(i <= izq && j >= der && st[pos]!=-1){
            //printf("completo\n");
            if(nuevo >= st[pos]){
                lazy[pos] = nuevo;
                solve_lazy(pos, izq, der);
                return (der-izq)+1;
            }else return 0;
        }

        int aux1 = 0, aux2 = 0, mitad = (izq + der) >> 1, x = -1;
        if(j <= mitad){
            x = 0;
            aux1 = lazy_propagation(mov_izq(pos), izq, (izq + der) >> 1, i, j, nuevo);
        }else if(i > mitad){
            x = 0;
            aux2 = lazy_propagation(mov_der(pos), ((izq + der) >> 1) + 1, der, i, j, nuevo);
        }else{
            aux1 = lazy_propagation(mov_izq(pos), izq, (izq + der) >> 1, i, mitad, nuevo);
            aux2 = lazy_propagation(mov_der(pos), ((izq + der) >> 1) + 1, der, mitad+1, j, nuevo);
        }
        if(aux1+aux2 == (der-izq)+1) st[pos] = nuevo;
        else st[pos] = -1;

        //printf("aux1 %d, aux2 %d\n", aux1,aux2);
        return aux1 + aux2;
    }

    int update(int i, int j, int nuevo){//metodo a invocar
        return lazy_propagation(1, 1, n, i, j, nuevo);//propagar lazy
    }
};

int main(){//No terminado
    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt","w",stdout);
    int t, b, l, r, h, sum, x;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &b);
        //A.assign(16,0);
        segment_tree tree;
        tree.iniciar();

        sum = 0;
        forr(j,b){
            scanf("%d %d %d", &l, &r, &h);
            x = tree.update(l,r-1,h);
            sum += x;

            //forr(i,32){
            //    printf("%d -> st = %d, lazy %d\n", i, st[i], lazy[i]);
			//}
            //printf("encontrado overlap de %d\n",x);
        }
        printf("%d\n",sum);
    }
    while(scanf("%d", &t)!=EOF && t);

    return 0;
}


