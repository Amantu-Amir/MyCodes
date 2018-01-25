#include<bits/stdc++.h>
using namespace std;
vector<string>word;
map<string , int> used;
bool diff1(string a, string b)
{
    if(a.size() != b.size()) return false;
    int d = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            d++;
        }
    }
    if(d==1) return true;
    return false;
}
int bfs(string s, string t)
{
    used.clear();
    queue<string> q, q2;
    q.push(s);
    used[s] = 1;
    int ret = 0;
    if(s==t) return 0;
    while(!q.empty()){
        ret++;
        while(!q.empty()){
            string x = q.front();
            q.pop();
            for(int i=0; i<word.size(); i++){
                string y = word[i];
                if(used.find(y)==used.end() && diff1(x,y)){
                    if(y==t) return ret;
                    q2.push(y);
                    used[y] = 1;
                }
            }
        }
        q.swap(q2);
    }
    return ret;
}
int main()
{
    string s,t, in;int cs=1;
    int tc;cin>>tc;
    while(tc--){
        if(cs>1)
            cout<<endl;
        word.clear();
        while(cin>>s){
            if(s=="*") break;
            word.push_back(s);
        }
        getchar();
        while(getline(cin, in)){
            if(in.empty()) break;
            s = t = "";
            int i;
            for(i=0; in[i] != ' '; i++) s+=in[i];
            for(i++; i<in.size(); i++) t+=in[i];
            cout<<s<<" "<<t<<" "<<bfs(s,t)<<endl;
        }
        cs++;
    }

    return 0;
}
