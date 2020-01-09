#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<double, double> ii;//y, x

const double eps = 1e-7;
double d;
int n;

bool cubierto(ii &p, ii &centro){
    return (hypot(centro.first-p.first,centro.second-p.second) - d <= eps);
}

ii nextCircle(ii p){
    if(p.second > d){
        return ii(p.first,0.0);
    }
    double c = sqrt(d*d - p.second*p.second);
    return ii(p.first+c, 0.0);
}

bool cmp(ii &a, ii &b){
    if(fabs(a.first-b.first) < eps) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    double x, y, med;
    int caso = 0;

    while(scanf("%d %lf", &n, &d), n){
        vector<ii> puntos;//y, x
        //vector<ii> sol;//x, y
        forr(i,n){
            scanf("%lf %lf", &x, &y);
            puntos.push_back(ii(x, y));
        }
        sort(puntos.begin(),puntos.end(),cmp);

        int res = 1, ant = 0, ini = 0;
        ii aux = nextCircle(puntos[0]);
        for(int next = 0; next < n; ++next){
            //printf("punto (%.3f , %.3f) centro(%.3f , %.3f) ", puntos[next].first,puntos[next].second, aux.first, aux.second);
            if(!cubierto(puntos[next],aux)){
                //printf("no cubierto\n");
                if(ant == next){
                    res = -1;
                    break;
                }

                aux = nextCircle(puntos[next]);
                bool cubre = true;
                forab(j,ini,next){
                    if(!cubierto(puntos[j],aux)){
                        cubre = false;
                        break;
                    }
                }

                if(!cubre){
                    ant = next;
                    ini = next;
                    next--;
                    res++;
                }
            } //else printf(" cubierto\n");
        }

        printf("Case %d: %d\n", ++caso, res);
    }

    return 0;
}

/*
4 56
17 2
17 50
33 51
-39 15
-------------
4 70
-18 14
-16 67
3 20
-32 31
*/


