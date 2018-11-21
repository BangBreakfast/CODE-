#include <iostream>
#include <set>
using namespace std;
struct edge{
    int u[2];
    int w;
    edge()
    {
        u[0]=-1;
        u[1]=-1;
        w=-1;
    }
};
edge e[80]={};
bool vis[80]={};
int main() {
    int n;
    cin>>n;
    int t=0;
    set<int> u;
    set<int> vu;
    int minnum=1e10;
    int mined[2];
    int minj=79;
    for(int i=0;i<n;i++)
    {
        vu.insert(i);
    }
    for(int i=0;i<n-1;++i)
    {
        char tmp;
        cin>>tmp;
        int count;
        cin>>count;
        while(count--)
        {
            int num;
            char c;
            cin>>c>>num;
            e[t].u[0]=tmp-'A';
            e[t].u[1]=c-'A';
            e[t].w=num;
            if(num<minnum)
            {
                minnum=num;
                mined[0]=e[t].u[0];
                mined[1]=e[t].u[1];
                minj=t;
            }
            ++t;
        }
    }
    int cnt=0;
    for(int i=0;i<n-1;++i)
    {
        vis[minj]=1;
        cnt+=e[minj].w;
        u.insert(mined[0]);
        vu.erase(mined[0]);
        u.insert(mined[1]);
        vu.erase(mined[1]);
        minnum=100000000;
        for(int j=0;j<t;++j)
        {
            if(vis[j])
                continue;
            if((u.find(e[j].u[0])!=u.end()&&vu.find(e[j].u[1])!=vu.end())||(vu.find(e[j].u[0])!=vu.end()&&u.find(e[j].u[1])!=u.end()))
           {
               if(e[j].w<minnum)
               {
                   minnum=e[j].w;
                   mined[0]=e[j].u[0];
                   mined[1]=e[j].u[1];
                   minj=j;
               }
           }
        }
    }
    cout<<cnt;
    return 0;
}
