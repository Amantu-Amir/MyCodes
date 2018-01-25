#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void g()
{
    for(int i=2; i<=40000; i++){
        string s;
        int k = i*i;
        stringstream out;
        out<<k;
        s = out.str();
        string a,b;int x,y;
        bool flag = false;
        int len = s.size();
        for(int l=1; l<len; l++){
            a = "", b = "";
            int j;
            for(j=0; j<l; j++){
                a+=s[j];
            }
            for(j; j<len; j++){
                b+=s[j];
            }
            x = atoi(a.c_str());y = atoi(b.c_str());
            if(x+y == i && x!=0 && y!=0){
                flag =true;
                break;
            }
        }
        if(flag == true)
            v.push_back(i);

    }
}
int main()
{

    g();
    int tc,a,b;
    int sz = v.size();
    cin>>tc;
    for(int t=1; t<=tc; t++){
        cin>>a>>b;
        printf("case #%d\n",t);
        int print = 0;
        for(int k=0; k<sz; k++){
            if(v[k]>=a && v[k]<=b){
                print++;
                cout<<v[k]<<endl;
            }
            else if(v[k]>b)
                break;
        }
        if(print == 0)
            printf("no kaprekar numbers\n");
        if(t!=tc)
            cout<<endl;
    }
    return 0;
}
