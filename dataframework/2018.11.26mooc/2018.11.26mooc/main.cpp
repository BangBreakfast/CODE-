#include <iostream>
#include <map>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
map<string,int> f1;
map<int,string> f2;
int lenth[35][35]={};
int p;
bool vis[35]={};
int maxn=INF;
string output;
void dfs(int n1,int n2,int cnt,string s)
{
    if(n1==n2)
    {
        if(cnt<maxn)
        {
            maxn=cnt;
            output=s;
        }
        return;
    }
    for(int i=0;i<p;i++)
    {
        if(!vis[i]&&lenth[n1][i])
        {
            vis[i]=1;
            dfs(i,n2,cnt+lenth[n1][i],s+char(i));
            vis[i]=0;
        }
    }
}
int main()
{
    cin>>p;
    for(int i=0;i<p;i++)
    {
        string s;
        cin>>s;
        f1.insert(make_pair(s, i));
        f2.insert(make_pair(i, s));
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s1,s2;
        int num;
        cin>>s1>>s2>>num;
        lenth[f1[s1]][f1[s2]]=num;
        lenth[f1[s2]][f1[s1]]=num;
    }
    int r;
    cin>>r;

    while(r--)
    {
        
        string s1,s2;
        cin>>s1>>s2;
        string s;
        memset(vis, 0, sizeof(vis));
        s+=char(f1[s1]);
        maxn=INF;
        vis[f1[s1]]=1;
        dfs(f1[s1],f1[s2],0,s);
        cout<<f2[int(output[0])];
        for(int i=1;i<int(output.size());++i)
        {
            cout<<"->("<<lenth[int(output[i-1])][int(output[i])]<<")->"<<f2[int(output[i])];
        }
        cout<<endl;
    }
    return 0;
}
