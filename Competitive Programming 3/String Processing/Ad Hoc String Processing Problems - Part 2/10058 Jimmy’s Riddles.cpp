#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    string VERB = "(hate|love|know|like)s*";
    string NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
    string ARTICLE = "(a|the)";
    string ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")";
    string ACTIVE_LIST = "(" + ACTOR + " and )*(" + ACTOR + ")";
    string ACTION = "(" + ACTIVE_LIST + " " + VERB + " " + ACTIVE_LIST + ")";
    string STATEMENT = "(" + ACTION + " , )*(" + ACTION + ")";
    string cad;

    while(getline(cin, cad)){
        regex re(STATEMENT);

        if(regex_match(cad,re)){
            printf("YES I WILL\n");
        }else{
            printf("NO I WON'T\n");
        }
    }

    return 0;
}


