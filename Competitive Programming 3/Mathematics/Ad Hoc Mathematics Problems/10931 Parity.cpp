#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    unsigned int n;

    while(cin >> n,n){
        bitset<33> bs(n);
        int i = 32;
        while(!bs[i--]);  i++;

        cout << "The parity of ";
        for(;i>=0;i--) cout << bs[i];
        cout << " is " << __builtin_popcount(n) << " (mod 2)." << '\n';
    }

    return 0;
}


