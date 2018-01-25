#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k,n||k){
		long long int res = 1;
		if(k>n-k) k = n-k;
		for(int i=0; i<k; i++){
			res*=(n-i);
			res/=(i+1);
		}
		cout<<res<<endl;
	}
	
	return 0;
}

