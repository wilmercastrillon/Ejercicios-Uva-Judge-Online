#include <bits/stdc++.h>

using namespace std;

bool repetido(int n){
	bool digitos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	while(n > 0){
		if(digitos[n % 10])
			return false;
		else
			digitos[n % 10] = 1;
		n = n / 10;
	}
	return true;
}

int main(){
	
	int n1, n2, con;
	
	while(scanf("%d %d", &n1, &n2) != EOF){
		
		con = 0;
		for(int i = n1; i <= n2; i++)
			if(repetido(i))
				con++;
		
		printf("%d\n", con);
	}
	
	return 0;
}	
