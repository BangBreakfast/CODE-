#include <iostream>
using namespace std;
int parent[50010];
int sexual[50010];
int getroot(int a)
{
    if(parent[a]!=a)
    {
        int tmp=parent[a];
        parent[a]=getroot(parent[a]);
        sexual[a]=(sexual[a]+sexual[tmp])%2;
    }
    else
        sexual[a]=0;
    return parent[a];
}
bool check(int a,int b)
{
    int p1=getroot(a);
    int p2=getroot(b);
    if(p1==p2&&sexual[a]==sexual[b])
        return 0;
    return 1;
}
void merge(int a,int b)
{
    int p1=getroot(a);
    int p2=getroot(b);
    if(p1!=p2)
    {
        parent[p2]=p1;
        sexual[p2]=(sexual[a]+1-sexual[b]+2)%2;
    }
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int bg,it;
        cin>>bg>>it;
        bool tmp=0;
        for(int j=0;j<=bg;++j)
        {
            parent[j]=j;
            sexual[j]=0;
        }
        while(it--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(check(x,y))
                merge(x,y);
            else
            {
                tmp=1;
                continue;
            }
        }
        printf("Scenario #%d:\n",i);
        if (tmp)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}
