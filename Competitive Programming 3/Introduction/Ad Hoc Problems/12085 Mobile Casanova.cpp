#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
vector<string> vec;

string quitar_ceros(string h){
	while(h[0] == '0') h.erase(h.begin());
	return h;
}

string res(string q, string w){
	for(int i = 0; i < q.length(); i++){
		if(q[i] != w[i]) return w.substr(i);
	}
	return "";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, casos = 0;
	unsigned long long int m, ant;
	string cad, prim, ant2;
	
	while(cin >> n, n){
		
		int con = 0, num, ant;
		vec.clear();
		cin >> cad;
		ant = atoi(quitar_ceros(cad).c_str());
		prim = cad;
		ant2 = cad;
		for(int i = 1; i < n; i++){
			cin >> cad;
			num = atoi(quitar_ceros(cad).c_str());
			ant++;
			
			if (ant == num){
				con++;
			}else{
				if(con){
					stringstream ss;
					ss << prim;
					ss << "-";
					ss << res(prim, ant2);
					vec.push_back(ss.str());
				}else
					vec.push_back(prim);
					
				prim = cad;
				con = 0;
				ant = num;
			}
			ant2 = cad;
		}

		if(n > 1){
			if(con){
				stringstream ss;
				ss << prim;
				ss << "-";
				ss << res(prim, cad);
				vec.push_back(ss.str());
			}else
				vec.push_back(prim);
		}else{
			vec.push_back(cad);
		}
		
		cout << "Case " << ++casos << ":\n";
		for(int i = 0; i < vec.size(); i++) cout << vec[i] << "\n";
		cout << "\n";
	}
	
	return 0;
}
