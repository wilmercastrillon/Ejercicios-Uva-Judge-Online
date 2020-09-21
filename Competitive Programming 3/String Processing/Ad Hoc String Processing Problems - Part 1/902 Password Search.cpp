#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

unordered_map<string, int> mapa;

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    int n;
    string cad;

    while(cin >> n >> cad){
        mapa.clear();
        string aux = "", mejor = "";
        int l = cad.size()-(n-1), mejortam = 0;

        forr(i, l){
            aux = cad.substr(i, n);
            mapa[aux]++;
        }

        int con;
        for(auto it = mapa.begin(); it != mapa.end(); ++it){
            con = it -> second;
            if(con > mejortam){
                mejortam = con;
                mejor = it -> first;
            }
            //cout << aux << " = " << con << endl;
        }
        cout << mejor << '\n';
    }
    return 0;
}


