#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)
#define inf 1000000000

using namespace std;

int main(){
    int n, x;

    while(scanf("%d", &n) != EOF){
        vector<int> d;

        forr(i, n){
            scanf("%d", &x);
            d.push_back(x);
        }
        d.push_back(inf);
        sort(d.rbegin(),d.rend());
        n++;

        bool posible = true;
        int sum = 0, k, acum;
        forab(i,1,n){
            k = i;
            sum += d[i];

            acum = 0;
            forab(j,k+1,n){
                acum += min(d[j],k);
            }

            if(sum > k*(k-1)+acum){
                posible = false;
                break;
            }
        }

        if(posible && sum%2==0) printf("1\n");
        else printf("0\n");
    }

    return 0;
}


