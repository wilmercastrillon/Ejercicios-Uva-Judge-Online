#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int var[30], invar[30];

int main(){
    cin.tie(NULL);
    int n;
    string cad;
    cin >> n;

    while(n--){
        cin >> cad;
        char c;
        bool neg = false, res;

        forr(i, cad.size()){
            if(cad[i] == '('){
                memset(var, 0, sizeof(var));
                memset(invar, 0, sizeof(invar));
            }else if(cad[i] == ')'){
                i++;//omitir el 'or'
                res = true;
                forr(j, 26){
                    if(var[j] > 0 && invar[j] > 0){
                        //printf("se repite el %c \n", j+'a');
                        res = false;
                        break;
                    }
                }
                if(res) break;
            }else if(cad[i] != '&'){
                if(cad[i] == '~'){
                    i++;
                    neg = true;
                }
                c = cad[i];
                if(!neg){
                    var[c-'a']++;
                }else{
                    invar[c-'a']++;
                    neg = false;
                }
            }
        }

        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


