#include<iostream>
#include<queue>
#include<cmath>
#include<stdio.h>

using namespace std;

double P[100][2];
int n;
double sum;

void dikjstra(){
    double ax,min;
    double dist[100];
    bool intree[100];

    for(int q = 0; q < 100; q++){
        intree[q] = 0;
    }

    for(int i=0;i<100;i++) dist[i]=1000000.0;

    int v=0;
    dist[0]=0;
    sum=0;

    while(!intree[v]){
        intree[v]=1;
        sum+=dist[v];
        cout << "v = " << v << endl;
        cout << "sum = " << sum << endl;
        cout << "dist1 = " << dist[v] << endl;

        for(int i=0;i<n;i++){
            if(!intree[i]){
                ax=sqrt(pow(P[v][0]-P[i][0],2)+pow(P[v][1]-P[i][1],2));
                if(ax<dist[i]) dist[i]=ax;
            }
        }

        v=0;
        min=1000000.0;

        for(int i=0;i<n;i++){
            if(!intree[i]){
                if(dist[i]<min){
                    v=i;
                    min=dist[i];
                }
            }
        }

    }

    printf("%.2f\n",sum);
}

int main(){

    int T;

    double a,b;

    cin>>T;

    for(int i=0;i<T;i++){
        cin>>n;

        for(int j=0;j<n;j++){
            cin>>a>>b;
            P[j][0]=a;
            P[j][1]=b;
        }

        dikjstra();
        if(i!=T-1) cout<<endl;
    }

    return 0;
}
