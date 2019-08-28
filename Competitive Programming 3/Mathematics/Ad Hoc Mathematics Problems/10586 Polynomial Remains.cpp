#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef vector<int> vi;

int n, k;

struct poly{
    vector<int> coef;
    poly(vi &v){//de mayor a menor grado lli
        coef.assign(v.begin(),v.end());
    }
    poly(){}

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
    int x;

    while(scanf("%d %d",&n, &k), n >= 0){
        vi v;
        forr(i,n+1){
            scanf("%d", &x);
            v.push_back(x);
        }

        poly p(v);
        for(int i = p.coef.size()-1; i-k >= 0; --i){
            p.coef[i-k] = -p.coef[i] + p.coef[i-k];
            p.coef.pop_back();
        }
        //cout << "f(x)= " << p.toString() << endl;

        printf("%d", p.coef[0]);
        forab(i,1,p.coef.size())
            printf(" %d", p.coef[i]);
        printf("\n");
    }
    return 0;
}


