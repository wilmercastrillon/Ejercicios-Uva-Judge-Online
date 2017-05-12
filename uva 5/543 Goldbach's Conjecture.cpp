#include <bits/stdc++.h>

using namespace std;

int p[1000010];
vector<int> primos;
int res[1000010][2];

void pre_primos(){
	for(int i = 2; i < 1000010; i++){
		if(!p[i]){
			primos.push_back(i);
			for(int j = i + i; j < 1000010; j += i){
				p[j] = 1;
			}
		}
	}
}

void llenar(int i){
	int suma, n2 = 0;
	
	do{
		suma = i - primos[n2];
		if(!p[suma]){
			if(i == primos[n2]){
				res[i][1] = primos[n2];
				res[i][0] = suma;
			}else{
				res[i][0] = primos[n2];
				res[i][1] = suma;
			}
			return;
		}
		n2++;
	}while(suma > -1);
}

int main(){
	//freopen("salida.txt", "w", stdout);
	memset(p, 0, sizeof(p));
	pre_primos();
	int n;
	
	while(scanf("%d", &n) && n){
		
		if(!res[n][1])
			llenar(n);
			
		if(res[n][1])
			printf("%d = %d + %d\n", n, res[n][0], res[n][1]);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
	
	return 0;
}





