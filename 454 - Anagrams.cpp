
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    //cout<<"ff"<<endl;
    int tc;scanf("%d",&tc);getchar();
    getchar();
    string a,b;
    string str[105],key[105];
    while(tc--){
        int count = 0;
        while(getline(cin,a)){
            int len = a.size();
            if(len == 0) break;
            else
                str[count++] = a;
        }
        sort(str, str+count);
        for(int i=0; i<count; i++){
            b = "";
            for(int j=str[i].size()-1; j>=0; j--){
                if(!isspace(str[i][j]))
                    b+=(str[i][j]);
            }
            sort(b.begin(), b.end());
            key[i] = b;
        }
        for(int i=0; i<count-1; i++){
            for(int j=i+1; j<count; j++){
                if(key[i] == key[j])
                    cout<<str[i]<<" = "<<str[j]<<endl;
            }
        }


        if(tc != 0)
        cout<<endl;
    }
    return 0;
}

