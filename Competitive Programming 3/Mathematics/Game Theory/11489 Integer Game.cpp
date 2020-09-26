#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int con[10];
string s;

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    int caso = 0;
    cin >> s;

    while(cin >> s){
        memset(con, 0, sizeof(con));
        int acum = 0;
        forr(i, s.size()){
            con[s[i]-'0']++;
            acum += (s[i]-'0');
        }

        int mov = con[3]+con[6]+con[9];
        bool ini = 0;
        if(acum % 3){
            for(int i = acum%3; i < 10; i+=3)
                ini = ini || (con[i] > 0);
        }
        if(acum%3!=0 && !ini) printf("Case %d: T\n", ++caso);
        else if((ini+ mov) & 1) printf("Case %d: S\n", ++caso);
        else printf("Case %d: T\n", ++caso);
    }
    return 0;
}


