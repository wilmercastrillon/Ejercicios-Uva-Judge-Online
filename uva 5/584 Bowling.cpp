#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> turnos;

int main(){
	char cad[100];
	
	while(1){
		gets(cad);
		if(cad[0] == 'G') break;

		stringstream juego ((string) cad);
		string tok;
		turnos.clear();
		
		while(juego >> tok){
			int q, w;
			
			if(tok[0] == 'X'){
				q = w = 10;
				turnos.push_back(pair<int, int>(q, w));
				continue;
			}
			
			q = tok[0] - '0';
			juego >> tok;
			if(tok[0] == '/')
				w = 10;
			else
				w = q + (tok[0] - '0');
				
			turnos.push_back(pair<int, int>(q, w));
		}
		
		int con = 0, aux;
		for(int i = 0; i < 10; i++){
			aux = 0;
			
			if(turnos[i].first == 10) {
				if(turnos[i + 1].first == 10){
					aux = 10 + turnos[i + 2].first;
				}else
					aux += turnos[i + 1].second;
			}else{
				if(turnos[i].second == 10) aux = turnos[i + 1].first;
			}
			
			con += turnos[i].second + aux;
			//printf("con pareja %d %d aumenta %d\n", turnos[i].first, turnos[i].second, aux + turnos[i].second);
		}
		
		printf("%d\n", con);
	}

	return 0;
}
