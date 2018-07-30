#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,t,a,b,lcm;
    while(cin>>n>>t, n|t){
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        vector<ll> lcm;
        for(int i1=0; i1<n; i1++){
            for(int i2=i1+1; i2<n; i2++){
                ll lc2 = arr[i1]*(arr[i2]/__gcd(arr[i1], arr[i2]));
                for(int i3 = i2+1; i3<n; i3++){
                    ll lc3 = arr[i3]*(lc2/(__gcd(lc2, arr[i3])));
                    for(int i4=i3+1; i4<n; i4++){
                        ll lc4 = arr[i4]*(lc3/(__gcd(lc3, arr[i4])));
                        lcm.push_back(lc4);
                    }
                }
            }
        }
        while(t--){
            cin>>a;
            int got = 0;
            for(int i=0; i<lcm.size() && got == 0; i++){
                if(a%lcm[i]==0){
                    cout<<a<<" "<<a<<endl;
                    got = 1;
                }
            }
            if(got) continue;
            ll ans1,ans2;
            ll diff1,diff2;
            diff1 = diff2 = 1000000000000000000LL;
            for(int i=0; i<lcm.size(); i++){
                ll x = a/lcm[i];
                ll tem1 = x*lcm[i];
                ll tem2 = (x+1)*lcm[i];
                if(a-tem1 < diff1){
                    diff1 = a-tem1;
                    ans1 = tem1;
                }
                if(tem2-a < diff2){
                    diff2 = tem2-a;
                    ans2 = tem2;
                }
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
    }
}
