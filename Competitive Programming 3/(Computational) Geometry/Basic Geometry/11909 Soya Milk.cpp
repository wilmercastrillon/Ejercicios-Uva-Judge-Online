#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
const double PI = acos(-1.0);

double DEG_TO_RAD(double n){ return n*PI/180.0; }

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    double l, w, h, t, t2, volaux, op;

    while(cin >> l >> w >> h >> t){
        t2 = DEG_TO_RAD(90.0-t);
        t = DEG_TO_RAD(t);
        op = tan(t)*l;
        double vol = l*w*h;
        if(op < h){
            volaux = vol - (w*l*op/2.0);
            //printf("volTotal %.5f, volmenos %.5f| area t %.5f\n", vol, volaux, l*op/2.0);
            printf("%.3f mL\n", volaux);
        }else{
            op = tan(t2)*h;
            volaux = w*h*op*0.5;
            //printf("volT %.5f| area t %.5f | w: %.5f\n", w*h*op*0.5, h*op*0.5, w);
            printf("%.3f mL\n", volaux);
        }
    }

    return 0;
}


