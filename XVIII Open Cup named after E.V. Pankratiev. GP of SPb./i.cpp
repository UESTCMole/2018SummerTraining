#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int ans[505], n, le[505], ri[505], cntl = 0, cntr = 0;

int cmp(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int tmp;
    scanf("%d", &tmp);
    return(1 - tmp);
}

int main()
{
    scanf("%d", &n);
    if(n == 1)
    {
        puts("! YES");
        puts("1");
        return 0;
    }
    for(int i = 2; i <= n; i++)
    {
        printf("? 1 %d\n", i);
        fflush(stdout);
        int tmp;
        scanf("%d", &tmp);
        if(tmp) le[++cntl] = i;
        else ri[++cntr] = i;
    }
    if(cntl > 0) sort(le + 1, le + 1 + cntl, cmp);
    if(cntr > 0) sort(ri + 1, ri + 1 + cntr, cmp);

    if(cntl == 0)
    {
        puts("! YES");
        for(int i = cntr; i >= 1; i--) cout << ri[i] << " ";
        cout << "1";
        return 0;
    }
    if(cntr == 0)
    {
        puts("! YES");
        cout << "1 ";
        for(int i = cntl; i >= 1; i--) cout << le[i] << " ";
        return 0;
    }
    printf("? %d %d\n", le[1], ri[cntr]);
    fflush(stdout);
    int tmp; scanf("%d", &tmp);
    if(tmp)
    {
        puts("! NO");
        printf("%d ", n);
        cout << "1 ";
        for(int i = cntl; i >= 1; i--) cout << le[i] << " ";
        for(int i = cntr; i >= 1; i--) cout << ri[i] << " ";
    }
    else
    {
        puts("! YES");
        for(int i = cntr; i >= 1; i--) cout << ri[i] << " ";
        cout << "1 ";
        for(int i = cntl; i >= 1; i--) cout << le[i] << " ";
    }
    return 0;
}
