#include<bits/stdc++.h>
using namespace std;
bool comp(char a,char b)
{
    if(a>b) return true;
    return false;
}
long int Sort(long int a, int f)
{
    stringstream out;
    out<<a;
    string s = out.str();
    if(f==1)
        sort(s.begin(),s.end(),comp);
    else
        sort(s.begin(),s.end());
    stringstream ss(s);
    long int x;
    ss >> x;
    return x;
}

int main()
{
    freopen("out.txt","w",stdout);
    long int num,a,b;
    while(cin>>num,num){
        int count = 0;
        set<long int>s;
        int s1,s2;
        printf("Original number was %ld\n",num);
        a = Sort(num,0);
        b = Sort(num,1);
        long int now= b-a;
        printf("%ld - %ld = %ld\n",b,a,now);count++;
        s.insert(now);
        num = now;
        while(true){
            a = Sort(num,0);
            b = Sort(num,1);
            now = b-a;
            printf("%ld - %ld = %ld\n",b,a,now);count++;
            s1 = s.size();
            s.insert(now);
            s2 = s.size();
            if(s1 == s2)
                break;
            num = now;
        }
        printf("Chain length %d\n\n",count);
    }
    return 0;
}
