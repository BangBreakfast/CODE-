#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N,M;
int now=0;
int sum=0;
int res;
vector<int> gr[10050];
stack<int> stk;
int dfs[10050]={};
int low[10050]={};
bool vis[10050]={};
int pit[10050]={};
int deg[10050]={};
int pop;
void targin(int num)
{
    vis[num]=1;
    dfs[num]=low[num]=++now;
    stk.push(num);
    for(int i=0;i<gr[num].size();++i)
    {
        int tmp=gr[num][i];
        if(!dfs[tmp])
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
void init(){
    now=0;
    sum=0;
    res=0;
    cin>>N>>M;
    for(int i=0;i<M;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        gr[a].push_back(b);
    }
}
void solve(){
    for(int i=1;i<=N;++i)
        if(!dfs[i])
            targin(i);
    for(int i=1;i<=N;++i)
        for(int j=0;j<gr[i].size();++j)
            if(pit[i]!=pit[gr[i][j]])
                deg[pit[i]]++;//只用判断是不是0所以不管重复量了
    for(int i=1;i<=sum;++i)
    {
        if(!deg[i])
        {
            ++res;
            pop=i;
        }
    }
    if(res>1)
        printf("0\n");
    else
    {
        int ans=0;
        for(int i=1;i<=N;++i)
            if(pit[i]==pop)
                ++ans;
        printf("%d\n",ans);
    }
}

int main() {
    init();
    solve();
    return 0;
}
