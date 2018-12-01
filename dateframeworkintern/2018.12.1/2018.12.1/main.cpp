#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int K,C,M;
int dist[330][330];
int map[330][330];
bool vis[330];
bool sh[330][330];
bool bfs(){
    memset(vis,0,sizeof(vis));
    memset(sh,0,sizeof(sh));
    queue<int> q;
    vis[0]=1;
    q.push(0);
    int cur;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        for(int i=0;i<=K+C+1;++i)
        {
            if(!vis[i]&&map[cur][i])
            {
                vis[i]=1;
                sh[cur][i]=1;
                q.push(i);
            }
        }
    }
    if(vis[K+C+1])
        return 1;
    return 0;
}
int dfs(int cur,int num){
    if(cur==K+C+1)
        return num;
    int sum = num;
    for(int i=0;i<=K+C+1;++i)
    {
        if(sh[cur][i])
        {
            int ans=dfs(i,min(map[cur][i],num));
            map[cur][i]-=ans;
            map[i][cur]+=ans;
            num-=ans;
            if(!num)
                break;
        }
    }
    return sum-num;
}
int main() {
    scanf("%d %d %d",&K,&C,&M);
    for(int i=1;i<=K+C;++i)
        for(int j=1;j<=K+C;++j)
        {
            scanf("%d",&dist[i][j]);
            if(!dist[i][j])
                dist[i][j]=INF;
        }
    for(int k=1;k<=K+C;++k)
        for(int i=1;i<=K+C;++i)
        {
            if(dist[i][k]!=INF)
                for(int j=1;j<=K+C;++j)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    int L=0;
    int R=100000;
    while(L<R)
    {
        int mid=(L+R)/2;
        memset(map,0,sizeof(map));
        for(int i=K+1;i<=K+C;++i)
            map[0][i]=1;
        for(int i=1;i<=K;++i)
            map[i][K+C+1]=M;
        for(int i=K+1;i<=K+C;++i)
            for(int j=1;j<=K;++j)
                if(dist[i][j]<=mid)
                    map[i][j]=1;
        int sum=0;
        while(bfs())
        {
            sum+=dfs(0, INF);
        }
        if(sum>=C)
            R=mid;
        else
            L=mid+1;
    }
    printf("%d\n",R);
    return 0;
}
