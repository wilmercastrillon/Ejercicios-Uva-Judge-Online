#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define inf 1000000000

using namespace std;

map<char, int> mapa;//Prioridad de operadores

bool isoperator(char c){
    return c == '+' || c == '*';
}
bool isparentesis(char c){
    return c == '(' || c == ')';
}

int solve_postfix(vector<string> &v){
    stack<int> pila;//negativo -> operacion
    int a, b, x;
    forr(i, v.size()){
        if(isdigit(v[i][0])) x = atoi(v[i].c_str());
        else x = v[i][0]*-1;

        if(x < 0){
            if(pila.size() < 2) return inf;
            a = pila.top(); pila.pop();
            b = pila.top(); pila.pop();
            if(x*-1 == '+') pila.push(a+b);
            else pila.push(a*b);
        }else{
            pila.push(x);
        }
    }
    if(pila.size() == 1) return pila.top();
    else return inf;
}

vector<string> build_postfix(vector<string> &infix){
    vector<string> res;
    stack<string> pila;
    string cad, x;
    bool op = false;
    forr(i, infix.size()){
        cad = infix[i];
        if(isdigit(cad[0])){
            res.push_back(cad);
        }else{
            if(cad[0] == ')'){
                while(pila.size()){
                    x = pila.top(); pila.pop();
                    if(x[0] == '(') break;
                    res.push_back(x);
                }
            }else{
                while(pila.size() && cad[0] != '('){
                    x = pila.top();
                    if(x[0] == '(' || mapa[cad[0]] > mapa[x[0]])
                        break;
                    pila.pop();
                    //printf("empuja %c >= %c \n", x[0], cad[0]);
                    res.push_back(x);
                }
                pila.push(cad);
            }
        }
    }

    while(pila.size()){
        x = pila.top(); pila.pop();
        res.push_back(x);
    }
    return res;
}

vector<string> build_infix(string &cad){
    vector<string> res;
    string n;
    int contp = 0;

    forr(i, cad.size()){
        n = "";
        if(isdigit(cad[i])){
            while(true){
                n.push_back(cad[i]);
                if(isdigit(cad[i+1])) i++;
                else break;
            }
        } else {
            if(cad[i] == '(') contp++;
            else if(cad[i] == ')'){
                contp--;
            }
            if(contp<0 || isalpha(cad[i]) || (!i && isoperator(cad[i]))
                    || (i && isoperator(cad[i]) && isoperator(cad[i-1]))){//Error
                res.clear();
                break;
            }
            n.push_back(cad[i]);
        }
        res.push_back(n);
    }
    if(contp != 0) res.clear();
    return res;
}

void imp(vector<string> &vs){
    forr(i, vs.size()){
        cout << vs[i] << " ";
    }
    cout << endl;
}

int main(){
    cin.tie(NULL);
    mapa['*'] = 2; mapa['+'] = 1;//Prioridades
    string cad;
    int n;  cin >> n;

    while(cin >> cad){
        vector<string> infix = build_infix(cad);
        vector<string> postfix = build_postfix(infix);
        //imp(postfix);
        int res = solve_postfix(postfix);
        if(res != inf) cout << res << endl;
        else cout << "ERROR\n";
    }

    return 0;
}


