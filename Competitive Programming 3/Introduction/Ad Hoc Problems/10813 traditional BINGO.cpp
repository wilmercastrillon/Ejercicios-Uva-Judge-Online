#include <bits/stdc++.h>

using namespace std;

int bingo[6][6];

void marcar(int n){
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(bingo[i][j] == n){
				bingo[i][j] = -1;
				return;
			}
}

bool gana(){
	bool a, b;
	
	for(int i = 0; i < 5; i++){
		a = b = 1;
		for(int j = 0; j < 5; j++){
			a = a && (bingo[i][j] == -1);
			b = b && (bingo[j][i] == -1);
		}
		if(a || b) return 1;
	}
	
	a = b = 1;
	int aux = 4;
	for(int i = 0; i < 5; i++){
		a = a && (bingo[i][i] == -1);
		b = b && (bingo[i][aux--] == -1);
	}
		
	return a || b;
}

int main(){
	//freopen("salida.txt", "w", stdout);
	int casos, carta, turno;
	scanf("%d", &casos);
	bool gano;
	
	while(casos--){
		gano = 0;
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; j++)
				if(i == 2 && j == 2)
					bingo[i][j] = -1;
				else
					scanf("%d", &bingo[i][j]);
		
		for(int j = 0; j < 75; j++){
			scanf("%d", &carta);
			if(!gano){
				marcar(carta);
				if(gana()){
					 gano = 1;
					 turno = j + 1;
				 }
			}
		}
		
		printf("BINGO after %d numbers announced\n", turno);
	}
	
	return 0;
}


