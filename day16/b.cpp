#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

LL table[100005][26];
LL base[100005];
int flg[30], zero;
string s;

struct node
{
    string s;
    int flg, name;
} t[30];

int cmp(node a, node b)
{
    return(a.s > b.s);
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    int kase = 1, maxl = 0;
    int n;
    base[0] = 1;
    for(int i = 1; i < 100005; i++)
    {
        base[i] = MOD(base[i - 1] * 26);
        //cout<<base[i]<<endl;
    }

    while(cin >> n)
    {
        maxl = 0;
        MEM(table, 0);
        MEM(flg, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            if (s.length() > 1) flg[s[0] - 'a'] = 1;
            int L = s.length(), k;
            for(int x = L - 1; x >= 0; x--)
            {
                int j = L - 1 - x;
                int c = s[x] - 'a';
                table[j][c]++;
                k = j;
                while(table[k][c] > 25)
                {
                    table[k + 1][c] += table[k][c] / 26;
                    table[k][c] = table[k][c] % 26;
                    k++;
                }
                maxl = max(k, maxl);
            }
        }
        for(int i = 0; i < 26; i++)
        {
            string tmp = "";
            for(int j = maxl; j >= 0; j--)
            {
                char c = table[j][i] + 'a';
                tmp += c;
            }
            t[i].flg = flg[i];
            t[i].s = tmp;
            t[i].name = i;
            // cout << t[i].s << endl;
        }
        sort(t, t + 26, cmp);
        int x = 25;
        while(t[x].flg == 1) x--;

        LL res = 0, now = 25;

        for(int i = 0; i < 26; i++)
        {
            if(i == x) continue;
            int ch = t[i].name;
            LL tmp = 0;
            for(int j = 0; j <= maxl; j++)
            {
                LL k = t[i].s[maxl - j] - 'a';
                tmp = MOD(tmp + k * base[j]);
            }
            res = MOD(res + tmp * now);

            //cout << (char)(ch + 'a') << ":" << now << endl;
            now--;
        }
        //cout << (char)(t[x].name + 'a') << ":" << now << endl;
        cout << "Case #" << kase << ": " << res << endl;
        kase++;
    }
    return 0;
}