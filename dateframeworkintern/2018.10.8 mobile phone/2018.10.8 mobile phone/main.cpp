#include <iostream>
using namespace std;
int sq[1050][1050]={};
int C[1050][1050]={};
int lowbit(int x)
{
    return x&(-x);
}
int sum(int x,int y)
{
    int sum=0;
    while(x>0)
    {
        int tmpy=y;
        while(tmpy>0)
        {
            sum+=C[x][tmpy];
            tmpy-=lowbit(tmpy);
        }
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int n,S;
    cin>>n>>S;
    while(cin>>n)
    {
        if(n==3)
            break;
        else if(n==1)
        {
            int x,y,a;
            cin>>x>>y>>a;
            ++x;
            ++y;
            sq[x][y]+=a;
            while(x<=S)
            {
                int tmpy=y;
                while(tmpy<=S)
                {
                    C[x][tmpy]+=a;
                    tmpy+=lowbit(tmpy);
                }
                x+=lowbit(x);
            }
        }
        else if(n==2)
        {
            int l,b,r,t;
            cin>>l>>b>>r>>t;
            ++l;++b;++r;++t;
            cout<<sum(r,t)-sum(l-1,t)-sum(r,b-1)+sum(l-1,b-1)<<endl;
        }
    }
    return 0;
}
