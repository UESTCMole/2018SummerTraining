#include<bits/stdc++.h>
#define ll long long


using namespace std;


const int maxn = 2e6 + 7;
const int maxk = 10000;
const int MOD = 997;


struct node
{
    int x, y;
    node() {}
    node(int x, int y): x(x), y(y) {}
    bool operator < (const node &b) const
    {
        if(x == b.x) return y < b.y;
        else return x < b.x;
    }
} a[maxk];
ll A[maxn], inv[maxn], dp[maxk];
int optx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int opty[8] = {1, -1, 0, 0, -1, 1, -1, 1};
ll ksm(ll x, int m)
{
    ll ans = 1;
    while(m)
    {
        if(m & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        m /= 2;
    }
    return ans;
}
void init()
{
    A[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= maxn - 5; i++)
    {
        A[i] = A[i - 1] * i, A[i] %= MOD;
        inv[i] = ksm(A[i], MOD - 2);
    }
}
ll C(int n, int m)
{
    if(n == m) return(1);
    return A[n] * inv[m] % MOD * inv[n - m] % MOD;
}
ll Lucas(ll a, ll b)
{
    if(a < MOD && b < MOD)
        return C(a, b);
    return
        C(a % MOD, b % MOD) * Lucas(a / MOD, b / MOD);
}
ll cal(int x1, int y1, int x2, int y2)
{
    int x = (x2 - x1), y = (y2 - y1);
    return Lucas(x + y, x) % MOD;
}
int main()
{
    int T, cas = 0; scanf("%d", &T);
    init();
    while(T--)
    {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1; i <= k; i++) scanf("%d %d", &a[i].x, &a[i].y);
        int tot = k;
        for(int i = 1; i <= k; i++)
        {
            for(int op = 0; op < 8; op++)
            {
                int x = a[i].x + optx[op], y = a[i].y + opty[op];
                if(x >= 1 && x <= n && y >= 1 && y <= m) a[++tot] = node(x, y);
            }
        }
        k = tot;
        a[0] = node(1, 1);
        a[k + 1] = node(n, m);
        sort(a, a + k + 2);
        //for(int i = 1; i <= k; i++) cout << a[i].x << " " << a[i].y << endl;
        //cout << k << endl;
        dp[0] = 1;
        for(int i = 1; i <= k + 1; i++) dp[i] = cal(1, 1, a[i].x, a[i].y);
        for(int i = 1; i <= k + 1; i++)
        {
            dp[i] = cal(1, 1, a[i].x, a[i].y);
            for(int j = 1; j < i; j++)
            {
                if(a[j].y <= a[i].y)
                    dp[i] = ((dp[i]%MOD - (dp[j] % MOD * cal(a[j].x, a[j].y, a[i].x, a[i].y) % MOD) % MOD + MOD) % MOD + MOD) % MOD;
            }
        }
        printf("Case #%d: %lld\n", ++cas, (dp[k + 1]+MOD)%MOD);
    }
    return 0;
}
