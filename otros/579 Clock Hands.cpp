#include <bits/stdc++.h>

using namespace std;

int main(){
    int casos, h, m, minTotal;
    double angHoras, angMinutos;
    char cad[10];
    string str;

    while(scanf("%s", &cad) != EOF){
        str = (string) cad;
        replace(str.begin(), str.end(), ':',' ');
        //cout << str << endl;
        istringstream ss(str);

        ss >> h;
        ss >> m;
        if(!h && !m) break;
        //printf("leyo %d %d\n", h, m);
        if(h == 12) h = 0;//caso especial

        minTotal = (h*60) + m;//cantidad total de minutos trasncurridos desde la 12:00
        angHoras = (double) (360*minTotal)/(12*60);//angulo de las horas con respecto a las 12:00
        angMinutos = (double) 360*(m/60.0);//angulo de los minutos con respecto a las 12:00

        //cout << angHoras << " " << angMinutos << endl;
        printf("%.3f\n", min(abs(angHoras-angMinutos), 360-abs(angHoras-angMinutos)));//obtener los dos posible angulos
    }

    return 0;
}


