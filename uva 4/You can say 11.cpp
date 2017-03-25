#include <iostream>
#include <stdlib.h>
using namespace std;

long num;
string x;

void remove_spaces(string &s){ 
     size_t posicion; 
     while((posicion = s.find(' ')) != string::npos){ 
                     s.erase(posicion, 1);	
     } 
}

int main (){
    while (true){
          getline(cin, x);
          remove_spaces ( x );
          num = atol((x).c_str());
          if  (x.length()==0){
          }else{
                    if  (num==0){
                        break;
                    }
                    if(num % 11 == 0 && num > 0){
                           cout << x << " is a multiple of 11." << endl;
                    }else{
                          cout << x << " is not a multiple of 11." << endl;
                    }
          }
    }
    return 0;
}
