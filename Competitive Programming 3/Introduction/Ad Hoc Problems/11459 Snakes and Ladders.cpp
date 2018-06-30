#include <bits/stdc++.h>

using namespace std;

int jug, esc, turnos, tab[101], pos[1000000];
vector<pair<int, int>> atajos;

int snake_leader(int n, int index){
	pair<int, int> par = atajos[index];
	if(par.first == n)
		return par.second;
	
	return n;
}

int main(){
	
	int casos;
	scanf("%d", &casos);
	
	while(casos--){
		scanf("%d %d %d", &jug, &esc, &turnos);
		memset(tab, 0, sizeof(tab));
		memset(pos, 0, sizeof(pos));
		atajos.clear();
		
		for(int i = 1; i <= esc; i++){
			int a1, a2;
			scanf("%d %d", &a1, &a2);
			atajos.push_back(pair<int, int>(a1, a2));
			tab[a1] = i;
			tab[a2] = i;
		}
		
		int aux, aux2, mod;
		bool seguir = (jug != 0);
		for(int i = 0; i < turnos; i++){
			scanf("%d", &aux);
			if(!seguir) continue;
			
			mod = i % jug;
			if(!pos[mod]) pos[mod] = 1;
			aux2 = pos[mod] + aux;
			if(aux2 > 100) aux2 = 100;
			
			if(tab[aux2]){
				pos[mod] = snake_leader(aux2, tab[aux2] - 1);
				//printf("tiene alguna cosa la pos %d queda en: %d\n", aux2, pos[mod]);
			}else{
				pos[mod] += aux;
				//printf("se guarda %d\n", pos[mod]);
			}
			if(pos[mod] >= 100){
				 pos[mod] = 100;
				 //printf("llega a cien se ignora\n");
				 seguir = false;
			 }
		}
		
		for(int i = 0; i < jug; i++){
			if(!pos[i]) pos[i] = 1;
			printf("Position of player %d is %d.\n", i + 1, pos[i]);
		}
	}
	
	return 0;
}
