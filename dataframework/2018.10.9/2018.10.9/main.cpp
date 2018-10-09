#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n;
bool functions ( vector<int> & seq)
{
    stack<int> stk;
    int i=1;
    stk.push(i);
    for(int j=0;j<n;++j)
    {
        if(seq[j]>i)
        {
            for(;i<seq[j];i++)
            {
                stk.push(i);
            }
        }
        else
        {
            if(stk.top()!=seq[j])
                return 0;
            else
                stk.pop();
        }
    }
    return 1;
}
int main()
{
    while(1)
    {
        cin>>n;
        vector<int> seq;
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            seq.push_back(tmp);
        }
        cout<< functions(seq);
    }
    return 0;
}
