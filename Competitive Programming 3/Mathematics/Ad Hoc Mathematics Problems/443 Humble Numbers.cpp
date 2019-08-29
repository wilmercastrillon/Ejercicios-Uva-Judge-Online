#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;
const lli MAX = 2000000000LL;

lli ar[4] = {2LL,3LL,5LL,7LL};
set<lli> s;
vector<lli> h;

void backTraking(lli n, int depth){
    //printf("llega %lld con depth %d\n",n,depth);
    lli aux = n;
    while(aux <= MAX){
        if(depth < 3) backTraking(aux, depth+1);
        aux = aux*ar[depth];
        //printf("\tinserta %lld\n",aux);
        s.insert(aux);
    }
}

int main(){
    //freopen("salida.txt","w",stdout);
    cin.tie(NULL);

    s.insert(0LL);
    s.insert(1LL);
    backTraking(1LL,0);
    h.assign(s.begin(),s.end());
    //forr(i,20) printf("h[%d] -> %lld\n",i,h[i]);
    lli n;
    string out = "";

    while(cin >> n, n){
        if(n%10==1 && n%100!=11LL) out = "st";
        else if(n%10==2 && n%100!=12LL) out = "nd";
        else if(n%10==3 && n%100!=13LL) out = "rd";
        else out = "th";
        cout << "The " << n << out << " humble number is " << h[n] << ".\n";
    }

    return 0;
}


