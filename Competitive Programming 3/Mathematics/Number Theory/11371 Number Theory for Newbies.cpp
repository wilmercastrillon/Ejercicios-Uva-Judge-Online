#include<bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

string cad;

void ajustar(){
    forab(i,1,cad.size()){
        if(cad[i] != '0'){
            swap(cad[0],cad[i]);
            break;
        }
    }
}

int main(){
    cin.tie(NULL);

    while(cin >> cad){
        lli men = 0, may = 0;

        sort(cad.begin(), cad.end());
        if(cad[0] == '0') ajustar();
        forr(i,cad.size()){
            men *= 10;  men += (cad[i]-'0');
        }

        sort(cad.rbegin(), cad.rend());
        if(cad[0] == '0') ajustar();
        forr(i,cad.size()){
            may *= 10;  may += (cad[i]-'0');
        }

        printf("%lld - %lld = %lld = 9 * %lld\n", may, men, may-men, (may-men)/9LL);
    }

    return 0;
}


