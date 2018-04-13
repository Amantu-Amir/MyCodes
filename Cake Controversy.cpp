#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int tc,ck;
    double k,l,m,n;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        cin>>ck;
        if(ck==1){
            cin>>l>>m>>n;
            cout<<fixed<<setprecision(6)<<sqrt(l*l-m*m+n*n)<<endl;
        }
        else if(ck==2){
            cin>>k>>m>>n;
            cout<<fixed<<setprecision(6)<<sqrt(k*k-n*n+m*m)<<endl;
        }
        else if(ck==3){
            cin>>k>>l>>n;
            cout<<fixed<<setprecision(6)<<sqrt(l*l-k*k+n*n)<<endl;
        }
        else if(ck==4){
            cin>>k>>l>>m;
            cout<<fixed<<setprecision(6)<<sqrt(k*k-l*l+m*m)<<endl;
        }
        else{
            cout<<"fuck u"<<endl;
        }
    }
    return 0;
}
