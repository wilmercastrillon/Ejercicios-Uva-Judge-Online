#include <bits/stdc++.h>

using namespace std;
char cad[1000];

bool cmp(char a, char b){
	if(a < 'a') a += 32;
	if(b < 'a') b += 32;
	return a < b;
}

int main(){
	int n, l;
	scanf("%d", &n);
	
	while(n--){
		scanf("%s", &cad);
		l = strlen(cad);
		sort(cad,cad+l, cmp);
		
		while(next_permutation(cad, cad+l, cmp)){
			printf("%s\n", cad);
		}
	}
	
	return 0;
}
