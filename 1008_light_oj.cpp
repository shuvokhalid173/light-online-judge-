#include <bits/stdc++.h>
using namespace std;
int main ()
{
	long long test;
	scanf ("%lld" , &test);
	long long i;
	for (i = 1; i <= test; i++){
		long long n;
		scanf ("%lld" , &n);
		long long row , col;
		row = col = 0;
		long long sq = sqrt (n);
		long long stay = 0;
		if (sq * sq == n){
			stay = sq;
		}
		else{
			stay = sq + 1;
		}
		long long test1 = (stay * stay) - n;
		if (test1 < stay){
			row = stay;
			col = test1 + 1;
		}
		else if (test1 >= stay){
			row = stay - ((test1 - stay) + 1);
			col = stay;
		}
		if (stay % 2 == 1){                             
			printf ("Case %lld: %lld %lld\n" , i , col , row);
		}
		else{
			printf ("Case %lld: %lld %lld\n" , i , row , col);
		}
	}
}
