#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int M,N;
bool able[300][300]={};
bool vis[300]={};
int match[300]={};
vector<int> E[300];
bool find(int x)
{
    for(int i=0;i<E[x].size();++i)
    {
        int cur=E[x][i];
        if(!vis[cur])
        {
            vis[cur]=1;
            if((match[cur]==-1) || find(match[cur]))
            {
                match[cur]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    while(cin>>N>>M){
        for(int i=1;i<=N;++i)
        {
            E[i].clear();
            int tmp;
            cin>>tmp;
            for(int j=0;j<tmp;++j)
            {
                int dim;
                cin>>dim;
                E[i].push_back(dim);
            }
        }
        int ans=0;
        memset(match,-1,sizeof(match));
        for(int i=1;i<=N;++i)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
