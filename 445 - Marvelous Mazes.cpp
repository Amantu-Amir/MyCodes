#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    vector<string> v;
    string s;int ct = 0;
    while(getline(cin,s)){
        if(!s.empty())
            v.push_back(s);
        else{
            if(ct > 0)
                cout<<endl;
            ct++;
            int n = v.size();
            for(int j=0; j<n; j++){
                s = v[j];
                int len = s.size();
                int count = 0;
                for(int i=0; i<len ;i++){
                    if(s[i] == 'b'){
                        for(int k=0; k<count; k++)
                            cout<<" ";
                        count = 0;
                    }
                    else if(s[i] == '!'){
                        cout<<endl;
                    }
                    else if(isdigit(s[i])){
                        while(isdigit(s[i])){
                            count = count + s[i]-'0';
                            i++;
                        }
                        if(count>0)
                            i--;
                    }
                    else{
                        for(int k=0; k<count; k++)
                            cout<<s[i];
                        count = 0;
                    }
                }
                cout<<endl;
            }
            v.clear();
        }
    }
    ///
    if(ct > 0)
                cout<<endl;
            ct++;
            int n = v.size();
            for(int j=0; j<n; j++){
                s = v[j];
                int len = s.size();
                int count = 0;
                for(int i=0; i<len ;i++){
                    if(s[i] == 'b'){
                        for(int k=0; k<count; k++)
                            cout<<" ";
                        count = 0;
                    }
                    else if(s[i] == '!'){
                        cout<<endl;
                    }
                    else if(isdigit(s[i])){
                        while(isdigit(s[i])){
                            count = count + s[i]-'0';
                            i++;
                        }
                        if(count>0)
                            i--;
                    }
                    else{
                        for(int k=0; k<count; k++)
                            cout<<s[i];
                        count = 0;
                    }
                }
                cout<<endl;
            }
                ///
    return 0;
}

