#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;int t= 1;
    vector<string> v;
    while(cin>>s){
        if(s == "9"){
            int len = v.size();
            bool f = true;
            for(int i=0; i<len; i++){
                for(int j=0; j<len; j++){
                    if(i == j)
                        continue;
                    size_t found = v[j].find(v[i]);
                    if(found != string::npos && found ==0){
                        f = false;
                        break;
                    }
                }
                if(!f)
                    break;
            }
            if(f)
                printf("Set %d is immediately decodable\n",t++);
            else
                printf("Set %d is not immediately decodable\n",t++);


            v.clear();
        }
        else
            v.push_back(s);
    }
}
