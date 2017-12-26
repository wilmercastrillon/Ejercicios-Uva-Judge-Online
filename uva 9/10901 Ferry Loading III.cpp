#include <bits/stdc++.h>

using namespace std;
typedef pair<int, bool> ib;

int main(){
    //freopen("salida.txt", "w", stdout);
    int casos, n, t, m;
    scanf("%d", &casos);

    for(int i = 0; i < casos; i++){
        scanf("%d %d %d", &n, &t, &m);
        char cad[10];
        int aux;
        bool izq = true;
        vector<ib> v;

        for(int j = 0; j < m; j++){
            scanf("%d %s", &aux, &cad);
            v.push_back(ib(aux, cad[0] == 'l'));
        }

        int index = 0, tiempo = 0, coni = 0, cond = 0;
        int can = 0;

        vector<int> carros(m, 0);
        queue<int> colai, colad, barco;

        while(colai.size() || colad.size() || barco.size() || index < m){
            while(barco.size()){
                carros[barco.front()] = tiempo;
                barco.pop();
            }

            while(index < m){
                ib par = v[index];
                if(par.first <= tiempo){
                    //cout << "llega auto de tiempo: " << par.first << " en " << ((par.second)? "izq " : "der ") << endl;
                    if(par.second) colai.push(index);
                    else colad.push(index);
                    index++;
                }else break;
            }

            if(izq){
                while(barco.size() < n && colai.size()){
                    barco.push(colai.front());
                    colai.pop();
                }
            } else {
                while(barco.size() < n && colad.size()){
                    barco.push(colad.front());
                    colad.pop();
                }
            }

            if(!colai.size() && !colad.size() && !barco.size() && index < m){
                tiempo = v[index].first;
                //cout << "no hay nada, esperamos hasta " << tiempo << endl;
            }else{
                //cout << "nos vamos con " << can << endl;
                tiempo += t;
                izq = !izq;
            }
            //cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        }
        while(barco.size()){
            carros[barco.front()] = tiempo;
            barco.pop();
        }

        for(int j = 0; j < m; j++) printf("%d\n", carros[j]);

        if(i != casos - 1) printf("\n");
    }

    return 0;
}


