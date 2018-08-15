#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e6 + 7;
char X[maxn], Y[maxn], Z[maxn];
int posx[maxn], posy[maxn], totx, toty;

struct Kmp
{
    int nex[maxn];
    void GetNext(char *p)
    {
        //memset(nex, -1, sizeof(nex));
        int m = strlen(p);

        nex[0] = -1;
        int k = -1, j = 0;
        while(j < m)
        {
            if(k == -1 || p[j] == p[k])
            {
                nex[++j] = ++k;
            }
            else k = nex[k];
        }
        /*
        for(int i = 1; i < m; i++)
        {
            int j = nex[i];
            while(j && s[i] != s[j]) j = nex[j];
            if(s[i] == s[j]) nex[i + 1] = j + 1;
            else nex[i + 1] = 0;
        }*/
    }

    void match(char *s, char *p, int *pos, int &tot)
    {
        //memset(pos, -1, sizeof(pos));
        int n = strlen(s);
        int m = strlen(p);

        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(j == -1 || s[i] == p[j])
            {
                i++; j++;
            }
            else j = nex[j];
            if(j == m)
            {
                pos[tot++] = i;
                j = nex[j];
            }
        }
        /*
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            while(j && p[j] != s[i]) j = nex[j];
            if(p[j] == s[i]) j++;
            if(j == m)
            {
                pos[tot++] = i;
                i--;
            }
        }*/
    }
} kmpx, kmpy;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; scanf("%d", &T);
    while(T--)
    {
        totx = 0; toty = 0;
        scanf("%s", Z); scanf("%s", X); scanf("%s", Y);
        kmpx.GetNext(X); kmpx.match(Z, X, posx, totx);
        kmpy.GetNext(Y); kmpy.match(Z, Y, posy, toty);
        //for(int i = 0; i < totx; i++) cout << posx[i] << " "; cout << endl;
        //for(int i = 0; i < toty; i++) cout << posy[i] << " "; cout << endl;
        int Lx = strlen(X);
        int Ly = strlen(Y);
        if(totx == 0 || toty == 0)
        {
            printf("NO\n");
            continue;
        }
        if((posx[0] <= posy[toty - 1] - Ly) || (posy[0] <= posx[totx - 1] - Lx)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
