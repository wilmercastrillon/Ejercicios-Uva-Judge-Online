#include <iostream>
using namespace std;

int main (){
    
    int casos;
    do{
          cin >> casos;
          if(casos == 0){
                   break;
          }
          int divisionx;
          int divisiony;
          int posx;
          int posy;
          cin >> divisionx;
          cin >> divisiony;
          for(int i = 0; i <casos; i++){
                  cin >> posx;
                  cin >> posy;
                      
                  if (posx == divisionx || posy == divisiony){
                           cout << "divisa" << endl;
                  }else{
                        if(posx > divisionx){
                             if(posy > divisiony){
                                     cout << "NE" << endl;
                             }else{
                                     cout << "SE" << endl;
                             }
                        }else{
                             if(posy > divisiony){
                                     cout << "NO" << endl;
                             }else{
                                     cout << "SO" << endl;
                             }
                        } 
                  }
          }
             
    }while(true);
    return 0;
}
