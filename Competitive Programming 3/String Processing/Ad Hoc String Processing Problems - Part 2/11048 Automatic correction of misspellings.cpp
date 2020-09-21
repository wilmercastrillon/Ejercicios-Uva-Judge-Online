#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

vector<string> dict;

bool order(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    int cont = 0;
    forr(i, s1.size()){
        if(s1[i] != s2[i]){
            if(cont > 0 || i == s1.size()-1) return false;
            swap(s2[i], s2[i+1]);
            i--;
            cont++;
        }
    }
    //cout << "is order\n";
    return true;
}

bool wrong(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    int cont = 0;
    forr(i, s1.size()){
        if(s1[i] != s2[i]){
            if(cont > 0) return false;
            cont++;
        }
    }
    //cout << "is wrong\n";
    return true;
}

bool _more(string s1, string s2){//s2 tiene una adicional
    if(s1.size() != s2.size()-1) return false;
    int cont = 0, j = 0;
    forr(i, s1.size()){
        if(s1[i] != s2[j]){
            if(cont > 0) return false;
            cont++;
            i--;
        }
        j++;
    }
    //cout << "is more\n";
    return true;
}

bool _less(string s1, string s2){//s2 tiene una menos
    if(s1.size() != s2.size()+1) return false;
    int cont = 0, j = 0;
    forr(i, s1.size()){
        if(s1[i] != s2[j]){
            if(cont > 0) return false;
            cont++;
            j--;
        }
        j++;
    }
    //cout << "is less\n";
    return true;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, q;
    string in;

    while(cin >> n){
        dict.clear();
        forr(i, n){
            cin >> in;
            dict.push_back(in);
        }

        int idx;
        cin >> q;
        forr(j, q){
            cin >> in;

            idx = -1;
            forr(i, n){
                if(dict[i] == in){
                    idx = i;
                    break;
                }
                if(idx != -1) continue;
                if(order(dict[i],in) || wrong(dict[i],in) || _more(dict[i],in) || _less(dict[i],in)){
                    idx = i;
                }
            }

            if(idx == -1){
                cout << in << " is unknown\n";
            }else if(dict[idx] == in){
                cout << in << " is correct\n";
            }else{
                cout << in << " is a misspelling of " << dict[idx] << '\n';
            }
        }

    }

    return 0;
}


