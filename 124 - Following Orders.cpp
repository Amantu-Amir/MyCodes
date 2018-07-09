#include<bits/stdc++.h>
using namespace std;
vector<char> input;
map<char, vector<char> >mp;
int in[300] = {0};
int taken[300] = {0};
void rec(int len, string str)
{
    //cout<<len<<" "<<str<<endl;
    if(len==input.size()){
        if(str.size()==len) cout<<str<<endl;
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
    int cs=0;
    while(cin>>c){
        if(cs>0) cout<<endl;
        input.push_back(c);
        while(ch = getchar()){
            if(ch=='\n') break;
            else if(isalpha(ch))
                input.push_back(ch);
        }
        sort(input.begin(), input.end());
        while(cin>>c>>ch){
            mp[ c ].push_back(ch);
            in[ch]++;
            ch = getchar();
            if(ch=='\n') break;
        }
        rec(0,"");
        mp.clear();
        input.clear();
        memset(in, 0, sizeof in);
        memset(taken, 0, sizeof taken);
        cs++;
    }
    return 0;
}
//a  b  f  g
//a  b  b  f
//v  w  x  y  z
//v  y  x  v  z  v  w  v
