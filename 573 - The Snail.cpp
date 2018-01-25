#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    double h,u,d,f;
    while(cin>>h>>u>>d>>f){
        if(h == 0) break;
        f = (f/100.0)*u;
       // cout<<"f = "<<f<<endl;;
        int count = 0;
        double climbed = 0;
        while(climbed<=h){
            if(climbed<0){
                break;
            }
            if(u < 0){
                climbed-=d;
            }
            else{
                climbed+=u;
                if(climbed<=h)
                    climbed-=d;
                //climbed = climbed + u - d;
            }
            //cout<<"climbed: "<<climbed<<endl;
            u-=f;
            count++;
        }
        if(climbed<=0)
            printf("failure on day %d\n",count);
        else
            printf("success on day %d\n",count);
    }

    return 0;
}
