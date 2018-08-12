#include<stdio.h>
#include<string.h>
#define mod 1000000007
long long n;
long long ini[10][10]={	{0,0,0,0,1,0},
						{0,0,0,1,1,0},
						{0,0,0,0,1,1},
						{0,1,0,0,1,0},
						{1,1,1,1,1,0},
						{0,0,1,0,0,0}};
struct Mat
{
    long long mat[10][10];
    Mat()
    {
        memset(mat, 0, sizeof(mat));
    }
};
Mat operator * (const Mat &a, const Mat &b)
{
    Mat c;
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            for(int k = 0; k < 6; k++)
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % mod;
    return(c);
}
int main()
{
	while(scanf("%lld",&n)!=EOF)
	{
		Mat ans, temp;
		for(int i=0;i<6;i++) ans.mat[i][i]=1;
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				temp.mat[i][j]=ini[i][j];
		n--;
		while(n)
		{
			if(n & 1) ans = ans * temp;
			temp = temp * temp;
			n = n / 2;
		}
		long long answer=0;
		for(int i=0;i<5;i++)
			answer=(answer+ans.mat[i][4])%mod;
		printf("%lld\n",answer);
	}
	return 0;
}
