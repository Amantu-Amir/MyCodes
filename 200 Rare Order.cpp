#include<bits/stdc++.h>
using namespace std;
char str[10005][22], s[22];

int main()
{
    while(cin>>s){
        int r = 1;
        memset(str, 0, sizeof str);
        strcpy(str[r], s);
        while(cin>>s){
            if(s[0]=='#')
                break;
            ++r;
            strcpy(str[r], s);
        }
        string ans;
        map<char , int> mp;
        for(int i=0; i<=21; i++){
            for(int j=1; j<=r; j++){
                if(isalpha(str[j][i]) && mp[str[j][i]]==0){
                    mp[str[j][i]]++;
                    ans+=(str[j][i]);
                }
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
