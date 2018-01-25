#include<bits/stdc++.h>
using namespace std;
int main()
{
    string output;
    string s;char c;int a;
    while(getline(cin,s)){
        int len = s.size();
        output = "";
        if(isalpha(s[0]) || ispunct(s[0])){
            for(int i=0; i<len; i++){
                a = s[i];
                stringstream out;
                out<<a;
                string x = out.str();
                output+=x;
            }
            reverse(output.begin(),output.end());
        }
        else{
            for(int i=len-1; i>=0; i--){
                if(s[i] == '1'){
                    a = 1;
                    a = a*100 + (s[i-1]-'0')*10 + (s[i-2]-'0');
                    c = a;
                    i-=2;
                }
                else{
                    a = (s[i]-'0')*10 + (s[i-1]-'0');
                    c = a;
                    i-=1;
                }
                output += c;
            }
        }
        cout<<output<<endl;
    }
    return 0;
}
