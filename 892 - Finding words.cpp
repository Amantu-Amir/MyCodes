#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool hypen = false;
    string str,s;
    vector<string>v;
    while(getline(cin,str)){
        if(str == "#")
            break;
        else{
            s = "";
            int len = str.size();
            for(int i=0; i<len; i++){
                if(!ispunct(str[i]) && !isdigit(str[i]))
                    s+=str[i];
            }
            if(str[len-1] == '-')
                s+=str[len-1];
            v.push_back(s);
        }
    }
    int n = v.size();
    s = "";
    for(int i=0; i<n; i++){
        str = v[i];
        int len = str.size();
        int a = 0,b = 0;
        if(!s.empty()){
            cout<<s;
            for(int j=0; j<len && isalpha(str[j]); j++){
                cout<<str[j];
                b++;
            }
            cout<<endl;
            s = "";
        }
        if(str[len-1] == '-'){
            a++;
            for(int j=len-2; j>=0 && isalpha(str[j]); j--){
                s+=str[j];
                a++;
            }
            reverse(s.begin(),s.end());
        }
        for(b ; b<len-a; b++){
            cout<<str[b];
        }

        cout<<endl;
    }
    return 0;
}
