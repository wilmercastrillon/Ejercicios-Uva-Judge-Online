#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

vector<string> vec;

double solve(int &pos){
    //cout << "Llamado recursivo con " << vec[pos] << " pos: " << pos << endl;
    if(vec[pos][0] == '('){
        string x = vec[pos++].substr(1);
        double a = atof(x.c_str());
        //cout << "\t a = " << a << endl;
        double b = solve(pos);
        //cout << "\t b = " << b << endl;
        pos++;
        double c = solve(pos);
        //cout << "\t c = " << c << endl;
        //pos++;
        //printf("a %.2f, b %.2f, c %.2f | con pos %d\n", a, b, c, pos);
        return a*(b+c) + (1.0-a)*(b-c);
    }else{
        while(vec[pos].back() == ')'){
            vec[pos].pop_back();
        }
        //cout << "retorna " << vec[pos] << endl;
        return atof(vec[pos].c_str());
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    string cad, x;

    while(getline(cin,cad)){
        if(cad == "()") break;
        vec.clear();
        stringstream ss(cad);
        while(ss >> x){
            vec.push_back(x);
        }

        int pos = 0;
        double res = solve(pos);
        printf("%.2f\n", res);
    }

    return 0;
}


