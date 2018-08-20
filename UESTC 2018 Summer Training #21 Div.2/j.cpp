#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e5 + 7;
int fir[maxn], last[maxn], a[maxn];
int tr[4 * maxn], firmax, n, m;


void build(int rt, int l, int r)
{
    if(l == r)
    {
        tr[rt] = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(rt * 2, l, mid);
    build(rt * 2 + 1, mid + 1, r);
    tr[rt] = max(tr[rt * 2], tr[rt * 2 + 1]);
}

int querymax(int rt, int l, int r, int L, int R)
{
    if(L <= l && r <= R)
    {
        return(tr[rt]);
    }
    int mid = (l + r) / 2;
    int res = -1;
    if(mid >= L) res = max(res, querymax(rt * 2, l, mid, L, R));
    if(mid < R) res = max(res, querymax(rt * 2 + 1, mid + 1, r, L, R));
    return(res);
}

void query(int rt, int l, int r, int L, int R, int k)
{
    if(l == r)
    {
        firmax = min(firmax, l);
        return;
    }
    int m = (l + r) >> 1;
    if(L <= l && r <= R)
    {
        if(tr[rt * 2] > k) query(rt * 2, l, m, L, R, k);
        else if(tr[rt * 2 + 1] > k) query(rt * 2 + 1, m + 1, r, L, R, k);
        return ;
    }
    if(L <= m && tr[rt * 2] > k) query(rt * 2, l, m, L, R, k);
    if(R > m && tr[rt * 2 + 1] > k) query(rt * 2 + 1, m + 1, r, L, R, k);
}



int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)  scanf("%d", &a[i]);
        last[1] = 1;
        int MAX = a[1], pos = 1;
        for(int i = 2; i <= n; i++)
        {
            last[i] = last[pos];
            if(MAX < a[i])
            {
                last[i]++;
                pos = i; MAX = a[i];
            }
        }

        build(1, 1, n);
        fir[n] = 1;
        for(int i = n - 1; i >= 1; i--)
        {
            firmax = n + 1;
            query(1, 1, n, i + 1, n, a[i]);
            if(firmax <= n) fir[i] = fir[firmax] + 1;
            else fir[i] = 1;
        }
        //for(int i = 1; i <= n; i++) cout << last[i] << " ";
        //cout << endl;
        //for(int i = 1; i <= n; i++) cout << fir[i] << " ";
        while(m--)
        {
            int p, q, ans = 0; scanf("%d%d", &p, &q);
            MAX = q;
            if(p == 1) ans = 1;
            if(p > 1)
            {
                int k = querymax(1, 1, n, 1, p - 1);
                firmax = p;
                query(1, 1, n, 1, p - 1, k - 1);
                ans += last[firmax];
                if(q > k) ans++;
                MAX = max(q, k);
            }
            if(p < n)
            {
                firmax = n + 1;
                query(1, 1, n, p + 1, n, MAX);
                if(firmax <= n) ans += fir[firmax];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
