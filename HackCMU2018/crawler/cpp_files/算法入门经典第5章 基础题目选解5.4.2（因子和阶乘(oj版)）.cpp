#include<stdio.h>
#include<string.h>
//素数判定
bool is_prime(int n)
{
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}
//素数表
int prime[100], count = 0;
int main()
{
	//n和各个素数的指数
	int n, p[100];

	//构造素数表
	for(int i = 2; i <= 100; i++)
		if(is_prime(i))
			prime[count++] = i;

	while(scanf("%d", &n), n)
	{
		memset(p, 0, sizeof(p));
		int maxp = 0;
		for(int i = 1; i <= n; i++)
		{
			//必须把i复制到变量m中，而不要在做除法时直接修改它
			int m = i;
			for(int j = 0; j < count; j++)
				while(m % prime[j] == 0)//反复除以prime[j]，并累加p[j]
				{
					m /= prime[j];
					p[j]++;
					if(j > maxp)
						maxp = j;//更新最大素因子下标
				}
		}
		printf("%3d! =", n);
		//只循环到最大下标
		int num = 0;
		for(int i = 0; i <= maxp; i++)
		{
			printf("%3d", p[i]);
			num++;
			if(num % 15 == 0 && num != maxp + 1)
				printf("\n      ");
		}
		printf("\n");
	}
	return 0;
}
