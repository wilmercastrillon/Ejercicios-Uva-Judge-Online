#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)
#define MAX 100010

using namespace std;
typedef long long int lli;
vector<int> f;

void llenar(){
    f.push_back(-1);
    f.push_back(1);
    int n = 2;
    while(f.back() < MAX){
        if(n&1) f.push_back(f.back()+(n/4)+(((n-1)/2)&1));
        else f.push_back(f.back()+(n/2));
        n++;
    }
}

int g(int n){//grupo
    if((n/2)&1) return -1*(n/4+1);
    else return n/4;
}

int h(int n){
    if(n%2==0) return 0;
    int k = (n-1)/2;
    if(k&1) return (k+1)/-2;
    else return (k+1)/2;
}

int main(){
    llenar();
    int n, diag, posf, posc, fila, col;
    //forr(i,13) printf("f[%d] = %d\n", i, f[i]);

    while(scanf("%d", &n) != EOF){
        posf = lower_bound(f.begin(),f.end(),n) - f.begin();

        if(posf&1) fila = g(posf);
        else if(g(posf) > 0) fila = g(posf)-(f[posf]-n);
        else fila = g(posf)+(f[posf]-n);

        if(posf&1){
            if(h(posf) > 0) col = h(posf)-abs(n-f[posf]);
            else col = h(posf)+abs(n-f[posf]);
        }else{
            int mitad = (f[posf-1]+f[posf])/2;
            if(posf%4==0){
                if(mitad >= n) col = h(posf-1);
                else col = n - f[posf];
            }else{
                if(mitad+1>=n) col = h(posf-1);
                else col = f[posf] - n;
            }
        }

        printf("%d %d\n",col,fila*-1);
    }

    return 0;
}


