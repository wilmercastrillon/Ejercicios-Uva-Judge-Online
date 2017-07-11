#include <bits/stdc++.h>

using namespace std;
int tab[700][700], con[700][700], fil, col, res[5];
int mf[] = {0, 1, 0, -1}, mc[] = {-1, 0, 1, 0};
char arr[700];

bool val(int pf, int pc){
	return (pf >= 0 && pf < fil && pc >= 0 && pc < col && !tab[pf][pc]);
}

void solve(){
	int posf = fil - 1, posc = 0, dir = 2, auxf, auxc, f2 = fil - 1, der;
	bool mov = false;
	//int con2 = 30;
	
	do{
		der = dir - 1;
		if(der < 0) der = 3;

		//cout << "esta en " << posf << " , " << posc << endl;
		auxf = posf + mf[der];
		auxc = posc + mc[der];
		
		if(val(auxf, auxc)){//verifica si hay pared a derecha
			posf = auxf;
			posc = auxc;
			dir = der;
			con[posf][posc]++;
			//cout << "gira a la derecha" << endl;
		}else{
			
			auxf = posf + mf[dir];
			auxc = posc + mc[dir];
			
			if(val(auxf, auxc)){//si puede continuar
				posf = auxf;
				posc = auxc;
				con[posf][posc]++;
				mov = true;
				//cout << "avanza" << endl;
			}else{//gira a la izquierda
				dir = (dir + 1) % 4;
				//cout << "gira a " << dir << endl;
			}
		}
		
		if(posf == f2 && posc == 0 && mov) break;
		//cout << "------------------" << endl;
	}while(true);
}

int main(){
	freopen("salida.txt", "w", stdout);
	while(scanf("%d %d", &fil, &col), fil || col){
		
		for(int i = 0; i < fil; i++){
			scanf("%s", &arr);
			for(int j = 0; j < col; j++) tab[i][j] = arr[j] - '0';
		}
		
		memset(con, 0, sizeof(con));
		memset(res, 0, sizeof(res));
		solve();
		
		for(int i = 0; i < fil; i++)
			for(int j = 0; j < col; j++)
				if(!tab[i][j])
					res[con[i][j]]++;
		
		/*for(int i = 0; i < fil; i++){
			for(int j = 0; j < col; j++) printf("%d", con[i][j]);
			printf("\n");
		}*/
		
		for(int i = 0; i < 5; i++) printf("%3d", res[i]);
		printf("\n");
	}
	
	return 0;
}
