#include <bits/stdc++.h>

using namespace std;

int arr[13];
bool pos[13];
string cad, cad2, cad3;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	char res;
	
	while(n--){
		memset(arr, 0, sizeof(arr));
		memset(pos, true, sizeof(pos));
		
		for(int j = 0; j < 3; j++){
			cin >> cad >> cad2 >> cad3;
			int l = cad.length(), l2 = cad2.length();
			
			if(cad3 == "even"){
				for(int i = 0; i < l; i++)
					pos[cad[i] - 'A'] = false;
				for(int i = 0; i < l2; i++)
					pos[cad2[i] - 'A'] = false;
				continue;
			}
			
			if(cad3 == "up"){
				for(int i = 0; i < l; i++)
					arr[cad[i] - 'A']++;
				for(int i = 0; i < l2; i++)
					arr[cad2[i] - 'A']--;
				continue;
			}
			
			if(cad3 == "down"){
				for(int i = 0; i < l; i++)
					arr[cad[i] - 'A']--;
				for(int i = 0; i < l2; i++)
					arr[cad2[i] - 'A']++;
				continue;
			}
		}
		
		int aux, may = 0;
		for(int i = 0; i < 12; i++){
			if((abs(arr[i]) > abs(may)) && pos[i]){
				may = arr[i];
				aux = i;
			}
		}
		
		res = aux + 'A';
		if(may > 0)
			cout << res << " is the counterfeit coin and it is heavy.\n";
		else
			cout << res << " is the counterfeit coin and it is light.\n";
	}
	
	return 0;
}
