#include <bits/stdc++.h>
using namespace std;
int main ()
{
	long long test;
	scanf ("%lld" , &test);
	long long t;
	for (t = 1; t <= test; t++){
		long long w;
		scanf ("%lld" , &w);
		if (w&1){
			printf ("Case %lld: Impossible\n" , t);
		}
		else{
			long long i;
			bool flag = false;
			long long x;
			for (i = 2; i <= (w / 2) + 1; i += 2){
				if (w % i == 0){
					x = w / i;
					if (x&1){
						flag = true;
						break;
					}
				}
			}
			if (!flag)
			printf ("Case %lld: Impossible\n" , t);
			else
			printf ("Case %lld: %lld %lld\n" , t , w / i , i);
		}
	}
}
