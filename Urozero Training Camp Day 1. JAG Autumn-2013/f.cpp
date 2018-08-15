#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <cmath>
#include <iostream>
#define LL long long
using namespace std;
char s[100005], in[100005];
int up = 32;
int tot;
stack <LL> num;
stack <char> opt;
bool did(char c)
{
    return c >= '0' && c <= '9';
}
#define mod 1000000007
int main()
{
    while(scanf("%s", in) != EOF)
    {
        int len = strlen(in);
        for(int i = 0; i < len; i++) s[tot++] = in[i];
    }
    s[tot++] = '#';
    s[tot++] = '#';
    s[tot] = '\0';
    int len = strlen(s);
    // printf("%s\n", s);
    len -= 2;
    for(int i = 0; i < len;)
    {
        if(s[i] == 'S' || s[i] == '<')    //push
        {
            opt.push(s[i]);
            i++;
        }
        else if(s[i] == '>')    //check oper
        {
            if(i == len - 1 || s[i + 1] == '>' && (s[i + 2] != 'S' && !did(s[i + 2]))) //S<x> and cal it
            {
                opt.pop(); opt.pop();
                LL sum = num.top(); num.pop();
                sum = (sum * sum) % mod;
                num.push(sum);
                i++;
            }
            else if(s[i + 1] == '>' && (s[i + 2] == 'S' || did(s[i + 2]))) // x>>y
            {
                opt.push('W');
                i = i + 2;
            }
        }
        if(did(s[i]))
        {
            int j = i;
            LL tmp = 0;
            while(did(s[j]))
            {
                tmp = tmp * 10 + s[j] - '0';
                j++;
            }
            num.push(tmp);
            i = j;
        }

        while(opt.size() && opt.top() == 'W' && num.size() > 1) //cal x>>y
        {
            opt.pop();
            LL rhs = num.top(); num.pop();
            LL lhs = num.top(); num.pop();
            //if(rhs >= up) lhs = 0;
            //else
            {
                while(rhs)
                {
                    lhs /= 2;
                    if(lhs == 0) break;
                    rhs--;
                }
            }
            num.push(lhs);
        }
    }
    printf("%lld\n", num.top());
}
