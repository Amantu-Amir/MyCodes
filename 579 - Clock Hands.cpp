#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,m;
    double ang_h, ang_m,ang;
    while(scanf("%d%*c%d",&h,&m)){
        if(h==0 && m==0)
            break;
        ang_m = (6.0*(double)m);
        ang_h = (30.0 * ((double)h+((double)m/60.0)));
        ang = abs(ang_h-ang_m);
        ang = min(ang, 360.0-ang);
        cout<<fixed<<setprecision(3)<<ang<<endl;
    }
    return 0;
}
