#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int f(int a, int b, vector<ii> &v){
    return v[a].first > b;
}

int busqueda_binaria(int men, int may, int num, vector<ii> &v){
    int epsilon = 1, med;

    while(may-men > epsilon){
        med = (may+men)/2;
        if(f(med,num, v))
            may = med;
        else
            men = med;
    }
    return men;
}

int solve(int i, int j, vector<ii> &v){
    int k = busqueda_binaria(0, v.size(), i, v);
    int may = 0;
    for(; k < v.size() && v[k].first <= j; k++){
        may = max(may, min(j, v[k].second) - max(i, v[k].first));
    }
    return may;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, q, x, ant, p1, p2, ai, aj;

    while(scanf("%d", &n), n){
        scanf("%d", &q);
        vector<ii> v;

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

        for(int i = 0; i < q; i++){
            scanf("%d %d", &ai, &aj);
            printf("%d\n", solve(ai - 1, aj - 1, v) + 1);
        }
    }

    return 0;
}


