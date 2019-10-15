#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
//typedef pair<int,int> ii;
typedef pair<double,double> dd;

bool cmp(dd &a, dd &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

dd intervalo(double x, double w, double r){
    double dx = sqrt(r*r-pow(w/2.0,2.0));
    return dd(x-dx, x+dx);
}

const double eps = 1e-5;

int main(){
    freopen("salida.txt","w",stdout);
    int n;
    double posx, radio, w, l;
    vector<dd> v;

    while(scanf("%d %lf %lf", &n, &l, &w) != EOF){
        v.clear();
        forr(i,n){
            scanf("%lf %lf", &posx, &radio);
            if(radio < w/2.0) continue;
            v.push_back(intervalo(posx, w, radio));
            //printf("inserta (%.3f,%.3f)\n",v.back().first,v.back().second);
        }
        sort(v.begin(),v.end(),cmp);

        //forr(i,v.size()) printf(" (%.3f,%.3f),",v[i].first,v[i].second);
        //printf("\n");

        vector<dd> sol;//imp;
        int res, mejor = 1000000000;
        dd ant;

        forr(j,v.size()){
            if(v[j].second < 0.0) continue;
            if(v[j].first > 0.0) break;

            if(v[j].second > 0.0 && v[j].first <= 0.0){
                ant = v[j];
                sol.clear();
                sol.push_back(ant);
                res = 1;
                //printf("sirve (%.5f %.5f)\n",ant.first,ant.second);

                forab(i, j+1, v.size()){
                    if((ant.second-l)>=eps || fabs(ant.second-l)<=eps){
                        //printf("termino!!!\n");
                        break;
                    }
                    //printf("\t (%.5f %.5f) ",v[i].first,v[i].second);

                    if((v[i].first-ant.second)>=eps || fabs(v[i].first-ant.second)<=eps){
                        //printf("por fuera, NO SIRVIO\n");
                        res = -1;
                        break;
                    }
                    if((ant.second-v[i].second)>=eps || fabs(ant.second-v[i].second)<=eps){
                        //printf("dentro del anterior\n");
                        continue;
                    }//else printf(" %.f - %.7f = %.7f \n",ant.second,v[i].second,ant.second-v[i].second);

                    if(res >= 2 && ((sol[res-2].second-v[i].first)>=eps || fabs(sol[res-2].second-v[i].first)<=eps)
                                && ((v[i].second-ant.second)>=eps || fabs(v[i].second-ant.second)<=eps)){
                        //printf(" |quitar anterior, no sirve de intermedio| ");
                        sol.pop_back();
                    }//else printf(" | comparo con (%.5f,%.5f) (%.5f,%.5f) | ",v[res-2].first,v[res-2].second,ant.first,ant.second);
                    ant = v[i];
                    sol.push_back(ant);
                    res = sol.size();
                    //printf("### si sirve\n",v[i].first,v[i].second);
                }

                if((l-ant.second) > eps) res = -1;
                //printf("\t res final %d\n", res);
                if(res > 0 && res < mejor){
                    mejor = res;
                    //imp = sol;
                }
            }
        }

        if(mejor < 1000000000){
            printf("%d\n",mejor);
        }else printf("-1\n");

    }

    return 0;
}


