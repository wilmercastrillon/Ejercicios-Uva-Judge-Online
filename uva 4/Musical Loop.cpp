#include <iostream>
using namespace std;

int main (){
    
    while (true){
    int t;
    int l;
    cin >> t;
    if (t == 0){
          break;
    }
    if(t < 2){
         cin >> l;
         cout << t-1 << endl;
    } else{
        int aux;
        int res = 0;
        int ini;
        bool subir = false;
    
        cin >> l;
        aux = l;
        cin >> l;
        if(aux > l){
             subir = true;
        }else{
        }
        bool subini = subir;
        res++;
        for (int i = 2; i < t; i++){
             aux = l;
             cin >> l;
             if (aux < l && subir == true){
                     subir = false;
                     res++;
             }else{
                if(aux > l && subir == false){
                       subir = true;
                       res++;
                }else{
                      if(aux > l){
                      }else{
                      }
                }
             }
        }
        if ((subini == true && subir == false) || (subini == false && subir == true)){
                 cout << res << endl;
        }else{
           cout << res+1 << endl;
        }
     }
     }
     return 0;
}
