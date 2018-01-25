#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc; scanf("%d",&tc);
    char c;
    string s;
    while(tc--){
        cin>>s;
        int len = s.size();
        int ans = len;
        for(int j=1; j<=len && ans == len; j++){
            string str = "";
            if(len%j !=0 ) continue;
            for(int i=0; i<j; i++){
                c = s[i];
                str+=c;
            }
            //cout<<str<<endl;
            int count = 0;
            int a = len/j;
            for(int i=0; i<len; i+=j){
                size_t found = s.find(str,i);
                //cout<<i<<endl;
                if(found == i){
                    count++;
                    //cout<<"found: "<<i<<endl;
                }

                else
                    break;

            }
            if(count == a && count != 1)
                ans = j;
        }
        printf("%d\n",ans);
        if(tc!=0)
            printf("\n");
    }

    return 0;
}
