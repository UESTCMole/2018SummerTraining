#include<stdio.h>
#include<string.h>
#include<string>
char s[1000005];
bool vis[100005];
int cnt;
int pr[20] = {1000000007, 19260817, 998244353, 469762049, 167772161, 104857601, 23068673, 7340033,  5767169,786433,
10000019,12289, 7681,257,7681,257, 0, 0, 0, 0};
long long ksm(long long a, int b, int p) {
	long long res = 1;
	while (b) {
		if (b & 1) res = (a * res) % p;
		a = (a * a)  % p;
		b >>= 1;
	}
	return res % p;
}
int main() 
{
	/*for(int i=2;i<=100000;i++)
	{
		if(vis[i])continue;
		cnt++;
		pr[cnt]=i;
		//printf("%d ",i);
		for(int j=2;j*i<=100000;j++)
			vis[j*i]=1;
	}*/
	//printf("\n%d\n",cnt);
	scanf("%s",s);
	int len=strlen(s);
	bool sign=0;
	int js = 0;
	for(int i=15;i>=0;i--)
	{
		int p=pr[i];
		long long n=0;
		for(int i=0;i<len;i++)
		{
			n=(n*10+(long long)(s[i]-'0'))%p;
		}
		if(n==0) continue;
		js++;
		if (js == 15) break;
		if(ksm(n,(p-1)/2,p)!=1)
		{
			sign=1;
			break;
		}
	}
	if(sign) printf("No\n");
	else printf("Yes\n");
	return 0;
}
