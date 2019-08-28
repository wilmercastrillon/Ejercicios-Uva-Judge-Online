#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;
typedef vector<lli> vi;

lli exp_bin(lli a, lli n) {
	lli res = 1;
	while(n) {
		if (n & 1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

struct poly{
    vector<lli> coef;
    poly(vi &v){//de mayor a menor grado
        coef.assign(v.begin(),v.end());
    }
    poly(){}

    lli evaluar(lli x){
        lli res = 0LL;
        for(int i = 1; i <= coef.size(); ++i)
            res += coef[i-1]*exp_bin(x,(lli) coef.size()-i);
        return res;
    }

    void derivar(){
        for(int i = 1; i <= coef.size(); ++i)
            coef[i-1] *= ((lli) coef.size()-i);
        coef.pop_back();
    }

    string toString(){
        stringstream ss;
        for(int i = 1; i <= coef.size(); ++i){
            if(coef[i-1] >= 0) ss << "+";
            ss << coef[i-1];
            ss << "x^";
            ss << (coef.size()-i);
        }
        return ss.str();
    }
};

int main(){
    //freopen("salida.txt","w",stdout);

    string cad1, cad2;
    while(getline(cin,cad1)){
        getline(cin,cad2);

        lli x, xn = (lli) atoi(cad1.c_str());
        vi v;

        istringstream ss(cad2);
        while(ss >> x){
            v.push_back(x);
        }

        poly p(v);
        //cout << "f(x)= " << p.toString() << endl;
        p.derivar();
        //cout << "f'(x)= " << p.toString() << endl;

        printf("%lld\n", p.evaluar(xn));
    }
    return 0;
}


