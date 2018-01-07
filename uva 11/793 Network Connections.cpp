#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

struct union_find{
	vector<int> padre;
	vector<int> rango;

	void iniciar(int n){
	    padre.clear();
	    rango.clear();
		for (int i = 0; i < n; i++) {
			padre.push_back(i);
			rango.push_back(0);
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

		if(rango[x] > rango[y]){
			padre[y] = x;
			return;
		}

		padre[x] = y;
		if(rango[y] == rango[x]) rango[y]++;
	}

	bool MismoGrupo(int x, int y){
		return raiz(x) == raiz(y);
	}
};

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int casos, n, a, b;
    char cad[3];
    string s;
    union_find uf;
    scanf("%d", &casos);

    for(int i = 0; i < casos; i++){
        scanf("%d", &n);
        uf.iniciar(n + 1);
        int con1 = 0, con2 = 0, l;

        getchar();
        while(1){
            getline(cin, s);
            if(s.size() == 0) break;
            sscanf(s.c_str(), "%s %d %d", &cad, &a, &b);
            if(cad[0] == 'c'){
                //cout << "unimos " << a << " , " << b << endl;
                uf.unir(a, b);
            }else{
                if(uf.MismoGrupo(a, b)) con1++;
                else con2++;
            }
        }

        printf("%d,%d\n", con1, con2);
        if(i != casos - 1) printf("\n");
    }

    return 0;
}


