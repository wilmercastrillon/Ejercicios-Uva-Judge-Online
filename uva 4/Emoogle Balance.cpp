#include<iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int res(string x);

int main(){
    int casos;
    cin >> casos;
    string cadena;
    
    for(int i = 0; i < casos; i++){
            cin >> cadena;
            if(cadena.length() == 5){
                               cout << 3 << endl;
            }else{
                  cout << res(cadena) << endl;
            }
    }
    return 0;
}

int res(string x){
    int con = 0;
    string z = "one";
    for(int j = 0; j < 3; j++){
            if(x.substr(j, 1) == z.substr(j, 1)){
                           con++;
            }
    }
    if(con > 1){
           return 1;
    }else{
          return 2;
    }
}
