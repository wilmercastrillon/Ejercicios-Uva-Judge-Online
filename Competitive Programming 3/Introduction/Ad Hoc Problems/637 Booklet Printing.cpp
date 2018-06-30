#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream> 

using namespace std;

struct pag{
	int first;
	int second;
};

vector<pag> vec;
int n, can, mul;

void solve(){
	int l = mul / 2, con = 1, pos = 0;
	n++;
	
	for(int i = 0; i < l; i++){
		pag p;
		if(con == n){
			//cout << "pagina " << i << " se pone -1" << endl;
			p.first = -1;
		}else{
			//cout << "pagina " << i << " se pone " << con << endl;
			p.first = con++;
		}
		vec.push_back(p);
	}
	
	pos = l - 1;
	for(int i = l; i < mul; i++){
		if(con == n){
			//cout << "pagina " << pos << " se pone -1" << endl;
			vec[pos--].second = -1;
		}else{
			//cout << "pagina " << pos << " se pone " << con << endl;
			vec[pos--].second = con++;
		}
	}
}

string out(int q, string s2, int pos, bool orden){
	stringstream ss;
	ss << "Sheet ";
	ss << q;
	ss << ", ";
	ss << s2;
	
	if(orden){
		if(vec[pos].first == -1)
			ss << "Blank, ";
		else{
			ss << vec[pos].first;
			ss << ", ";
		}
		if(vec[pos].second == -1)
			ss << "Blank";
		else
			ss << vec[pos].second;
	}else{
		if(vec[pos].second == -1)
			ss << "Blank, ";
		else{
			ss << vec[pos].second;
			ss << ", ";
		}
		if(vec[pos].first == -1)
			ss << "Blank";
		else{
			ss << vec[pos].first;
		}
	}
	ss << "\n";
	return ss.str();
}

int main(){
	freopen("salida.txt", "w", stdout);
	while(scanf("%d", &n), n){
		vec.clear();
		can = n / 4;
		if(can*4 != n){
			mul = (can+1) * 4;
			can += 4;
		}else{
			mul = n;
		}
		can = mul >> 1;
		//cout << "n = " << n << " multiplo " << mul << " can pag " << can << endl;
		
		printf("Printing order for %d pages:\n", n);
		solve();
		int num;
		stringstream salida;
		
		for(int i = 0; i < can; i++){
			num = (i >> 1) + 1;
			if(i&1){
				if(vec[i].first == -1 && vec[i].second == -1) continue;
				salida << out(num, "back : ", i, true);
			}else{
				if(vec[i].first == -1 && vec[i].second == -1) continue;
				salida << out(num, "front: ", i, false);
			}
		}
		printf("%s", salida.str().c_str());
	}
	
	return 0;
}
