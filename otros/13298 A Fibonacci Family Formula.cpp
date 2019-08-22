#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000009

using namespace std;
typedef unsigned long long int ulli;
typedef vector<ulli> vulli;

struct matrix{
    vector<vulli> mat;

    matrix(){}
    matrix(int n, int m){
        mat.assign(n,vulli(n,0));
    }
    matrix(int n){
        mat.assign(n,vulli(n,0));
        for(int i=n-2,j=n-1; i>=0; i--,j--){
            mat[i][j] = 1;
            mat[n-1][j] = 1;
        }
        mat[n-1][0] = 1;
    }
};

matrix matmul(matrix &a, matrix &b){//multiplicar
    matrix ans(a.mat.size(),0);
    int i, j, k;

    for(i = 0; i < a.mat.size(); i++)
    for(j = 0; j < a.mat.size(); j++)
        for(ans.mat[i][j] = k = 0; k < a.mat.size(); k++)
            ans.mat[i][j] = (ans.mat[i][j] + ((a.mat[i][k] * b.mat[k][j])%mod)) % mod;

    return ans;
}

matrix matpow(matrix base, ulli p){//exp binaria
    matrix ans(base.mat.size(),0);
    int i, j;

    for(i = 0; i < base.mat.size(); i++)
        for(j = 0; j < base.mat.size(); j++)
            ans.mat[i][j] = (i == j);

    while(p){
        if(p&1) ans = matmul(ans, base);
        base = matmul(base, base);
        p >>= 1;
    }
    return ans;
}

vector<matrix> matrices;

void pre(){
    forab(i,1,101)
        matrices.push_back(matrix(i));
}

void imp(matrix m){
    printf("matriz:\n");
    forr(i,m.mat.size()){
        forr(j,m.mat.size()){
            printf("%3llu", m.mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int k;
    ulli n;
    pre();
    matrix aux;

    while(scanf("%d %llu", &k, &n), k){
        if(k == 1){
            printf("1\n");
            continue;
        }
        aux = matpow(matrices[k-1],n);
        //imp(aux);
        printf("%llu\n", aux.mat[k-1][k-1]);
    }
    return 0;
}


