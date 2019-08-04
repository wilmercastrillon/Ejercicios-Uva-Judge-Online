#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#define MAX 5010 //n
#define Log2 13 //2^10 > 1000
#define forr(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int l[MAX<<1], e[2*MAX], h[MAX], idx;
int arr[MAX<<1], spt[MAX<<1][Log2], nivel[MAX], padre[MAX];

struct sparseTable{
    sparseTable(){}

    sparseTable(int n, int a[]){
        memset(spt, 0, sizeof(spt));
        for(int i = 0; i < n; i++){
            //printf("estamos en %d\n", i);
            arr[i] = a[i];
            spt[i][0] = i;
        }

        for(int j = 1; (1<<j) <= n; j++){
            for(int i=0; i+(1<<j)-1 < n; i++)
                if(arr[spt[i][j-1]] < arr[spt[i+(1<<(j-1))][j-1]])
                    spt[i][j] = spt[i][j-1];
                else
                    spt[i][j] = spt[i+(1<<(j-1))][j-1];
        }
    }

    int query(int i, int j){//de i hasta j, index desde 0
        int k = (int) floor(log(((j-i+1)*1.0))/log(2.0));
        if(arr[spt[i][k]] <= arr[spt[j-(1<<k)+1][k]])
            return spt[i][k];
        else return spt[j-(1<<k)+1][k];
    }
};

sparseTable table;

void dfs(int nodo, int deep, vvi &grafo){
    h[nodo] = idx;
    e[idx] = nodo;
    l[idx++] = deep;
    nivel[nodo] = deep;

    for(int i = 0; i < grafo[nodo].size(); i++){
        if(h[grafo[nodo][i]] != -1) continue;
        padre[grafo[nodo][i]] = nodo;
        dfs(grafo[nodo][i], deep+1, grafo);
        e[idx] = nodo;
        l[idx++] = deep;
    }
}

void BuildRMQ(vvi &grafo){//llamar antes de LCA
    idx = 0;
    memset(h, -1, sizeof(h));
    memset(l, -1, sizeof(l));
    padre[1] = 1;
    dfs(1, 0, grafo);
    //printf("dfs\n");
    table = sparseTable(grafo.size()<<1, l);
    //printf("tabla sparse\n");
}

int LCA(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    return e[table.query(h[u], h[v])];
}

vi path(int inicio, int obj){
    vi vis;
    int nodo = inicio;
    do{
        vis.push_back(nodo);
        if(nodo == obj) break;
        nodo = padre[nodo];
    } while(true);
    return vis;
}

void imp(vi v){
    forr(i, v.size())
        printf("%d ", v[i]);
    printf("\n");
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, a, b, q, _lca;
    while(scanf("%d", &n), n){
        vvi grafo(n+1, vi(0));
        forr(i, n-1){
            scanf("%d %d", &a, &b);
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        //printf("leyo\n");
        BuildRMQ(grafo);
        //printf("construyo\n");

        scanf("%d", &q);
        vi v1, v2;
        forr(i, q){
            scanf("%d %d", &a, &b);
            _lca = LCA(a, b);
            v1 = path(a, _lca);
            v2 = path(b, _lca);
            v1.insert(v1.end(), v2.rbegin()+1,v2.rend());
            //  imp(v1);

            if(v1.size()&1){
                printf("The fleas meet at %d.\n",v1[v1.size()>>1]);
            }else{
                printf("The fleas jump forever between %d and %d.\n",
                       min(v1[(v1.size()>>1)-1],v1[v1.size()>>1]),
                       max(v1[(v1.size()>>1)-1],v1[v1.size()>>1]));
            }
        }
    }
    return 0;
}


