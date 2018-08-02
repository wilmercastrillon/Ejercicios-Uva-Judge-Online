#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
typedef pair<double, double> ii;
vector<ii> puntos;
double eps = 1e-7;

double posx(ii p1, ii p2, double y){
    return p1.first + ((p2.first-p1.first)*(y-p1.second)/(p2.second-p1.second));
}

int main(){
    int c, n;
    double x, y;
    scanf("%d", &c);

    while(c--){
        scanf("%d", &n);
        puntos.clear();
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &x, &y);
            puntos.push_back(ii(x, y));
        }
        sort(puntos.rbegin(), puntos.rend());

        double acum = 0, ymay = 0, xmin = 0;
        if(n > 1){
            acum = hypot(puntos[0].first-puntos[1].first, puntos[0].second-puntos[1].second);
            ymay = puntos[1].second;
            xmin = puntos[1].first;
        }

        for(int i = 1; i < n; i++){
            //printf("punto = %.5f, %.5f junto con: %.5f, %.5f || punto mas alto: %.5f, %.5f\n",
            //        puntos[i].first, puntos[i].second, puntos[i-1].first, puntos[i-1].second, xmin, ymay);
            if(puntos[i].second > ymay){
                ii par = ii(posx(puntos[i-1], puntos[i], ymay), ymay);
                acum += hypot(par.first-puntos[i].first, par.second-puntos[i].second);
                //printf("----- posicion de luz = %.5f %.5f --- %.5f, %.5f | ", puntos[i].first
                //       , puntos[i].second, par.first, par.second);
                //printf("suma %.5f\n", hypot(par.first-puntos[i].first, par.second-puntos[i].second));
                ymay = puntos[i].second;
                xmin = puntos[i].first;
            }
        }
        printf("%.2f\n", acum);
    }

    return 0;
}


