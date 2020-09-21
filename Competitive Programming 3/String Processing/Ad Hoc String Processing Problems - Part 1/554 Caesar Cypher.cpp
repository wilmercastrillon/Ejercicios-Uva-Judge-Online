#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

map<string, bool> mapa;
map<char, int> letra;
map<int,char> letrainv;

void pre(){
    letra.clear();
    forr(i, 26){
        letra['A'+i] = i;
        letrainv[i] = ('A'+i);
    }
    letra[' '] = 26;
    letrainv[26] = ' ';
}

int main(){
    pre();
    string n, msg, mejor, x, word;

    while(getline(cin, n)){
        mapa.clear();
        mapa[n] = true;
        while(n[0] != '#'){
            getline(cin, n);
            mapa[n] = true;
        }
        getline(cin, msg);

        word = "";
        int mayp = 0, mayl = 0, auxl, auxp;
        forr(k, 27){
            x = msg;
            auxl = auxp = 0;
            //printf("k = %d\n", k);
            forr(i, x.size()){
                x[i] = letrainv[(letra[x[i]]+k) % 27];
                if(x[i] != ' ') word.push_back(x[i]);
                else{
                    if(mapa[word]){
                        auxl += word.size();
                        auxp++;
                    }
                    word = "";
                }
            }
            if(mapa[word]){
                auxl += word.size() + 1;
                auxp++;
            }

            if(mayp < auxp){
                mayp = auxp;
                mayl = auxl;
                mejor = x;
            }else if(mayp == auxp && mayl < auxl){
                mejor = x;
                mayl = auxl;
            }
        }

        int len = 0;
        stringstream ss(mejor);
        ss >> x;
        cout << x;
        len += x.size();
        while(true){
            if(ss >> x){
                if(len+x.size() > 60){
                    cout << '\n';
                    len = 0;
                } else {
                    cout << ' ';
                    len++;
                }
            }
            else break;
            cout << x;
            len += x.size();
        }
        cout << '\n';
    }
    return 0;
}


