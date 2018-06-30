#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

int mcd(int a, int b) {
    if (a % b == 0)
        return b;
        
    return mcd(b, a % b);
}

int main(){
	freopen("texto.txt", "w", stdout);
	int casos;
	char cad[10000];
	string tok;
	scanf("%d", &casos);
	getchar();
	
	while(casos--){
		gets(cad);
		stringstream ss (cad);
		vec.clear();
				
		while(ss >> tok){
			vec.push_back(atoi(tok.c_str()));
		}
		
		int maximo = 1;
		for(int i = 0; i < vec.size(); i++){
			for(int j = i + 1; j < vec.size(); j++){
				maximo = max(maximo, mcd(vec[i], vec[j]));
			}
		}
		printf("%d\n", maximo);
	}
	
	return 0;
}
