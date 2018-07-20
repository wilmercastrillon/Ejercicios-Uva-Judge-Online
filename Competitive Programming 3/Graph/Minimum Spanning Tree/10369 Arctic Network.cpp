#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct union_find{
	int padre[300000];
	int comp;

	void iniciar(int n){
	    comp = n;
		for (int i = 0; i < n; i++) padre[i] = i;
	}

	int raiz(int x){
		if(padre[x] == x) return x;
		return raiz(padre[x]);
	}

	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		if(x == y) return;
		comp--;
		padre[x] = y;
	}

	bool MismoGrupo(int x, int y){
		return raiz(x) == raiz(y);
	}
};

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<double, ii> piii;//peso, origen y destino
#define mpiii(a, b, c) piii(a, ii(b, c))
//insertar: grafo.push_back(mpiii(7, 0, 1))

vector<piii> grafo;//lista de incidencia
union_find uf;

double kruskal(vector<piii> lista, int comp){
	sort(lista.begin(), lista.end());
	uf.iniciar(lista.size() + 1);
	int ejes = 0, n = comp;
	double may = 0;
	if(ejes >= n) return 0;

	for (int i = 0; i < lista.size(); i++) {
		if (!uf.MismoGrupo(lista[i].second.first,
                      lista[i].second.second)) {
			ejes++;
			uf.unir(lista[i].second.first, lista[i].second.second);
			may = max(may, lista[i].first);
			if(ejes >= n) return may;
		}
	}
	//printf("ejes = %d , n = %d, may = %.2f ", ejes, n, may);
	return -1;
}

int s, m;

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int t;
    double x, y;
    scanf("%d", &t);
    vector<dd> puntos;

    while(t--){
        grafo.clear(); puntos.clear();
        scanf("%d %d", &s, &m);
        for(int i = 0; i < m; i++){
            scanf("%lf %lf", &x, &y);
            for(int j = 0; j < puntos.size(); j++){
                grafo.push_back(mpiii(hypot(x-puntos[j].first, y-puntos[j].second), i, j));
                //printf("lista de incidencia %lf, %d, %d\n", hypot(x-puntos[j].first, y-puntos[j].second), i, j);
            }
            puntos.push_back(dd(x, y));
        }

        if(s == 0) s = 1;
        printf("%.2f\n", kruskal(grafo, puntos.size() - s));
    }

    return 0;
}


