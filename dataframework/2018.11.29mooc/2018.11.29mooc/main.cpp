#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int N,M;
double x[110];
double y[110];
const double INF=0x3f3f3f;
struct edge{
    int st;
    int ed;
    double val;
}e[1010];
int pre[110];//存储父节点
int vis[110];//标记作用
int id[110];//id[i]记录节点i所在环的编号
double in[110];//in[i]记录i入边中最小的权值
double zhuliu(int root, int n, int m, edge *e)//root根 n点数 m边数
{
    double res=0;
    int u, v;
    while(1)
    {
        for(int i = 1; i <= n; i++)
            in[i] = INF;
        for(int i = 0; i < m; i++)
        {
            edge E = e[i];
            if(E.ed != root && E.st != E.ed && E.val < in[E.ed])
            {
                pre[E.ed] = E.st;//记录前驱
                in[E.ed] = E.val;//更新
            }
        }
        for(int i = 1; i <= n; i++)
            if(i != root && in[i] == INF)
                return -1;//有其他孤立点 则不存在最小树形图
        //找有向环
        int tn = 0;//记录当前查找中 环的总数
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;//根
        for(int i = 1; i <= n; i++)
        {
            res += in[i];//累加
            v = i;
            //找图中的有向环 三种情况会终止while循环
            //1,直到出现带有同样标记的点说明成环
            //2,节点已经属于其他环
            //3,遍历到根
            while(vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;//标记
                v = pre[v];//一直向上找
            }
            //因为找到某节点属于其他环  或者 遍历到根  说明当前没有找到有向环
            if(v != root && id[v] == -1)//必须上述查找已经找到有向环
            {
                for(int u = pre[v]; u != v; u = pre[u])
                    id[u] = tn;//记录节点所属的 环编号
                id[v] = tn++;//记录节点所属的 环编号  环编号累加
            }
        }
        if(tn == 0) break;//不存在有向环
        //可能存在独立点
        for(int i = 1; i <= n; i++)
            if(id[i] == -1)
                id[i] = tn++;//环数累加
        //对有向环缩点  和SCC缩点很像吧
        for(int i = 0; i < m; i++)
        {
            v = e[i].ed;
            e[i].st = id[e[i].st];
            e[i].ed = id[e[i].ed];
            //<u, v>有向边
            //两点不在同一个环 u到v的距离为 边权cost - in[v]
            if(e[i].st != e[i].ed)
                e[i].val -= in[v];//更新边权值 继续下一条边的判定
        }
        n = tn;//以环总数为下次操作的点数 继续执行上述操作 直到没有环
        root = id[root];
    }
    return res;
}
int main() {
    while(scanf("%d %d",&N,&M)!=EOF)
    {
        for(int i=1;i<=N;++i)
        {
            cin>>x[i];
            cin>>y[i];
        }
        for(int i=0;i<M;++i)
        {
            cin>>e[i].st;
            cin>>e[i].ed;
            double delta_x=x[e[i].st]-x[e[i].ed];
            double delta_y=y[e[i].st]-y[e[i].ed];
            e[i].val=sqrt(delta_x*delta_x+delta_y*delta_y);
        }
        double ans=zhuliu(1,N,M,e);
        if(ans==-1)
            cout<<"NO"<<endl;
        else
            printf("%.2lf\n",ans);
    }
    return 0;
}
