#include <iostream>
using namespace std;
bool cmp(char a,char b)
{
    if(a==b)
        return 1;
    else if(a>='a'&&a<='z'&&b-'A'==a-'a')
        return 1;
    else if(a>='A'&&a<='Z'&&b-'a'==a-'A')
        return 1;
    return 0;
}
int main() {
    int n;
    cin>>n;
    string str[55];
    for(int i=0;i<n;++i)
    {
        cin>>str[i];
    }
    string c;
    cin>>c;
    for(int i=0;i<n;++i)
    {
        bool flag=1;
        int j=0,k=0;
        for(;j<str[i].size()&&k<c.size();++j,++k)
        {
            string tmp;
            int ktmp;
            if(c[k]=='[')
            {
                ktmp=k+1;
                while(c[ktmp]!=']')
                {
                    ++ktmp;
                }
                tmp=c.substr(k+1,ktmp-k-1);
                for(int ii=0;ii<c.size();++ii)
                {
                    if(cmp(c[ii],str[i][j]))
                    {
                        break;
                    }
                    if(ii==c.size()-1)
                    {
                        flag=0;
                    }
                }
                k=ktmp;
            }
            else if(!cmp(c[k],str[i][j]))
                 flag=0;
        }
        if(j!=str[i].size()||k!=c.size())
            flag=0;
        if(flag)
            cout<<i+1<<' '<<str[i]<<endl;
    }
    return 0;
}
