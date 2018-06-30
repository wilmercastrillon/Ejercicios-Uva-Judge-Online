#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

char tab[61][61];
string abc[27][5];

void llenar(){
abc[0][0] = ".***.."; abc[1][0] = "****.."; abc[2][0] = ".****."; 
abc[0][1] = "*...*."; abc[1][1] = "*...*."; abc[2][1] = "*...*."; 
abc[0][2] = "*****."; abc[1][2] = "****.."; abc[2][2] = "*....."; 
abc[0][3] = "*...*."; abc[1][3] = "*...*."; abc[2][3] = "*....."; 
abc[0][4] = "*...*."; abc[1][4] = "****.."; abc[2][4] = ".****."; 

abc[3][0] = "****.."; abc[4][0] = "*****."; abc[5][0] = "*****."; 
abc[3][1] = "*...*."; abc[4][1] = "*....."; abc[5][1] = "*....."; 
abc[3][2] = "*...*."; abc[4][2] = "***..."; abc[5][2] = "***..."; 
abc[3][3] = "*...*."; abc[4][3] = "*....."; abc[5][3] = "*....."; 
abc[3][4] = "****.."; abc[4][4] = "*****."; abc[5][4] = "*....."; 

abc[6][0] = ".****."; abc[7][0] = "*...*."; abc[8][0] = "*****."; 
abc[6][1] = "*....."; abc[7][1] = "*...*."; abc[8][1] = "..*..."; 
abc[6][2] = "*..**."; abc[7][2] = "*****."; abc[8][2] = "..*..."; 
abc[6][3] = "*...*."; abc[7][3] = "*...*."; abc[8][3] = "..*..."; 
abc[6][4] = ".***.."; abc[7][4] = "*...*."; abc[8][4] = "*****."; 


abc[9][0] = "..***."; abc[10][0] = "*...*."; abc[11][0] = "*....."; 
abc[9][1] = "...*.."; abc[10][1] = "*..*.."; abc[11][1] = "*....."; 
abc[9][2] = "...*.."; abc[10][2] = "***..."; abc[11][2] = "*....."; 
abc[9][3] = "*..*.."; abc[10][3] = "*..*.."; abc[11][3] = "*....."; 
abc[9][4] = ".**..."; abc[10][4] = "*...*."; abc[11][4] = "*****."; 

abc[12][0] = "*...*."; abc[13][0] = "*...*."; abc[14][0] = ".***.."; 
abc[12][1] = "**.**."; abc[13][1] = "**..*."; abc[14][1] = "*...*."; 
abc[12][2] = "*.*.*."; abc[13][2] = "*.*.*."; abc[14][2] = "*...*."; 
abc[12][3] = "*...*."; abc[13][3] = "*..**."; abc[14][3] = "*...*."; 
abc[12][4] = "*...*."; abc[13][4] = "*...*."; abc[14][4] = ".***.."; 

abc[15][0] = "****.."; abc[16][0] = ".***.."; abc[17][0] = "****.."; 
abc[15][1] = "*...*."; abc[16][1] = "*...*."; abc[17][1] = "*...*."; 
abc[15][2] = "****.."; abc[16][2] = "*...*."; abc[17][2] = "****.."; 
abc[15][3] = "*....."; abc[16][3] = "*..**."; abc[17][3] = "*..*.."; 
abc[15][4] = "*....."; abc[16][4] = ".****."; abc[17][4] = "*...*.";

abc[18][0] = ".****."; abc[19][0] = "*****."; abc[20][0] = "*...*."; 
abc[18][1] = "*....."; abc[19][1] = "*.*.*."; abc[20][1] = "*...*."; 
abc[18][2] = ".***.."; abc[19][2] = "..*..."; abc[20][2] = "*...*."; 
abc[18][3] = "....*."; abc[19][3] = "..*..."; abc[20][3] = "*...*."; 
abc[18][4] = "****.."; abc[19][4] = ".***.."; abc[20][4] = ".***.."; 

abc[21][0] = "*...*."; abc[22][0] = "*...*."; abc[23][0] = "*...*."; 
abc[21][1] = "*...*."; abc[22][1] = "*...*."; abc[23][1] = ".*.*.."; 
abc[21][2] = ".*.*.."; abc[22][2] = "*.*.*."; abc[23][2] = "..*..."; 
abc[21][3] = ".*.*.."; abc[22][3] = "**.**."; abc[23][3] = ".*.*.."; 
abc[21][4] = "..*..."; abc[22][4] = "*...*."; abc[23][4] = "*...*."; 

abc[24][0] = "*...*."; abc[25][0] = "*****."; abc[26][0] = "......"; 
abc[24][1] = ".*.*.."; abc[25][1] = "...*.."; abc[26][1] = "......"; 
abc[24][2] = "..*..."; abc[25][2] = "..*..."; abc[26][2] = "......"; 
abc[24][3] = "..*..."; abc[25][3] = ".*...."; abc[26][3] = "......"; 
abc[24][4] = "..*..."; abc[25][4] = "*****."; abc[26][4] = "......"; 
}

void mostrar(){
	for(int i = 0; i < 60; i++){
		for(int j = 0; j < 60; j++)
			printf("%c", tab[i][j]);
		printf("\n");
	}
}

void write(string h, int q, int w, string fuente){
	for(int i = 0; i < h.length(); i++){
		if(q > 59 || w < 0 || w > 59 || h[i] == ' ' || (h[i] == '.' && fuente == "C5")){// 
			w++;
			continue;//con 20
		}
		
			tab[q][w++] = h[i];
	}
}

void c2(string h, int q, int w){
	for(int k = 0; k < h.length(); k++){
		int aux = h[k] - 'A';
		if(h[k] == ' ') aux = 26;
		
		for(int l = 0; l < 5; l++){
			write(abc[aux][l], q + l, w, "C5");
		}
		w += 6;
	}
}

string buscar(string b){
	for(int i = 0; i < b.length(); i++)
		if(b[i] == '|') return b.substr(i);
	return b;
}

int main(){
	freopen("entrada.txt", "r", stdin);
	freopen("salida.txt", "w", stdout);
	int h;
	string cad;
	llenar();
	bool next;
	
	while(1){
		next = true;
		memset(tab, '.', sizeof(tab));
	while(getline(cin, cad)){
		next = false;
		stringstream ss(cad);
		string aux, cadena = "", formato;
		int posf, posc;
		
		ss >> aux;
		if(aux == ".P"){
			ss >> formato;
			ss >> aux;
			posf = atoi(aux.c_str()) - 1;
			ss >> aux;
			posc = atoi(aux.c_str()) - 1;
			
			cadena = buscar(ss.str());
			
			if(formato == "C1")
				write(cadena.substr(1, cadena.length() - 2), posf, posc, "C1");
			else
				c2(cadena.substr(1, cadena.length() - 2), posf, posc);
			continue;
		}
		
		if(aux == ".L"){
			ss >> formato;
			ss >> aux;
			posf = atoi(aux.c_str()) - 1;
			
			cadena = buscar(ss.str());
			
			if(formato == "C1")
				write(cadena.substr(1, cadena.length() - 2), posf, 0, "C1");
			else
				c2(cadena.substr(1, cadena.length() - 2), posf, 0);
			continue;
		}
		
		if(aux == ".R"){
			ss >> formato;
			ss >> aux;
			posf = atoi(aux.c_str()) - 1;
			
			cadena = buscar(ss.str());
			
			cadena = cadena.substr(1, cadena.length() - 2);
			if(formato == "C1")
				write(cadena, posf, 60 - cadena.length(), "C1");
			else{
				int qqq = cadena.length() * 6;
				c2(cadena, posf, 60 - qqq);
			}
			continue;
		}
		
		if(aux == ".C"){
			ss >> formato;
			ss >> aux;
			posf = atoi(aux.c_str()) - 1;
			
			cadena = buscar(ss.str());
			cadena = cadena.substr(1, cadena.length() - 2);
			
			if(formato == "C1")
				write(cadena, posf, ((60 - cadena.length()) / 2) + (cadena.length() % 2), "C1");
			else{
				int qqq = cadena.length() * 6;
				qqq = 60 - qqq;
				c2(cadena, posf, qqq / 2);// con el numero 20
			}
			continue;
		}
		
		if(aux == ".EOP"){
			mostrar();
			printf("\n------------------------------------------------------------\n\n");
			break;
		}
	}
	
	if(next) break;
	
	}
	return 0;
}
