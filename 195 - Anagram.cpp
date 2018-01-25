
#include<bits/stdc++.h>
using namespace std;
map<char,int>Map;
void makeMap()
{
    int counter  = 1;
    for(int i=0; i<=26; i++){
        Map['A'+i] = ++counter;
        Map['a'+i] = ++counter;
    }
}
bool comp(char a, char b)
{
    return Map[a]<Map[b];
}
int main()
{
    makeMap();
    int n;string s;
    cin>>n;
    for(int t=1; t<=n; t++){
        cin>>s;
        sort(s.begin(), s.end(), comp);
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(), s.end(), comp));

    }
    return 0;
}
