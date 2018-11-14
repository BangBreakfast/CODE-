#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
char output[55][350];
int last[55]={};
int val[26]={};
struct node{
    char op;
    node * left;
    node * right;
};
int pow(int x,int y)
{
    int res=1;
    for(int i=0;i<y;++i)
        res*=x;
    return res;
}
inline bool ifnum(char c)
{
    return (c>='a')&&(c<='z');
}
inline int pri(char c)
{
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
//    if(c=='^')
//        return 3;
    else
        return 0;
}
int findd(node * rt)
{
    if(!rt)
        return 0;
    int l=findd(rt->left);
    int r=findd(rt->right);
    return max(l,r)+1;
}
int cal(node * rt)
{
    char c=rt->op;
    if(ifnum(c))
        return val[c-'a'];
    switch (c) {
        case '+':
            return cal(rt->left)+cal(rt->right);
        case '-':
            return cal(rt->left)-cal(rt->right);
        case '*':
            return cal(rt->left)*cal(rt->right);
        case '/':
            return cal(rt->left)/cal(rt->right);
        //case '^':
        //    return pow(cal(rt->left),cal(rt->right));
        default:
            return 0;
    }
}
void buildoutput(node * cur,int x,int y,int space)
{
    output[x][y]=cur->op;
    last[x]=max(last[x],y);
    if(cur->left)
    {
        output[x+1][y-1]='/';
        buildoutput(cur->left,x+2,y-space,space>>1);
    }
    if(cur->right)
    {
        output[x+1][y+1]='\\';
        last[x+1]=max(last[x+1],y+1);
        buildoutput(cur->right,x+2,y+space,space>>1);
    }
}
int main() {
    string str;
    cin>>str;
    string back="";
    stack<char> stk;
    for(int i=0;i<str.size();++i)
    {
        char c=str[i];
        if(ifnum(c))
        {
            back+=c;
        }
        else
        {
            if(c=='(')
            {
                stk.push(c);
                continue;
            }
            if(c==')')
            {
                while(!stk.empty())
                {
                    char tmp=stk.top();
                    if(tmp=='(')
                    {
                        stk.pop();
                        break;
                    }
                    back+=tmp;
                    stk.pop();
                }
            }
            else
            {
                while(!stk.empty()&&pri(stk.top())>=pri(c)&&stk.top()!='(')
                {
                    back+=stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
        }
    }
    while(!stk.empty())
    {
        back+=stk.top();
        stk.pop();
    }//求逆波兰表达式
    cout<<back<<endl;
    stack<node *> nstk;
    for(int i=0;i<back.size();++i)
    {
        char c=back[i];
        if(ifnum(c))
        {
            node * cur = new node;
            cur->op=c;
            cur->left=NULL;
            cur->right=NULL;
            nstk.push(cur);
        }
        else
        {
            node * r = nstk.top();
            nstk.pop();
            node * l = nstk.top();
            nstk.pop();
            node * cur = new node;
            cur->op=c;
            cur->left=l;
            cur->right=r;
            nstk.push(cur);
        }
    }
    node * root=nstk.top();
    nstk.pop();//建树
    int deep=findd(root);
    int y=pow(2,deep-1)-1;
    buildoutput(root,0,y,(y+1)>>1);
    int n;
    cin>>n;
    while(n--)
    {
        char tmp;
        cin>>tmp;
        cin>>val[tmp-'a'];
    }
    for(int i=0;i<2*deep-1;++i)
    {
        for(int j=0;j<=last[i];++j)
        {
            if(output[i][j]==0)
                cout<<' ';
            else
                cout<<output[i][j];
        }
        cout<<endl;
    }
    cout<<cal(root);
    return 0;
}
