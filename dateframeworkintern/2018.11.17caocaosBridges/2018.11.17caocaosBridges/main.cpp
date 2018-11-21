#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge
{
    int v,next;
};
edge e[1000005];
int h[1005],cnt=0;
void addedge(int u,int v)
{
    cnt++;
    e[cnt].v=v;
    e[cnt].next=h[u];
    h[u]=cnt;
    cnt++;
    e[cnt].v=u;
    e[cnt].next=h[v];
    h[v]=cnt;
}
int dep[1005],sn[1005],dc=0;
int dfs(int u,int f){
    dc++;
    int lowu=dep[u]=dc;
    int c=0;
    for(int i=h[u];i;i=e[i].next)
    {
        int next=e[i].v;
        if(!dep[next])
        {
            c++;
            int lowv=dfs(next,u);
            lowu=min(lowu,lowv);
            if(lowv>=dep[u])
                sn[u]++;
        }
        else if(dep[next]<dep[u]&&next!=f)
            lowu=min(lowu,dep[next]);
    }
    if(f==-1)
        sn[u]=0;
    return lowu;
}
int main()
{
    int u,v,cas=0,n;
    while(scanf("%d",&u)==1&&u)
    {
        int root=0,flag=0;
        cnt=0;
        n=0;
        memset(h,0,sizeof(h));
        memset(dep,0,sizeof(dep));
        memset(sn,0,sizeof(sn));
        scanf("%d",&v);
        addedge(u,v);
        n=max(n,max(u,v));
        while(scanf("%d",&u)==1&&u)
        {
            scanf("%d",&v);
            addedge(u,v);
            n=max(n,max(u,v));
            root=u;
        }
        dfs(root,0);
        if(sn[root]!=0)
            sn[root]--;
        printf("Network #%d\n",++cas);
        for(int i=0;i<=n;i++)
        {
            if(sn[i])
            {
                printf("  SPF node %d leaves %d subnets\n",i,sn[i]+1);
                flag=1;
            }
        }
        if(!flag)
            printf("  No SPF nodes\n");
        printf("\n");
    }
    return 0;
}
