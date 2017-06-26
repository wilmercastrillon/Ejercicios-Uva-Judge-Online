#include <bits/stdc++.h>

using namespace std;

vector<int> sem;
int menor;

int solve(){
	int a[sem.size()], con;
	bool verde[sem.size()], cambio[sem.size()];
	memset(a, 0, sizeof(a));
	memset(verde, true, sizeof(verde));
	memset(cambio, false, sizeof(cambio));
	
	for(int i = 0; i < sem.size(); i++){
		if(sem[i] == menor){
			verde[i] = false;
			cambio[i] = true;
		}
		a[i] = menor - 5;
	}
	
	for(int i = menor - 5; i < 18001; i++){
		//printf("------------------------------------------------ i = %d\n", i);
		
		con = 0;
		for(int j = 0; j < sem.size(); j++) if (verde[j]) con++;
		if(con == sem.size()) return i;
		
		for(int j = 0; j < sem.size(); j++){
			//printf("semaforo %d ---------------------\n", sem[j]);
			a[j]++;
			
			//printf("pasa a segundo %d\n", a[j]);
			if(verde[j]){
				//printf("es verde\n");
				if(a[j] == sem[j] - 5){
					verde[j] = false;
					cambio[j] = true;
					//printf("cambia de verde\n");
				}
				
			}else{
				//printf("es rojo\n");
				if(a[j] == sem[j]){
					//printf("completa ciclo\n");
					a[j] = 0;
					if(!cambio[j]){
						verde[j] = true;
						//printf("pasa a verde\n");
					}
					cambio[j] = !cambio[j];
				}
			}
		}
	}
	
	return 1000000;
}

void imp(int q){
	if(q > 9)
		printf("%d:", q);
	else
		printf("0%d:", q);
}

int main(){
	freopen("salida.txt", "w", stdout);
	int n, salir = 0;
	
	while(salir != 3){
		salir++;
		menor = 1000;
		sem.clear();
		while(scanf("%d", &n), n){
			sem.push_back(n);
			menor = min(menor, n);
			salir = 0;
		}
		if(!sem.size()) continue;
		
		int hor = 0, min = 0, seg = 0, aux = solve();
		if(aux == 1000000){
			printf("Signals fail to synchronise in 5 hours\n");
			continue;
		}
		
		seg = aux % 60;
		min = (aux / 60) % 60;
		aux /= 60;
		hor = (aux / 60) % 60;
		
		imp(hor);
		imp(min);
		if(seg > 9)
			printf("%d\n", seg);
		else
			printf("0%d\n", seg);
	}
	
	return 0;
}
