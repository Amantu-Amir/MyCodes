#include<bits/stdc++.h>
using namespace std;
vector<char> input;
map<char, vector<char> >mp;
int in[300] = {0};
int taken[300] = {0};
int ans;
void rec(int len, string str)
{
    if(len==input.size()){
        if(str.size()==len){
            ans++;
            for(int i=0; i<(len-1); i++)
                cout<<str[i]<<" ";
            cout<<str[len-1]<<endl;
        }
        return;
    }
    for(int i=0; i<input.size(); i++){
        if(in[ input[i] ]!=0 || taken[ input[i] ]!=0) continue;
        for(int j=0; j<mp[ input[i] ].size(); j++){
            in[ mp[input[i]][j] ]--;
        }
        taken[ input[i] ] ++;
        rec(len+1, str + input[i]);
        for(int j=0; j<mp[ input[i] ].size(); j++){
            in[ mp[input[i]][j] ]++;
        }
        taken[ input[i] ] --;
    }
    return;
}
int main()
{
    char c,ch;
    int cs=0,tc,x;
    cin>>tc;
    while(tc--){
        if(cs>0) cout<<endl;
        while(ch = getchar()){
            if(ch=='\n'){
                if(input.size()>0) break;
                else continue;
            }
            else if(isalpha(ch))
                input.push_back(ch);
        }
        sort(input.begin(), input.end());
        //cout<<input.size()<<endl;
        string str;
        while(cin>>str){
            mp[ str[0] ].push_back(str[2]);
            //cout<<str[0]<<" - "<<str[2]<<endl;
            in[ str[2] ]++;
            ch = getchar();
            if(ch=='\n') break;
        }
        ans = 0;
        rec(0,"");
        if(ans==0) cout<<"NO"<<endl;
        mp.clear();
        input.clear();
        memset(in, 0, sizeof in);
        memset(taken, 0, sizeof taken);
        cs++;
    }
    return 0;
}
