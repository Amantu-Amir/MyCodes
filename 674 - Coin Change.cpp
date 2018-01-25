#include<bits/stdc++.h>
using namespace std;
int coin[5] = {50,25,10,5,1};
int make = 7490;
int dp[5][7490];
int func(int i,int amount)
{
	if(i>=5){
		if(amount == 0) return 1;
		else return 0;
	}
	if(dp[i][amount] != -1) return dp[i][amount];
	int ret1=0,ret2=0;
	if(amount-coin[i]>=0) ret1 = func(i,amount-coin[i]);
	ret2 = func(i+1, amount);
	dp[i][amount] = ret1+ret2;
	return ret1+ret2;
}
int main()
{
	//freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	while(cin>>make){
		cout<<func(0,make)<<endl;
	}
 	return 0;
}

