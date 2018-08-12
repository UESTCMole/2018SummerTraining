#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int table[20], L, vis[20];
int id[100], tot = 1;
LL t[3628800 + 7];
LL base[40];
string s;
void dfs(int now)
{
    if(now > 10)
    {
        LL res = 0;
        for(int i = 1; i < L; i++)
        {
            if(table[id[s[i - 1] - 'a' + 1]] < table[id[s[i] - 'a' + 1]]) res = res * 3 + 0;
            else if(table[id[s[i - 1] - 'a' + 1]] == table[id[s[i] - 'a' + 1]]) res = res * 3 + 1;
            else if(table[id[s[i - 1] - 'a' + 1]] > table[id[s[i] - 'a' + 1]]) res = res * 3 + 2;
        }
        t[tot++] = res;
        return;
    }
    for(int i = 1; i <= 10; i++)
    {
        if(vis[i]) continue;
        table[now] = i;
        vis[i] = 1;
        dfs(now + 1);
        vis[i] = 0;
    }
}

void putout(LL ans)
{
    string tmp = "";
    for(int i = 1; i < L; i++)
    {
        if(ans % 3 == 0) tmp = "<" + tmp;
        else if(ans % 3 == 1) tmp = "=" + tmp;
        else if(ans % 3 == 2) tmp = ">" + tmp;
        ans /= 3;
    }
    cout << s[0];
    for(int i = 1; i < L; i++)
    {
        cout << " " << tmp[i - 1] << " " << s[i];
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    L = s.length();
    int index = 0;
    for(int i = 0; i < L; i++)
    {
        if(id[s[i] - 'a' + 1] == 0) id[s[i] - 'a' + 1] = ++index;
    }
    dfs(1);
    LL ans = 0;
    string tmp = "";
    sort(t + 1, t + 1 + 3628800);
    t[0] = t[3628801] = 0;
    for(int i = 1; i <= 3628800; i++)
    {
        if(t[i] != t[i + 1] && t[i] != t[i - 1])
        {
            ans = t[i];
            //cout << ans << endl;
            putout(ans);
            break;
        }
    }

    if(!ans) cout << "Impossible" << endl;
    return 0;
}
