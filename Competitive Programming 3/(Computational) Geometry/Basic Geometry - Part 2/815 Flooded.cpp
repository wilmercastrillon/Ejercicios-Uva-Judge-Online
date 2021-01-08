#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef long long int lli;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, caso = 1;
    double vol;

    while(cin >> n >> m, n){
        vector<lli> tab;
        forr(i, n)
            forr(j, m){
                scanf("%d", &x);
                tab.pb(x);
            }
        tab.pb(1000000000);
        cin >> vol;
        sort(tab.begin(), tab.end());

        double aux, h = tab[0];
        lli i = 0, acum = 0, inc;
        while(acum < vol){
            i++;
            inc = i*(tab[i]-tab[i-1])*100;
            if(acum+inc > vol){
                aux = ((vol-acum)*1.0)/(i*1.0);
                h += aux/100.0;
                acum = vol;
                break;
            }else{
                acum += inc;
            }
            h += (tab[i]-tab[i-1]);
        }
        //if(i == 0) i = n*m;

        printf("Region %d\n", caso++);
        printf("Water level is %.2f meters.\n", h);
        printf("%.2f percent of the region is under water.\n", ((i*1.0)/(n*m*1.0))*100.0);
        printf("\n");
    }

    return 0;
}


