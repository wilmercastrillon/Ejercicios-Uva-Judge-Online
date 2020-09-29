#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
const double eps = 1e-6;
const double PI = acos(-1.0);

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    double b, h;
    int casos;
    cin >> casos;

    while(cin >> b >> h){
        //b*=10.0;  h*=10.0;
        double r, cir = 0.0, hant;
        double areat = b*h/2.0;
        double p = b + 2*(sqrt(h*h + b*b/4.0));
        r = areat*2.0/p;
        //printf("area %.5f\n", areat);
        //printf("perimetro %.5f\n", p);

        while(r >= eps){
            //printf("radio %.5f\n\n", r);
            cir += r*PI*2.0;
            hant = h;
            h -= 2.0*r;
            r /= hant/h;
            //printf("circ %.5f\n", (PI*r));
        }

        //cir = cir*PI*2.0;
        printf("%13.6f\n", cir);
        casos--;
        if(casos) printf("\n");
    }

    return 0;
}


