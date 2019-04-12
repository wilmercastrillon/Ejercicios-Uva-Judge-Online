#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    int a, b, c, d, t, x, y;
    string str, ini;
    getline(cin, str);
    t = atoi(str.c_str());
    getline(cin, ini);
    bool salto = false;

    while(t--){
        if(salto) printf("\n");
        else salto = true;
        double res = 0.0;

        getline(cin, ini);
        istringstream aux(ini);
        aux >> x >> y;

        while(getline(cin, str) && str.size()){
            istringstream iss(str);
            iss >> a >> b >> c >> d;
            res += hypot(a-c, b-d);
        }
        res = ((res/1000.0)*2.0)/20.0;
        int h = (int) res;
        int m = (int) round((res - (h*1.0))*60.0);
        if(m == 60){
            m = 0;
            h++;
        }
        if(m >= 10) printf("%d:%d\n", h, m);
        else printf("%d:0%d\n", h, m);
    }

    return 0;
}




