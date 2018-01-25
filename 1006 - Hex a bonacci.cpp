#include<bits/stdc++.h>
using namespace std;
long long int  ara[10001][6] = {0};
int a[6];
int main()
{
	for(int i=0; i<=5; i++){
		for(int j=0; j<=5; j++){
			if(i == j)
		 		 ara[i][j] = 1;
		    else
		    	ara[i][j] = 0;	
		}
	}
	for(int i=6; i<10001; i++){
		for(int j=0; j<=5; j++){
			for(int k=1; k<=6; k++){
				ara[i][j] = (ara[i][j] + ara[i-k][j]) % 10000007;
			}
		}
	}
	int n,tc;
	cin>>tc;
	for(int t=1; t<=tc; t++){
		for(int i=0; i<=5; i++)
				cin>>a[i];
		cin>>n;
		long long int ans = 0;
		for(int i=0; i<=5; i++){
			ans = (ans + (a[i]*ara[n][i]) % 10000007)% 10000007;
		}
		printf("Case %d: %lld\n",t,ans);
	}
	
 	return 0;
}

