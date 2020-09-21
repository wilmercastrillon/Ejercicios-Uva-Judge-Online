#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int, string> is;

vector<is> cars;

void tolower(string &s){
    forr(i, s.size()){
        if(isalpha(s[i]))
            s[i] = tolower(s[i]);
    }
}

bool cmp(is &a, is &b){
    if(a.first != b.first) return a.first < b.first;

    string s1 = a.second, s2 = b.second;
    tolower(s1);  tolower(s2);
    return s1 < s2;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, t, aux;
    string nombre, x, in;

    while(cin >> n){
        cars.clear();
        getchar();

        forr(i, n){
            getline(cin, in);
            istringstream ss(in);

            ss >> nombre;
            ss >> x;//:
            ss >> aux;
            t = aux * 60;
            ss >> x;//min
            ss >> aux;
            t += aux;
            ss >> x;//sec
            ss >> aux;
            t = (t*1000) + aux;

            cars.push_back(is(t, nombre));
        }

        sort(cars.begin(), cars.end(), cmp);
        forr(i, n){
            if(i % 2 == 0){
                cout << "Row " << (i/2+1) << endl;
            }
            cout << cars[i].second << '\n';
        }
        cout << '\n';
    }

    return 0;
}


