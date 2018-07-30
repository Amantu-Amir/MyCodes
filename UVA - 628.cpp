#include<bits/stdc++.h>
using namespace std;
int xxx;
void print(string str, int star)
{
    if(star==0){
        cout<<str<<endl;
        return;
    }
    for(int i=0; i<xxx; i++){
        if(str[i]=='*'){
            for(char j='0'; j<='9'; j++){
                str[i] = j;
                print(str, star-1);
            }
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    string str, rule;
    while(cin>>n){
        vector<string> v;
        for(int i=0; i<n; i++){
            cin>>str;
            v.push_back(str);
        }
        cin>>m;
        for(int i=1; i<=m; i++){
            cout<<"--"<<endl;
            cin>>rule;
            int sz = rule.size();
            for(int j=0; j<n; j++){
                str = "";
                int star = 0;
                for(int k=0; k<sz; k++){
                    if(rule[k]=='#')
                        str+=v[j];
                    else{
                        str+="*";
                        star++;
                    }
                }
                xxx = str.size();
                print(str,star);
            }
        }

    }
}

