#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int casos, n1, n2, valor;
	char letra;
	scanf("%d", &casos);
	map<char, int> mapa;
	
	while(casos--){
		
		mapa.clear();
		scanf("%d", &n1);
		while(n1--){
			cin >> letra >> valor;
			mapa[letra] = valor;
		}
		
		string cad;
		char cad2[1000];
		scanf("%d", &n2);
		double acum = 0;
		
		getchar();
		while(n2--){
			gets(cad2);
			cad = (string) cad2;
			for(int i = 0; i < cad.length(); i++){
				acum += mapa[cad[i]];
			}
		}
		
		acum /= 100;
		printf("%.2f$\n", acum);
	}
	
	return 0;
}



