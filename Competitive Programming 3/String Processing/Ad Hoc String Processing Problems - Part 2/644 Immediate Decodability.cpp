#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

vector<string> v;
string cad;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, caso = 0;
    string in;

    while(cin >> in){
        v.clear();
        while(in != "9"){
            v.push_back(in);
            cin >> in;
        }

        bool pos = true;
        forr(i, v.size()){
            forr(j,v.size()){
                if(i == j || v[i].size() > v[j].size()) continue;
                if(v[i] == v[j].substr(0,v[i].size())){
                    pos = false;
                    i = v.size();
                    break;
                }
            }
        }

        caso++;
        if(pos)
            cout << "Set " << caso << " is immediately decodable\n";
        else
            cout << "Set " << caso << " is not immediately decodable\n";
    }

    return 0;
}


