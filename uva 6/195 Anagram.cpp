#include <bits/stdc++.h>

using namespace std;
char cad[1000];
map<char, int> mapa;

void llenar(){
	char c1 = 'A', c2 = 'a';
	int con = 0;
	for(int i = 0; i < 26; i++){
		mapa[c1++] = con++;
		mapa[c2++] = con++;
	}
}

bool cmp(char a, char b){
	return mapa[a] < mapa[b];
}

int main(){
	int n, l;
	llenar();
	scanf("%d", &n);
	
	while(n--){
		scanf("%s", &cad);
		l = strlen(cad);
		sort(cad,cad+l, cmp);
		
		do{
			printf("%s\n", cad);
		}while(next_permutation(cad, cad+l, cmp));
	}
	
	return 0;
}
