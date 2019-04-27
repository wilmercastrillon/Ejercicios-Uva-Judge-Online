#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define forr(i, n) for(int i = 0; i < n; ++i)

using namespace std;
typedef unsigned long long int ulli;
typedef pair<short, short> ss;
typedef pair<ulli, char> uc;

vector<char> sol;
ulli mask = 15, tabmask;
ss target[18], to2d[18];
short mf[4]={-1, 0, 1, 0}, mc[4]={0, 1, 0, -1}, to1d[4][4], lim;
char mov[4] = {'U','R','D','L'};

struct nodo{//hh, mask, pos, paso
    short hh, pos, paso;
    short gh;
    ulli tab;

    nodo(){}
    nodo(short _hh, short _pos, short _paso, ulli _tab){
        hh = _hh;
        pos = _pos;
        paso = _paso;
        tab = _tab;
        gh = _hh-_paso;
    }

    bool operator < (const nodo &otro) const{
        //return hh < otro.hh;
        return gh < otro.gh;
    }
};

void llenar(){
    short con = 0;
    forr(i, 4) forr(j, 4){
        to2d[con] = ss(i, j);
        to1d[i][j] = con;
        target[++con] = ss(i, j);
    }
    target[0] = ss(3, 3);//indice-donde debe estar
}

short get_num(ulli tab, short pos){
    return (tab>>(pos*4LL))&mask;
}

short h(ulli tab){
    short acum = 0, pos = 0, num;
    ss actual, obj;
    forr(i, 4) forr(j, 4){//ubicacion actual
        num = get_num(tab, pos);//numero en la ubicaion actual
        obj = target[num];//donde deberia estar
        acum += abs(i-obj.first) + abs(j-obj.second);
        pos++;
    }
    return -acum;
}

bool val(short f, short c){
    return !(f<0 || f>3 || c<0 || c>3);
}

ulli cambio(short pos1, short pos2, ulli tab){
    ulli aux = -1, res = tab;
    ulli fff = get_num(tab, pos1);
    ulli ccc = get_num(tab, pos2);
    res &= (aux^(mask<<pos1*4));
    res &= (aux^(mask<<pos2*4));
    res |= (fff<<pos2*4);
    res |= (ccc<<pos1*4);
    return res;
}

void imp(ulli tab){
    for(int i = 0; i < 16; i++){
        int f = to2d[i].first;
        int c = to2d[i].second;
        printf("en (%d, %d) -> %d\n", f, c, (int) get_num(tab, i));
    }
}

map<ulli, short> dis;
map<ulli, uc> padre;

void camino(ulli n){//imprimir el camino
    uc aux = padre[n];
    //printf("|%c|", aux.second);
    //printf("llegamos a :\n");
    //imp(aux.first);
    if(aux.first == 0) printf("%c", aux.second);
    else{
        camino(aux.first);
        printf("%c", aux.second);
    }
}

void dijkstra(short pos){//hh, pos, paso, tab
    priority_queue<nodo> cola;
    cola.push(nodo(h(tabmask), pos, 0, tabmask));
    dis[tabmask] = -1;
    padre[tabmask] = uc(0LL, '.');
    ss actual;
    ulli next;
    short auxf, auxc, peso;

    while(cola.size()){
        nodo n = cola.top();  cola.pop();
        //printf("llega a paso %d\n", (int) n.paso);
        //imp(n.tab);
        if(n.hh == 0){
            printf("|%c|", padre[n.tab].second);
            camino(n.tab);
            printf("\ntermino con %d pasos\n",(int) n.paso);
            return;
        }
        if(n.paso+((-n.hh)>>1) > lim){
            continue;
        }
        actual = to2d[n.pos];

        for(int i = 0; i < 4; i++){
            auxf = actual.first + mf[i];
            auxc = actual.second + mc[i];
            if(!val(auxf, auxc)) continue;

            next = cambio(to1d[auxf][auxc], to1d[actual.first][actual.second], n.tab);
            peso = dis[next];
            if(peso == 0 || peso > n.paso+1){
                dis[next] = n.paso+1;
                cola.push(nodo(h(next), to1d[auxf][auxc], n.paso+1, next));
                padre[next] = uc(n.tab, mov[i]);
            }
        }
    }

}

int main(){//No terminado
    llenar();

    int t, n, f, c;
    scanf("%d", &t);

    while(t--){
        dis.clear();
        padre.clear();
        tabmask = 0;
        ulli pos = 0;

        forr(i, 4){
            forr(j, 4){
                scanf("%d", &n);
                //tab[i][j] = n;
                tabmask |= (ulli) n<<(pos*4);
                pos++;
                if(n == 0){
                    f = i;
                    c = j;
                }
            }
        }

        //ulli q = cambio(3, 7, tabmask);
        //imp(q);
        int ini = (-h(tabmask))+13, q = 50;
        //lim = min(q, ini);
        lim = 49;
        printf("con lim %d\n", lim);
        dijkstra(to1d[f][c]);
        printf("termina con %d estados\n", dis.size());
    }

    return 0;
}


