#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    int tc,n;
    string s,a,str[1005], key[1005];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(int j=0; j<n; j++){
			cin>>s;
			str[j] = s;
			a = "";
			for(int i=s.size()-1; i>=0; i--){
				if(!isspace(s[i])) a+=(s[i]);
			}
			sort(a.begin(), a.end());
			key[j] = a;

		}
		while(cin>>s){
			if(s == "END") break;
			else{
				a = "";
				for(int i=s.size()-1; i>=0; i--){
					if(!isspace(s[i])) a+=(s[i]);
				}
				sort(a.begin(), a.end());
				vector<string >ans;
				for(int i=0; i<n; i++){
                    if(key[i] == a)
                        ans.push_back(str[i]);
				}
				printf("Anagrams for: ");cout<<s<<endl;
				int len = ans.size();
				if(len == 0){
                    printf("No anagrams for: ");cout<<s<<endl;
				}
				else{
                    for(int i=0; i<len; i++){
                        printf("%3d",i+1);
                        cout<<") "<<ans[i]<<endl;
                    }
				}
			}
		}
		if(tc != 0) cout<<endl;
	}
    return 0;
}
