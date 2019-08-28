#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int m = 1000010, primo[1000020];
vector<int> p;  int lim = sqrt(m)+1;
map<int, int> mapa;

void criba(){
    memset(primo, 0, sizeof(primo));

    for(int i = 2; i < m; i++){
        if(primo[i]) continue;
        p.push_back(i);
        primo[i] = i;
        if(i > lim) continue;

        for(int j = i*i; j < m; j += i)
            primo[j] = i;
    }
}

void factCriba(int n){
    int l, pos;
    while(n != 1){
        if(n >= m){//n mayor a logintud del array
            l = sqrt(n) + 1;  pos = -1;
            while(p[++pos] <= l)
                if(n%p[pos]==0){
                    mapa[p[pos]]++;
                    n /= p[pos];
                    break;
                }
            if(p[pos] > l){
                mapa[n]++;
                break;
            }
        }else{
            mapa[primo[n]]++;
            n /= primo[n];
        }
    }
}

int sum(int n){
    int con = 0;
    while(n){
        con += n%10;
        n /= 10;
    }
    return con;
}

int next(int n){
    int suma,acum;
    while(true){
        mapa.clear();
        factCriba(n);
        suma = sum(n);
        acum = 0;

        if(mapa.size() == 1 && mapa[n] == 1){
            n++;
            continue;
        }

        map<int,int>::iterator it;
        for(it = mapa.begin(); it!=mapa.end(); ++it){
            //printf("el %d aparece %d veces | suma = %d\n", it->first, it->second, sum(it->first));
            acum += sum(it->first)*(it->second);
        }
        //printf("%d | suma %d, sumadiv %d\n", n, suma,acum);
        if(suma == acum) return n;
        n++;
    }
}

int main(){
    criba();
    int t;
    int n;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        printf("%d\n", next(n+1));
    }

    return 0;
}


