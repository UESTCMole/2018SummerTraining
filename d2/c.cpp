#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e5 + 7;

vector<int>E[maxn];
/*struct node
{
    int u, v;
} Edge[4 * maxn];*/
struct kk
{
    int deg, id;
} d[maxn];
LL C[maxn];
int n, m, del[maxn], vis[maxn];

int cmp(kk a, kk b)
{
    return(a.deg > b.deg);
}

int main()
{
    C[0] = C[1] = 0;
    for(LL i = 2; i <= 100000; i++) C[i] = (i - 1) * i / 2;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            d[i].id = i;
            d[i].deg = 0;
            del[i] = 0;
        }
        int u, v;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            d[u].deg++; d[v].deg++;
            E[u].push_back(v);
            E[v].push_back(u);
            //Edge[i].u = u, Edge[i].v = v;
        }
        sort(d + 1, d + 1 + n, cmp);
        LL ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int u = d[i].id;
            for(int j = 0; j < E[u].size(); j++)
            {
                vis[E[u][j]] = 1;
            }
            for(int j = 0; j < E[u].size(); j++)
            {
                int v = E[u][j], num = 0;
                if(del[v]) continue;
                for(int k = 0; k < E[v].size(); k++)
                {
                    if(vis[E[v][k]]) num++;
                }
                ans = ans + C[num];
            }
            for(int j = 0; j < E[u].size(); j++)
            {
                vis[E[u][j]] = 0;
            }
            del[u] = 1;
        }
        printf("%lld\n", ans);
        for(int i = 1; i <= n; i++) E[i].clear();
    }

    return 0;
}