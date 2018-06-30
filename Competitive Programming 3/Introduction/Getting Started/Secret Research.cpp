#include <iostream>
#include <string.h>
using namespace std;

int main (){
    
    int t;
    cin >> t;
    string c;
    for (int i = 0; i < t; i++){
        cin >> c;
        
        if(c == "1" || c == "4"  || c == "78" ){
             cout << "+"<< endl;
        }else{
              if(c.substr(c.length()-2, 2) == "35"){
                                        cout << "-"<< endl;
              } else{
                     if(c.substr(0, 1) == "9" && c.substr(c.length()-1, 1) == "4"){
                                    cout << "*"<< endl;
                     }else{
                           cout << "?"<< endl;
                     }
              }
        }
    }
    system("pause");
    return 0;
}
