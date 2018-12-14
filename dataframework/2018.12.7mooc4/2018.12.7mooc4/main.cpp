#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int n;
    vector<int> cash[5050];
    cin>>n;
    int num[5050];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        cin>>num[i];
        int t=num[i];
        int tmp;
        for(int j=0;j<t;++j)
        {
            cin>>tmp;
            cash[i].push_back(tmp);
        }
        sort(cash[i].begin(),cash[i].end());
        ans+=cash[i][cash[i].size()-1]-cash[i][0];
        for(int j=1;j<cash[i].size()-1;++j)
        {
            cash[i+1].push_back(cash[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
int fd=open("foo.txt",O_RDONLY,0);
dup2(fd,1);
close(fd);

