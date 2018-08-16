#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
//const LL mod = 1000000007;
LL f[1000][1000];
LL n, m;

LL ksm(LL a, LL b)
{
    LL res = 1;
    while(b)
    {
        if(b & 1) res = MOD(res * a);
        a = MOD(a * a);
        b /= 2;
    }
    return MOD(res);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    LL inv = ksm(3, 1000000007 - 2);
    int T; cin >> T;
    while(T--)
    {
        cin >> n >> m;
        LL ans = MOD(ksm(2, n) - 1 + 1000000007);
        ans = MOD(2 * ksm(ans, m - 1));
        if(n % 2 == 1)
        {
            ans = MOD((ans + 1) * inv);
        }
        else ans = MOD(ans * inv);
        cout << ans << endl;
    }
    return 0;
}
