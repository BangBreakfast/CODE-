#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int st[55][15]={};
int ed[55][15]={};
int wt[55]={};
int p,n;
int edge[115][115]={};
int back_edge[115][115]={};
int l[115]={};
bool ok(int a,int b)
{
    for(int i=1;i<=p;++i)
    {
        if(!(ed[a][i]==st[b][i]||st[b][i]==2))
            return 0;
    }
    return 1;
}
bool bfs(int st,int ed)
{
    memset(l,0,sizeof(l));
    l[st]=1;
    queue<int> q;
    q.push(st);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(cur==ed)
            return 1;
        for(int i=0;i<=ed;++i)
        {
            if(edge[cur][i]&&!l[i])
            {
                l[i]=l[cur]+1;
                q.push(i);
            }
        }
    }
    return 0;
}
int dfs(int st,int ed,int mx)
{
    if(!mx)
        return mx;
    if(st==ed)
        return mx;
    int sf=0;
    for(int i=0;i<=ed;i++)
    {
        int f=edge[st][i];
        if(edge[st][i]!=0&&l[st]+1==l[i])
        {
            f=min(mx-sf,f);
            f=dfs(i,ed,f);
            edge[st][i]-=f;
            edge[i][st]+=f;
            sf+=f;
            if(sf==mx)
                break;
        }
    }
    if(sf==0)
        l[st]=0;
    return sf;
}
int dinic(int start,int end)
{
    int ans=0;
    while(bfs(start,end))
    {
        ans+=dfs(start,end,INF);
    }
    return ans;
}

int main() {
    scanf("%d %d",&p,&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&wt[i]);
        for(int j=1;j<=p;++j)
        {
            scanf("%d",&st[i][j]);
        }
        for(int j=1;j<=p;++j)
        {
            scanf("%d",&ed[i][j]);
        }
    }
    for(int i=1;i<=p;++i)
    {
        st[0][i]=0;ed[0][i]=0;;
        st[n+1][i]=1;ed[n+1][i]=1;
    }
    wt[0]=INF;wt[n+1]=INF;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        if(i==j)
            edge[j+n+1][i]=wt[i];
        else if(ok(i,j))
            edge[i][j+n+1]=INF;
    }
    memcpy(back_edge, edge, sizeof(edge));
    
    int mfl=dinic(0,2*n+2);
    int ans=0;
    int output_1[155]={};
    int output_2[155]={};
    int output_3[155]={};
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i!=j)
            {
                if(back_edge[i][j+n+1]>edge[i][j+n+1])
                {
                    output_1[ans]=i;
                    output_2[ans]=j;
                    output_3[ans]=back_edge[i][j+n+1]-edge[i][j+n+1];
                    ans++;
                }
            }
        }
    }
    printf("%d %d\n",mfl,ans);
    for(int i=0;i<ans;++i)
    {
        printf("%d %d %d\n",output_1[i],output_2[i],output_3[i]);
    }
    return 0;
}
