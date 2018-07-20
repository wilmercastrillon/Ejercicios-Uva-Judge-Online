#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef vector<int> vi;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;//peso, origen y destino
#define mpdii(a, b, c) dii(a, ii(b, c))

const int MAX = 1010;

struct union_find{
	int padre[MAX];
	int can;

	void iniciar(int n){
	    can = n;
		for(int i = 0; i < n; i++) padre[i] = i;
	}

    int raiz(int x){
        if(x == padre[x] ) return x;
        else return padre[x] = raiz(padre[x]);
    }

	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		if(x == y) return;
		can--;
		padre[x] = y;
	}

	bool MismoGrupo(int x, int y){
	    return raiz(x) == raiz(y);
	}
};

vector<dii> grafo;//lista de incidencia
union_find uf;
double r, acum1, acum2, eps = 1e-7;

double kruskal(vector<dii> &lista, int nodos){
	sort(lista.begin(), lista.end());
	uf.iniciar(nodos);
	acum1 = 0; acum2 = 0;
	int ejes = 0;

	for (int i = 0; i < lista.size(); i++) {
		if (!uf.MismoGrupo(lista[i].second.first,
                      lista[i].second.second)) {
			ejes++;
			//printf("unir %d %d con peso %lf\n", lista[i].second.first, lista[i].second.second, lista[i].first);
			uf.unir(lista[i].second.first, lista[i].second.second);
			//printf("acum = %lf, debe sumar %lf res %lf\n", acum, lista[i].first, acum + lista[i].first);
			if(r - lista[i].first >= eps) acum1 += lista[i].first;
			else acum2 += lista[i].first;
			//printf("acum = %lf\n");
			if(ejes == nodos-1) return acum1 + acum2;
		}
	}
	return -1;
}

int n;

int main(){
    int t;
    double x, y, aux;
    scanf("%d", &t);
    union_find estados;
    vector<dd> nodos;

    for(int i = 1; i <= t; i++){
        scanf("%d %lf", &n, &r);
        nodos.clear(); grafo.clear();
        estados.iniciar(n);

        for(int j = 0; j < n; j++){
            scanf("%lf %lf", &x, &y);
            for(int k = 0; k < nodos.size(); k++){
                aux = hypot(x-nodos[k].first, y-nodos[k].second);
                if(r - aux >= eps) estados.unir(j, k);
                grafo.push_back(mpdii(aux, j, k));
            }
            nodos.push_back(dd(x, y));
        }

        kruskal(grafo, nodos.size());
        printf("Case #%d: %d %.0f %.0f\n", i, estados.can, acum1, acum2);
    }

    return 0;
}


