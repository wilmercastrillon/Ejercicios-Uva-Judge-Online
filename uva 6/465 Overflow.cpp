#include <bits/stdc++.h>

using namespace std;

vector<string> pre;

struct biginteger{
	int tam;
    vector<short> num;
    
    void quitar_ceros_izquierda(){
		//imprimir();
		while(!num[tam-1] && tam > 0){
			//printf("pos = %d , num = %d\n", tam-1, num[tam-1]);
			num.pop_back();
			tam--;
		}
		
	}
    
    void iniciar(string c){
		tam = c.length();
		num.clear();
		for(int i = tam - 1; i > -1; i--) num.push_back(c[i] - '0');
		
		quitar_ceros_izquierda();
	}
	
	void iniciar(int c){
		num.clear();
		tam = 0;
		while(c > 0){
			num.push_back(c % 10);
			c /= 10;
			tam++;
		}
	}
	
	void imprimir(){
		for(int i = tam - 1; i > -1; i--) printf("%d", num[i]);
		printf("\n");
	}
	
	string tostring(){
		stringstream ss ("");
		for(int i = tam - 1; i > -1; i--) ss << num[i];
		return ss.str();
	}
	
	void suma(vector<short> b){
		int aux = 0, pos = b.size();
		
		for(int i = 0; i < pos; i++){
			if(i < tam){
				aux += num[i] + b[i];
				num[i] = aux % 10;
			}else{
				aux += b[i];
				num.push_back(aux % 10);
			}
			aux /= 10;
		}
		
		while(aux > 0){
			if(pos >= tam)
				num.push_back(aux % 10);
			else{
				aux += num[pos];
				num[pos++] = aux % 10;
			}
				
			aux /= 10;
		}
		
		tam = num.size();
	}
	
	void multiplicar(biginteger b){
		int l = b.num.size();
		vector<vector<short>>  vvs(l);
		
		for(int i = 0; i < l; i++){
			int aux = 0;
			for(int j = 0; j < i; j++) vvs[i].push_back(0);
			
			for(int j = 0; j < num.size(); j++){
				aux = aux + (b.num[i] * num[j]);
				vvs[i].push_back(aux % 10);
				aux /= 10;
			}
			
			while(aux > 0){
				vvs[i].push_back(aux % 10);
				aux /= 10;
			}
		}
		
		iniciar("0");
		for(int i = 0; i < l; i++) suma(vvs[i]);
		
		quitar_ceros_izquierda();
	}
	
	int comparar(biginteger b){//1 si es mayor, 0, igual, -1 menor
		if(b.tam > tam) return -1;
		
		if(tam > b.tam) return 1;
		
		for(int i = tam - 1; i > -1; i--){
			if(num[i] > b.num[i]) return 1;
			if(num[i] < b.num[i]) return -1;
		}
		
		return 0;
	}
};

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("salida.txt", "w", stdout);
	biginteger n, m;
	int num;
	n.iniciar(1);
	pre.push_back("1");
	
	for(int i = 1; i < 1001; i++){
		m.iniciar(i);
		n.multiplicar(m);
		pre.push_back(n.tostring());
	}
	
	while(scanf("%d", &num) != EOF){
		printf("%d!\n%s\n", num, pre[num].c_str());
	}
	
	/*
	*/
	return 0;
}


