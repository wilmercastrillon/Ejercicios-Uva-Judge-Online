#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi memo;
vi vec1, vec2, vec3;
map<int, int> val;
int aux[63000], lis[63000], indexAnt[63000], n;

void llenar(){
    val.clear();
    forr(i,vec1.size()){
        val[vec1[i]] = i+1;
        //printf("%d -> %d\n", vec1[i], i+1);
    }
    forr(i,n+1){
        if(val[i] == 0) val[i] = -1000000;
    }
}

bool cmp(int a, int b){
    return val[a] < val[b];
    //return a < b;
}

int bs(int men, int may, int v){
    int epsilon = 1, med = 0;

    while(may-men > epsilon){
        med = (may+men)/2;
        //printf("aux[%d] < v = %d < %d? = %d\n", med, aux[med], v,cmp(aux[med],v));
        //if(cmp(vec2[med],v))
        if(cmp(aux[med],v))
            men = med;
        else
            may = med;
    }
    //printf("men %d, med  %d, may %d, cmp %d | %d < %d\n",men,med,may,cmp(aux[men],v), aux[men],v);
    return (cmp(aux[men],v))? may: men;
}

void imp(int ar[], int v){
    for(int i = 0; i < v; ++i){
        printf("%3d",ar[i]);
    }
    printf("\n");
}

int LIS(){
    memset(aux, 0, sizeof(aux));
    int tam = 0, pos, res = 0;
    for(int i = 0; i < vec2.size(); i++){
        pos = bs(0, tam, vec2[i]);
        //printf("pos = %d hasta %d, buscando %d\n------------\n", pos,tam, vec2[i]);
        aux[pos] = vec2[i];
        indexAnt[pos] = i;
        lis[i] = pos;
        lis[i] = pos? indexAnt[pos-1]: -1;
        if(pos + 1 > tam){
            tam = pos + 1;
            res = i;
        }
    }
    return tam;
}

int main(){
    int t, p, q, x, caso = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &p, &q);
        n = n*n;
        vec1.clear();
        vec2.clear();
        vec3.clear();

        forr(i,p+1){
            scanf("%d", &x);
            vec1.push_back(x);
        }
        forr(i,q+1){
            scanf("%d", &x);
            vec3.push_back(x);
        }
        llenar();
        sort(vec1.begin(), vec1.end());

        int buscar;
        forr(i, vec3.size()){
            buscar = lower_bound(vec1.begin(), vec1.end(),vec3[i])-vec1.begin();
            if(buscar == vec1.size() || vec1[buscar] != vec3[i]) continue;
            vec2.push_back(vec3[i]);
        }
        printf("Case %d: %d\n", ++caso, LIS());
    }
}


