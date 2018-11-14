#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef vector<int>::iterator it;
vector<int> last;
vector<int> mid;
vector<int> first;
int end_=0;
struct node{
    int num;
    node * left;
    node * right;
    node(int n)
    {
        num=n;
        left=NULL;
        right=NULL;
    }
};
void dig(node * root,int st,int ed,int ls_st,int ls_ed)
{
    set<int> s;
    if(st==ed||ls_st>ls_ed)
        return;
    int i,j;
    for(i=st;i<=ed;++i)
    {
        if(mid[i]==root->num)
            break;
        s.insert(mid[i]);
    }
    j=ls_st;
    if(!s.empty())
    {
        for(;j<=ls_ed;j++)
        {
            if(s.find(last[j])==s.end())
                break;
        }
        root->left=new node(last[j-1]);
        dig(root->left,st,i-1,ls_st,j-1);
    }
    if(j!=ls_ed+1)
    {
        root->right=new node(last[ls_ed]);
        dig(root->right,i+1,ed,j,ls_ed-1);
    }
}
void f1(node *root)
{
    first.push_back(root->num);
    if(root->left)
        f1(root->left);
    if(root->right)
        f1(root->right);
}
int main() {
    int n;
    char c;
    while(cin>>n)
    {
        mid.push_back(n);
        end_++;
        c=cin.get();
        if(c=='\n')
            break;
    }
    while(cin>>n)
    {
        last.push_back(n);
        c=cin.get();
        if(c=='\n')
            break;
    }
    end_--;
    node * root=new node(last[end_]);
    dig(root,0,end_,0,end_-1);
    f1(root);
    it i=first.begin();
    cout<<*i;
    ++i;
    for(;i!=first.end();++i)
        cout<<' '<<*i;
    return 0;
}
