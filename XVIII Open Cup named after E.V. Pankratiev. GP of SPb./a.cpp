#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1000007;
string a, b;
int c[maxn], up;

int main()
{
    freopen("base-i-1.in", "r", stdin);
    freopen("base-i-1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int L = min(a.length(), b.length());
    for(int i = 0; i < L; i++)
    {
        c[i] = (a[i] - '0') + (b[i] - '0');
    }
    if(a.length() == L)
    {
        up = b.length();
        for(int i = L; i < up; i++) c[i] = (b[i] - '0');
    }
    else if(b.length() == L)
    {
        up = a.length();
        for(int i = L; i < up; i++) c[i] = (a[i] - '0');
    }
    for(int i = 0; i < 1000000; i++)
    {
        while(c[i] >= 2)
        {
            if(c[i + 1] >= 2 && c[i + 2] >= 1)
            {
                c[i] -= 2; c[i + 1] -= 2; c[i + 2] -= 1;
            }
            else
            {
                c[i] -= 2;
                c[i + 2] += 1; c[i + 3] += 1;
            }
        }
    }
    up = 1000000;
    while(c[up] == 0) up--;
    if (up<0) up=0;
    for(int i = up; i >= 0; i--) cout << c[i];
    return 0;
}
