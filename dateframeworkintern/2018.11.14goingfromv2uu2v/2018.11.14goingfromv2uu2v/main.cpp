#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
int now=0;
int sum=0;
vector<vector<int> > gr;
vector<vector<int>> nows;
stack<int> stk;
int dfs[1050]={};
int low[1050]={};
bool vis[1050]={};
int pit[1050]={};
int indeg[1050]={};
void targin(int num)
{
    vis[num]=1;
    dfs[num]=low[num]=++now;
    stk.push(num);
    for(int i=0;i<gr[num].size();++i)
    {
        int tmp=gr[num][i];
        if(!low[tmp])
        {
            targin(tmp);
            low[num]=min(low[num],low[tmp]);
        }
        else if(vis[tmp]==1)
            low[num]=min(low[num],dfs[tmp]);
    }
    if(low[num]==dfs[num]){
        ++sum;
        while(!stk.empty())
        {
            int tmp=stk.top();
            stk.pop();
            vis[tmp]=0;
            pit[tmp]=sum;
            if(tmp==num)
                break;
        }
    }
}
bool ok()
{
    queue<int> stc;
    int cnt=0;
    for(int i=1;i<=sum;++i)
    {
        if(indeg[i]==0)
        {
            indeg[i]=-1;
            stc.push(i);
            cnt++;
        }
    }
    if(cnt>1)
        return 0;
    while(!stc.empty())
    {
        int cur=stc.front();
        stc.pop();
        cnt=0;
        for(int i=0;i<nows[cur].size();++i)
        {
            int v=nows[cur][i];
            indeg[v]--;
            if(!indeg[nows[cur][i]])
            {
                indeg[v]=-1;
                stc.push(nows[cur][i]);
                cnt++;
            }
        }
        if(cnt>1)
            return 0;
    }
    return 1;
}
void init(){
    now=0;
    sum=0;
    cin>>N>>M;
    memset(dfs,0,sizeof(dfs));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    memset(pit,0,sizeof(pit));
    memset(indeg,0,sizeof(indeg));
    gr.clear();
    gr.resize(N+2);
    nows.clear();
    nows.resize(N+2);
    for(int i=0;i<M;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        gr[a].push_back(b);
    }
}
void solve(){
    for(int i=1;i<=N;++i)
    {
        if(!low[i])
            targin(i);
    }
    for(int i=1;i<=N;++i)
    {
        for(int j=0;j<gr[i].size();++j)
        {
            int v=gr[i][j];
            if(pit[i]!=pit[gr[i][j]])
            {
                nows[pit[i]].push_back(pit[v]);
                ++indeg[pit[v]];
            }
        }
    }
    if(!ok())
        printf("NO\n");
    else
        printf("YES\n");
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        init();
        solve();
    }
    return 0;
}

