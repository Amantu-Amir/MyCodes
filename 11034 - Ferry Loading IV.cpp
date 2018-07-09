#include<bits/stdc++.h>
using namespace std;
#define ll long long
char str[9];
int main()
{
    int tc,q,a;
    int cap;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&cap, &q);
        cap*=100;
        int ans = 0;
        queue<int> left, right;
        while(q--){
            scanf("%d%s",&a,str);
            if(strcmp(str, "left")==0)
                left.push(a);
            else right.push(a);
        }
        bool turn = true;
        while( !left.empty() || !right.empty()){
            if(turn){
                int now = 0;
                while(!left.empty() ){
                    if((now + left.front()) <= cap){
                        now+=left.front();
                        left.pop();
                    }
                    else break;
                }
                ans++;
            }
            else{
                int now = 0;
                while(!right.empty() ){
                    if((now + right.front()) <= cap){
                        now+=right.front();
                        right.pop();
                    }
                    else break;
                }
                ans++;
            }
            turn^=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/**
4
20 4
380 left
720 left
1340 right
1040 left
15 4
380 left
720 left
1340 right
1040 left
15 4
380 left
720 left
1340 left
1040 left
15 4
380 right
720 right
1340 right
1040 right
* */
