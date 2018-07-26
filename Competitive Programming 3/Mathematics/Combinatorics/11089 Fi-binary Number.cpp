#include <bits/stdc++.h>

using namespace std;

int fibo[50], m;

void llenar(){
    m = 0;
    int x1 = 0, x2 = 1, i, lim = 1000000001;

    while(x1 < lim){
        fibo[m++] = x1;        i = x1 + x2;
        x1 = x2;
        x2 = i;
        //printf("%d -> %d\n", m-1, fibo[m-1]);
    }
    fibo[m++] = x1;
    //printf("%d -> %d\n", m-1, fibo[m-1]);
}

int f(int a, int b){
    return fibo[a] > b;
}

int bs(int men, int may, int v){
    int epsilon = 1, med = 0;

    while(may-men > epsilon){
        med = (may+men)/2;
        if(f(med,v))
            may = med;
        else
            men = med;
    }
    return men;
}

int main(){//representacion zeckendorf
    llenar();
    int casos, n, ini;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &n);
        ini = bs(0, m, n);
        vector<bool> vis(ini+1, false);
        while(n){
            //printf("%d\n", fibo[ini]);
            vis[ini] = true;
            n = n - fibo[ini];
            ini = bs(0, m, n);
        }

        for(int i = vis.size() - 1; i >= 2; i--){
            printf("%d", (int) vis[i]);
        }
        printf("\n");
    }

    return 0;
}


