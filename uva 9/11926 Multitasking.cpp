#include <bits/stdc++.h>

using namespace std;
//1000001

bitset<1000001> bs, cero;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, y, x, z, lim = 1000001;
    while(scanf("%d %d", &n, &m), n || m){
        bool flag = true;
        bs.reset();
        string aux;

        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);

            if(!flag) continue;
            aux = "";
            aux.append(x, '0');
            aux.append(y - x, '1');
            aux.append((lim - (y - x)) - x, '0');
            //cout << aux << " lon: " << aux.size() << endl;
            bitset<1000001> task(aux);
            //cout << "t = " << task << endl;
            if((task&bs) != cero) flag = false;
            else bs |= task;
            //cout << "g = " << bs << endl;
        }


        int tam1, tam2, tam3;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);

            if(!flag) continue;
            aux = "";
            tam1 = y - x;
            tam2 = x;
            tam3 = z - (y - x);
            if(tam3 < 0){
                flag = false;
                continue;
            }

            if(aux.size() + tam2 > lim) aux.append((tam2 + aux.size()) - lim, '0');
            else aux.append(tam2, '0');

            while(1){
                //cout << "iteraccion , longitud: " << aux.size() << endl;
                if(aux.size() >= lim) break;

                if(aux.size() + tam1 > lim){
                    aux.append(lim - aux.size(), '1');
                    break;
                }else aux.append(tam1, '1');
                //cout << "     con unos longitud: " << aux.size() << endl;

                if(aux.size() + tam3 > lim){
                    aux.append(lim - aux.size(), '0');
                    break;
                }else aux.append(tam3, '0');
                //cout << "     con ceros longitud: " << aux.size() << endl;
            }
            //cout << " longitud final " << aux.size() << endl;
            //cout << aux << endl;
            bitset<1000001> task(aux);
            if((task&bs) != cero) flag = false;
            else bs |= task;
        }

        if(flag) printf("NO CONFLICT\n");
        else printf("CONFLICT\n");
    }

    return 0;
}
