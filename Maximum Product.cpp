#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v1,v2;
pair<ll, string > dp[22][2][2][2];
int vis[22][2][2][2] = {0};
pair<ll, string > fun(int pos=0, int isLarge=0, int isSmall=0, int isStart=0)
{
	if(pos==v1.size()) return {1,""};
	if(vis[pos][isLarge][isSmall][isStart])
		return dp[pos][isLarge][isSmall][isStart];
	pair<ll, string > ret, tem;
	ret = {-1,""};
    int low = 0, high = 9;
    if(isLarge==0) low = v1[pos];
    if(isSmall==0) high = v2[pos];
	for(int i=low; i<=high; i++){
        tem = fun(pos+1, isLarge|(i>low), isSmall|(i<high), isStart|(i>0));

        string st = "";
        st+=(i+'0');
        tem.second = st + tem.second;
        if(i==0 && isStart==0);
        else{
            tem.first*=i;
        }
        if(tem.first>ret.first){
            //cout<<tem.first<< " "<<ret.first<<endl;
            ret = tem;
        }

	}
	vis[pos][isLarge][isSmall][isStart] = 1;
	dp[pos][isLarge][isSmall][isStart] = ret;
	return ret;
}
int main()
{
	ll a,b;
	cin>>a>>b;

	for(int i=1; i<=20; i++){
		v1.push_back(a%10);
		a/=10;
	}
	reverse(v1.begin(), v1.end());

	for(int i=1; i<=20; i++){
		v2.push_back(b%10);
		b/=10;
	}
	reverse(v2.begin(), v2.end());

	pair<ll, string> ans = fun();
	string str = ans.second;
	for(int i=0; str[i]=='0'; i++){
        str[i]='*';
	}
	for(int i=0; i<str.size(); i++){
        if(str[i]!='*') cout<<str[i];
	}
	cout<<endl;
	return 0;
}
