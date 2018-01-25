#include<bits/stdc++.h>
using namespace std;
int arr[102], dp[102][50004];
int n, total;
const int inf = 1111111;
int fun(int pos, int sum)
{
    if(sum<0) return inf;
    if(pos==n){
        int tem = total-sum;
        return abs(sum-tem);
    }
    if(dp[pos][sum] != -1) return dp[pos][sum];
    int ret1 = fun(pos+1, sum);
    int ret2 = fun(pos+1, sum+arr[pos]);
    return dp[pos][sum] = min(ret1, ret2);
}
int main()
{
    int cs;
    cin>>cs;
    while(cs--){
        cin>>n;
        total = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            total +=arr[i];
        }
        memset(dp, -1, sizeof dp);
        cout<<fun(0,0)<<endl;
    }
    return 0;
}
