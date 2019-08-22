#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
typedef pair<int,int> ii;

string cad1, cad2;
int memo[100][100];
ii padre[100][100];

int costo(char a, char b){return (a==b)? 0: 1;}

void imp(){
    for(int i = 0; i <= cad1.size(); ++i){//f
        for(int j = 0; j <= cad2.size(); ++j){//c
            printf("%3d", memo[i][j]);
        }
        printf("\n");
    }
}

int dp(){
    int ans;
    padre[0][0] = ii(0,0);
    for(int i = 0; i <= cad2.size(); ++i)
        padre[0][i+1] = ii(0,i), memo[0][i] = i;
    for(int i = 0; i <= cad1.size(); ++i)
        padre[i+1][0] = ii(i,0), memo[i][0] = i;
    //imp();  printf(".\n");

    for(int i = 0; i < cad1.size(); ++i){//f
        for(int j = 0; j < cad2.size(); ++j){//c
            ans = costo(cad1[i],cad2[j]) + memo[i][j];
            padre[i+1][j+1] = ii(i,j);
            if(costo(cad2[i],'_') + memo[i+1][j] < ans){
                ans = costo(cad2[i],'_') + memo[i+1][j];
                padre[i+1][j+1] = ii(i+1,j);
            }
            if(costo(cad1[i],'_') + memo[i][j+1] < ans){
                ans = costo(cad1[i],'_') + memo[i][j+1];
                padre[i+1][j+1] = ii(i,j+1);
            }
            memo[i+1][j+1] = ans;
        }
    }
    return memo[cad1.size()][cad2.size()];
}

int del, con, op;

void contOp(int f, int c){
    if(!f && !c) return;
    contOp(padre[f][c].first, padre[f][c].second);
    if(cad1[f-1]!=cad2[c-1] && f==padre[f][c].first+1 && c==padre[f][c].second+1)
        op++;
    if(c==padre[f][c].second && f==padre[f][c].first+1) op++;
    if(f==padre[f][c].first && c==padre[f][c].second+1) op++;
}

void ruta(int f, int c){
    if(f==0 && c==0) return;
    ruta(padre[f][c].first, padre[f][c].second);
    if(cad1[f-1]!=cad2[c-1] && f==padre[f][c].first+1 && c==padre[f][c].second+1){
        printf("%d Replace %d,%c\n", ++con,f-del,cad2[c-1]);
    }
    if(c==padre[f][c].second && f==padre[f][c].first+1){
        printf("%d Delete %d\n",++con,f-del);
        del++;
    }
    if(f==padre[f][c].first && c==padre[f][c].second+1){
        printf("%d Insert %d,%c\n", ++con,(f+1)-del,cad2[c-1]);
        del--;
    }
    //printf("(%d, %d)\n", f, c);
}

int main(){
    //freopen("salida.txt", "w", stdout);

    int n;
    getline(cin,cad1);  getline(cin,cad2);
    while(true){
        //printf("dp = %d\n", dp());
        dp();
        //imp();
        del = con = op = 0;
        contOp(cad1.size(),cad2.size());
        printf("%d\n", op);
        ruta(cad1.size(),cad2.size());
        if(getline(cin,cad1)) printf("\n");
        else break;
        getline(cin,cad2);
    }
}


