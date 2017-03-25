#include <iostream>
#include <string.h>
using namespace std;
string subcadena(string x, int a, int b);


string respuesta(string x){
       string y = x.substr(0, 1);
       for(int i = 1; i < x.length(); i++){
               if(y == x.substr(i, 1)){
               }else{
                     return "No";
               }
       }
       return "Yes";
}

int main(){
    int con = 0;
    
    do{
       con++;
       string x;
       cin >> x;
       int t;
       cin >> t;
       int a;
       int b;
       cout << "Case " << con <<":"<<endl;
       for(int i = 0; i < t; i++){ 
               cin >> a;
               cin >> b;
               if(a > b){
                    int aux = a;
                    a = b;
                    b = aux;
               } 
               b++;
               string aux = subcadena(x, a , b);
               cout << respuesta(aux) << endl;
       }
    }while(true);
    return 0;
}

string subcadena(string x, int a, int b){
       return x.substr(a,(b-a));
}

