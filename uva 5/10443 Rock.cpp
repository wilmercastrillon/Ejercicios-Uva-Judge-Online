#include <bits/stdc++.h>

using namespace std;

int f, c, n;
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};
char tab[101][101];
char aux[101][101];
bool cambio[101][101];

char gana(char a, char b){
	if(a == b) return a;
	
	switch(a){
		case 'R':
			if(b == 'S') return a;
			return b;
		case 'S':
			if(b == 'P') return a;
			return b;
		case 'P':
			if(b == 'R') return a;
			return b;
	}
}

void turno(){
	int posf, posc;
	
	for(int i = 0; i < f; i++)
		for(int j = 0; j < c; j++){
			//printf("prueba %d %d esta %c\n", i, j, tab[i][j]);
			for(int k = 0; k < 4; k++){
				
				posf = i + mf[k];
				posc = j + mc[k];
				if(posf < 0 || posf == f || posc < 0 || posc == c)
					continue;
				
				/*printf("compara en %d %d antes %c\n", posf, posc, tab[posf][posc]);
				aux[posf][posc] = gana(tab[posf][posc], tab[i][j]);
				printf("ahora %c\n", aux[posf][posc]);*/
				
				char q = gana(tab[posf][posc], tab[i][j]);
				if(!cambio[posf][posc] && q != tab[posf][posc]){
					//printf("cambio en %d %d antes %c ahora %c\n", posf, posc, tab[posf][posc], q);
					aux[posf][posc] = q;
					cambio[posf][posc] = 1;
				}
			}
		}
		
	for(int i = 0; i < f; i++)
		for(int j = 0; j < c; j++)
			if(cambio[i][j])
				tab[i][j] = aux[i][j];
}

int main(){
	//freopen("salida.txt", "w", stdout);
	int casos;
	scanf("%d", &casos);
	
	while(casos--){
		scanf("%d %d %d", &f, &c, &n);
		
		for(int i = 0; i < f; i++){
			scanf("%s", &tab[i]);
		}
		
		while(n--){
			memset(cambio, 0, sizeof(cambio));
			turno();
		}
		
		for(int i = 0; i < f; i++)
			printf("%s\n", tab[i]);
			
		if(casos > 0) printf("\n");
	}
	
	return 0;
}


