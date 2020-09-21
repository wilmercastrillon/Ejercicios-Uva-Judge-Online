#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

set<string> pal;
string letras[10];
bool dedos[10];
int n, q, x;

void llenar(){
    letras[0] = "qaz";
    letras[1] = "wsx";
    letras[2] = "edc";
    letras[3] = "rfvtgb";
    letras[4] = " ";
    letras[5] = " ";
    letras[6] = "yhnujm";
    letras[7] = "ik,";
    letras[8] = "ol.";
    letras[9] = "p;/";
}

bool contains(string &x, char c){
    forr(i, x.size()){
        if(x[i] == c) return true;
    }
    return false;
}

bool val(string &x){
    bool pos;
    forr(i, x.size()){
        pos = false;
        forr(j, 10){
            if(dedos[j])
            if(contains(letras[j], x[i])){
                pos = true;
                break;
            }
        }
        //printf("")
        if(!pos) return false;
    }
    return true;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    llenar();
    string in;

    while(cin >> n >> q){
        pal.clear();
        memset(dedos, true, sizeof(dedos));
        forr(i, n){
            cin >> x;
            dedos[x-1] = false;
        }

        int best = 0;
        forr(i, q){
            cin >> in;
            if(in.size() < best) continue;
            if(val(in)){
                if(in.size() > best){
                    pal.clear();
                    best = in.size();
                }
                pal.insert(in);
            }
        }

        cout << pal.size() << '\n';
        for(auto &s: pal){
            cout << s << '\n';
        }
    }

    return 0;
}


