#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int num[110][2010]={};
int main() {
    priority_queue<int,vector<int>,greater<int>> q;
    int cases;
    cin>>cases;
    while(cases--)
    {
        int m,n;
        cin>>m>>n;
        int tmp[2010];
        int i=0;
        for(int j=0;j<n;++j)
        {
            cin>>tmp[j];
        }
        sort(tmp,tmp+n);
        for(i=1;i<m;++i)
        {
            int t;
            q=priority_queue<int,vector<int>,greater<int>>();
            for(int j=0;j<n;++j)
            {
                cin>>t;
                for(int k=0;k<n;++k)
                {
                    q.push(tmp[k]+t);
                }
            }
            for(int k=0;k<n;++k)
            {
                tmp[k]=q.top();
                q.pop();
            }
        }
        cout<<tmp[0];
        for(int i=1;i<n;++i)
            cout<<' '<<tmp[i];
        cout<<endl;
    }
    return 0;
}
