#include <bits/stdc++.h>

using namespace std;

struct union_find{
	vector<int> padre;
	vector<int> tam;

	void iniciar(int n){
	    padre.clear(); tam.assign(n, 1);
		for (int i = 0; i < n; i++) {
			padre.push_back(i);
		}
	}

    int raiz(int x){
        if(x == padre[x] ) return x;
        else return padre[x] = raiz(padre[x]);
    }

	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		if(x == y) return;

		if(tam[x] > tam[y]){
			padre[y] = x;
			tam[x] += tam[y];
			tam[y] = 0;
			return;
		}

		padre[x] = y;
        tam[y] += tam[x];
		tam[x] = 0;
	}

	bool MismoGrupo(int x, int y){
		return raiz(x) == raiz(y);
	}
};

int main(){
    //freopen("salida.txt", "w", stdout);
    int casos, m;
    scanf("%d", &casos);
    string s1, s2;

    while(casos--){
        scanf("%d", &m);
        map<string, int> mapa;
        int con = 0;
        union_find uf;
        uf.iniciar(100001);

        for(int i = 0; i < m; i++){
            cin >> s1 >> s2;
            if(!mapa.count(s1)) mapa[s1] = con++;
            if(!mapa.count(s2)) mapa[s2] = con++;
            uf.unir(mapa[s1], mapa[s2]);
            printf("%d\n", uf.tam[uf.raiz(mapa[s1])]);
        }
    }

    return 0;
}


