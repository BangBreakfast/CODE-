#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > AT(100010);
int start[100010]={};
int End[100010]={};
bool a[200020]={};
int C[200020]={};
int counts;
void dfs(int i)
{
    ++counts;
    start[i]=counts;
    for(int j=0;j<AT[i].size();++j)
        dfs(AT[i][j]);
    ++counts;
    End[i]=counts;
}
int lowbit(int num)
{
    return num&(-num);
}
int sum(int num)
{
    int sum=0;
    while(num>0)
    {
        sum+=C[num];
        num-=lowbit(num);
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        AT[a].push_back(b);
    }
    counts=0;
    dfs(1);
    for(int i=1;i<=2*n;++i)
        a[i]=1;
    for(int i=1;i<=2*n;++i)
        C[i]=lowbit(i);
    int c;
    cin>>c;
    for(int i=0;i<c;++i)
    {
        char tmp;
        int num;
        cin>>tmp>>num;
        if(tmp=='Q')
        {
            cout<<(sum(End[num])-sum(start[num]-1))/2<<endl;
        }
        if(tmp=='C')
        {
            int s_n=start[num];
            int e_n=End[num];
            a[s_n]=!a[s_n];
            a[e_n]=!a[e_n];
            int plu_s=-1;
            int plu_e=-1;
            if(a[s_n])
                plu_s=1;
            if(a[e_n])
                plu_e=1;
            while(s_n<=2*n)
            {
                C[s_n]+=plu_s;
                s_n+=lowbit(s_n);
            }
            while(e_n<=2*n)
            {
                C[e_n]+=plu_e;
                e_n+=lowbit(e_n);
            }
        }
    }
    return 0;
}
