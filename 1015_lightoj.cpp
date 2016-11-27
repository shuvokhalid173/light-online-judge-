#include <stdio.h>
int main ()
{
	
	int t;
	scanf ("%d" , &t);
	int i;
	for (i = 1; i <= t; i++)
	{
		int n;
		scanf ("%d" , &n);
		int j , num;
		int sum = 0;
		for (j = 0; j < n; j++)
		{
			scanf ("%d" , &num);
			if (num >= 0)
			sum += num;
		}
		printf ("Case %d: %d\n" , i , sum);
	}
	
}
