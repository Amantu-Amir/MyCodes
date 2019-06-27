#include<bits/stdc++.h>
using namespace std;
struct Node
{
    bool isEnd;
    Node* next[27];
    Node()
    {
        isEnd = false;
        for(int i=0; i<27; i++) next[i] = NULL;
    }
}* root;
void add(string str)
{
    int len = str.size();
    Node* curr = root;
    for(int i=0; i<len; i++){
        int id = str[i] - 'a';
        if(curr->next[id]==NULL)
            curr->next[id] = new Node();
        curr = curr->next[id];
    }
    curr->isEnd = 1;
}
int calc(string str)
{
    int ret = 1;
    int len = str.size();
    Node* curr = root;
    for(int i=0; i<len; i++){
        int id = str[i] - 'a';
        curr = curr->next[id];
        if( i!= len-1){
            int cnt = -1;
            for(int j=0; j<27; j++)
                if(curr->next[j])
                    cnt++;
            //cout<<str<<" "<<str[i]<<" "<<cnt+1<<endl;
            if(cnt || curr->isEnd) ret++;
        }
    }
    //cout<<str<<" -- "<<ret<<endl;
    return ret;
}
void del(Node* curr)
{
    for(int i=0; i<27; i++){
        if(curr->next[i]!=NULL)
            del(curr->next[i]);
    }
    delete(curr);
}
string arr[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    while(cin>>n){
        root = new Node();
        for(int i=0; i<n; i++){
            cin>>arr[i];
            add(arr[i]);
        }
        int tot = 0;
        for(int i=0; i<n; i++) tot+=calc(arr[i]);
        del(root);
        cout<<fixed<<setprecision(2)<<(tot*1.0)/n<<endl;
    }
}

