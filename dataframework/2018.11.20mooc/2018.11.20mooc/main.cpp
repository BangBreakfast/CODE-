#include <iostream>
#include <algorithm>
using namespace std;

int tree[11][2];
int find(int n)
{
    if(n==-1)
        return 0;
    return 1+max(find(tree[n][0]),find(tree[n][1]));
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        tree[i][0]=tmp;
        cin>>tmp;
        tree[i][1]=tmp;
    }
    cout<<find(1);
    return 0;
}
