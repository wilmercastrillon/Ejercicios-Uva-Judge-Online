#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;
typedef long long int tdato; //no debe ser unsigned para la resta!!!
tdato base = 1000000000;

struct bigint{
    vector<tdato> num;
    bool signo;

    bigint(){ signo = true; }
    bigint(int n){
        num.clear();
        signo = n >= 0; n = abs(n);
        while(n){
            num.push_back((n >= base)? n % base: n);
            n /= base;
        }
    }
    bigint(string n){
        num.clear();
        signo = n[0] != '-';
        if(n[0] == '-') n = n.substr(1);
        for(int i = n.size(); i > 0; i -= 9){
            if(i < 9) num.push_back(atoi(n.substr(0, i).c_str()));
            else num.push_back(atoi(n.substr(i-9, 9).c_str()));
        }
        quitar_zeros_izq();
    }

    void quitar_zeros_izq(){
        while(num.size() && !num.back()) num.pop_back();
    }
    void imprimir(){
        if(!signo && num.size()) printf("-");
        printf("%d", ((num.size())? num.back(): 0));
        for(int i = num.size() - 2; i >= 0; i--)
            printf("%09d", num[i]);
        printf("\n");
    }
    void dividirDos(){
        tdato carry = 0;
        ulli aux;
        for (int i = num.size() - 1; i >= 0; --i) {
            aux = num[i] + carry * base;
            num[i] = aux / 2;
            carry = aux % 2;
        }
        quitar_zeros_izq();
    }

    bigint suma(bigint b) {
        ulli carry = 0, aux;
        int l = max(b.num.size(), num.size());
        bigint c;

        for(int i = 0; i < l || carry; i++){
            aux = carry;
            if(i < b.num.size()) aux += b.num[i];
            if(i < num.size()) aux += num[i];

            if(aux >= base){
                c.num.push_back(aux % base);
                carry = aux / base;
            }else{
                c.num.push_back(aux);
                carry = 0;
            }
        }
        return c;
    }

    bigint resta(bigint b) {//asumimos que b es menor
        tdato carry = 0;//no debe ser unsigned
        bigint c;

        for(int i = 0; i < num.size(); i++){
            c.num.push_back(num[i]);
            c.num[i] -= ((i < b.num.size())? b.num[i]: 0) + carry;
            if(c.num[i] < 0){
                c.num[i] += base;
                carry = 1;
            }else carry = 0;
        }
        c.quitar_zeros_izq();
        return c;
    }

    bigint multiplicar(bigint b) {
        ulli aux = 0, carry;
        bigint c;
        c.num.assign(num.size() + b.num.size(), 0);

        for(int i = 0; i < num.size(); i++){
            carry = 0;
            for(int j = 0; j < b.num.size() || carry; j++){
                aux = c.num[i + j] + carry + (num[i] * ((j < b.num.size())? b.num[j] : 0));
                carry = aux / base;
                c.num[i + j] = aux % base;
            }
        }
        c.quitar_zeros_izq();
        return c;
    }

    bigint karatsuba(bigint y) {
        bigint xy;
        bigint x = *this;
        if(min(x.num.size(), y.num.size()) < 83){
            xy = x.multiplicar(y);  xy.signo = true;
            return xy;
        }
        int m = max(x.num.size(), y.num.size()) / 2;//punto optimo en el rango [66-100]

        bigint x1, x0, y1, y0, z0, z1, z2;
        if(x.num.size() > m) x1.num.assign(x.num.begin()+m,x.num.end());
        else x1.num.assign(1,0);
        if(y.num.size() > m) y1.num.assign(y.num.begin()+m,y.num.end());
        else y1.num.assign(1,0);
        if(x.num.size() > m) x0.num.assign(x.num.begin(),x.num.begin()+m);
        else x0.num.assign(x.num.begin(),x.num.end());
        if(y.num.size() > m) y0.num.assign(y.num.begin(),y.num.begin()+m);
        else y0.num.assign(y.num.begin(),y.num.end());

        z2 = x1.karatsuba(y1);//z2 = x1.multiplicar(y1);
        z0 = x0.karatsuba(y0);//z0 = x0.multiplicar(y0);
        x1 = x1.suma(x0);
        y1 = y1.suma(y0);
        z1 = ((x1.karatsuba(y1)).resta(z2)).resta(z0);//z1 = ((x1.multiplicar(y1)).resta(z2)).resta(z0);

        vector<tdato> v(2*m,0);
        z2.num.insert(z2.num.begin(),v.begin(),v.end());
        z1.num.insert(z1.num.begin(),v.begin(),v.begin()+m);
        xy = (z2.suma(z1)).suma(z0);
        xy.signo = true;
        return xy;
    }

    bigint dividir(bigint b) {
        if(comparar(b) < 0){
            bigint cero(0);
            return cero;
        }
        bigint may, men, med, m;
        m = bigint(1);
        may = suma(m); may.signo = true;
        men = bigint(0);
        int cmp;

        while(true){
            med = may.suma(men); med.signo = true;
            med.dividirDos();
            m = med.karatsuba(b); m.signo = true;

            cmp = comparar(m);
            if(cmp == 0) break;
            else if(cmp < 0) may = bigint(med);
            else{
                if(resta(m).comparar(b) < 0) break;
                else men = bigint(med);
            }
        }
        return med;
    }

    int comparar(bigint b){//este es: 1 mayor, 0 igual, -1 menor
        if(num.size() > b.num.size()) return 1;
        else if(num.size() < b.num.size()) return -1;
        else{
            for(int i = num.size() - 1; i >= 0; i--){
                if(num[i] > b.num[i]) return 1;
                else if(num[i] < b.num[i]) return -1;
            }
            return 0;
        }
    }
};

bool operator>(bigint &a, bigint &b){
    if(a.signo == b.signo){
        if(a.signo) return a.comparar(b) > 0;
        else return b.comparar(a) > 0;
    }else return a.signo;
}
bool operator<(bigint &a, bigint &b){
    if(a.signo == b.signo){
        if(a.signo) return a.comparar(b) < 0;
        else return b.comparar(a) < 0;
    }else return !a.signo;
}
bool operator==(bigint &a, bigint &b){
    if(a.signo != b.signo) return false;
    else return a.comparar(b) == 0;
}
bool operator!=(bigint &a, bigint &b){
    return !(a==b);
}
bigint operator+(bigint &a, bigint&b){
    bigint c;
    if(a.signo == b.signo){
        c = a.suma(b);
        c.signo = a.signo;
    }else if(a > b){
        c = a.resta(b);
        c.signo = a.signo;
    }else{
        c = b.resta(a);
        c.signo = b.signo;
    }
    return c;
}
bigint operator-(bigint &a, bigint&b){
    bigint c;
    if(a.comparar(b) > 0){
        if(a.signo == b.signo) c = a.resta(b);
        else c = a.suma(b);
        c.signo = a.signo;
    }else{
        if(a.signo == b.signo) c = b.resta(a);
        else c = a.suma(b);
        c.signo = !b.signo;
    }
    return c;
}
bigint operator*(bigint &a, bigint &b){
    bigint c = a.multiplicar(b);
    c.signo = a.signo == b.signo;
    return c;
}
bigint operator/(bigint &a, bigint &b){
    bool s = (a.signo == b.signo);
    a.signo = true; b.signo = true;
    bigint c = a.dividir(b);
    c.signo = s;
    return c;
}

bigint sqrt(bigint &n) {
    bigint a, b, m, w;
    a = n;  b = bigint(1);

    while(1) {
        m = (a+b);
        m.dividirDos();
        if(m == b) break;
        w = m*m;
        if(w > n) a = m;
        else b = m;
    }
    return m;
}

int main(){//No terminado
    //freopen("entrada.txt", "r", stdin);
    cin.tie(NULL);
    string s;
    bigint a;

    int t;
    scanf("%d", &t);

    while(t--){
        cin >> s;
        a = bigint(s);
        a = sqrt(a);
        a.imprimir();    }
    return 0;
}


