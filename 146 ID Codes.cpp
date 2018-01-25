#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s){
        if(s == "#") return 0;
        bool f = true;
        while(next_permutation(s.begin(),s.end())){
            cout<<s<<endl;
            f = false;
            break;
        }
        if(f)
            printf("No Successor\n");
    }
    return 0;
}
