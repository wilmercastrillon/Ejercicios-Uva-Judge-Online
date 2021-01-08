#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

struct cube{
    cube(int _x,int _y,int _z,int _d){
        x=_x;  y=_y;  z=_z;  d=_d;
    }
    int x, y, z, d;
};
vector<cube> cubes;

int main(){
    int n, xx, yy, zz, dd;
    while(cin >> n, n){
        cubes.clear();

        forr(i, n){
            cin>>xx>>yy>>zz>>dd;
            cubes.pb(cube(xx,yy,zz,dd));
        }

        int minx = -2000000000, miny = -2000000000, minz = -2000000000;
        int maxx = 2000000000, maxy = 2000000000, maxz = 2000000000;
        forr(i, cubes.size()){
            minx = max(minx, cubes[i].x);
            miny = max(miny, cubes[i].y);
            minz = max(minz, cubes[i].z);
            maxx = min(maxx, cubes[i].x + cubes[i].d);
            maxy = min(maxy, cubes[i].y + cubes[i].d);
            maxz = min(maxz, cubes[i].z + cubes[i].d);
        }
        int area = (maxx-minx)*(maxy-miny)*(maxz-minz);
        if(maxx < minx || maxy < miny || maxz < minz)
            area = 0;
        printf("%d\n", area);
    }

    return 0;
}


