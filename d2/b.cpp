#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e6 + 7;

int opt, tot, lson[maxn], rson[maxn], val[maxn], rt[60], x, got;

void init()
{
    tot = 0;
    MEM(lson, 0); MEM(rson, 0); MEM(rt, 0);
    MEM(val, 0x3f3f3f3f);
}

void update(int& now, int l, int r, int pos, int v)
{
    if(!now) now = ++tot;
    val[now] = min(val[now], v);
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(pos <= mid) update(lson[now], l, mid, pos, v);
    else update(rson[now], mid + 1, r, pos, v);
}

void query(int now, int l, int r, int L, int R)
{
    if(!now || got) return;
    if(L <= l && r <= R)
    {
        if(val[now] <= x) got = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) query(lson[now], l, mid, L, R);
    if(mid < R) query(rson[now], mid + 1, r, L, R);
}


int main()
{
    int l, r, ans, y, c;
    while(scanf("%d", &opt) != EOF)
    {
        if(opt == 0)
        {
            init();
        }
        else if(opt == 1)
        {
            scanf("%d%d%d", &x, &y, &c);
            update(rt[c], 1, maxn - 7, y, x);
        }
        else if(opt == 2)
        {
            ans = 0;
            scanf("%d%d%d", &x, &l, &r);
            for(int i = 0; i <= 50; i++)
            {
                got = 0;
                query(rt[i], 1, maxn - 7, l, r);
                ans += got;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
