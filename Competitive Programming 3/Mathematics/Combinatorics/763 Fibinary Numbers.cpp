#include<bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
//typedef unsigned long long int i128;
typedef __int128 i128;

string s1, s2;
i128 fibo[105];

void pre(){
    i128 x1 = 0, x2 = 1, i = 0; //acum = 0;
    forr(j,104){
        i = x1 + x2;
        x1 = x2;
        x2 = i;
        fibo[j] = i;
    }
}

i128 getnum(string cad){
    reverse(cad.begin(), cad.end());
    i128 acum = 0;

    forr(i, cad.size()){
        if(cad[i]=='1') acum += fibo[i];
    }
    return acum;
}

string getcad(i128 x){
    int pos = lower_bound(fibo,fibo+103,x) - fibo;
    if(fibo[pos] > x) pos--;
    string res = "";

    for(int i = pos; i >= 0; i--){
        if(fibo[i] <= x){
            x -= fibo[i];
            res.push_back('1');
        }else res.push_back('0');
    }

    //reverse(res.begin(), res.end());
    if(!res.size()) res.push_back('0');
    return res;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    pre();
    cin.tie(NULL);
    cin >> s1 >> s2;

    while(1){
        i128 n1 = getnum(s1);
        i128 n2 = getnum(s2) + n1;
        string imp = getcad(n2);
        cout << imp << '\n';
        if(cin >> s1 >> s2){
            cout << '\n';
        }else break;
    }

    return 0;
}


